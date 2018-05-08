#version 330

in vec3 viewSpacePosition;
in vec3 viewSpaceNormal;
in vec2 varyingTexcoord;
in vec3 varyingReflectionDirection;

out vec4 fragmentColor;

uniform int flags;

uniform sampler2D ambientMap;
uniform sampler2D diffuseMap;
uniform sampler2D specularMap;
uniform sampler2D normalMap;
uniform sampler2D reflectionMap;

uniform vec3 colorAmbient;
uniform vec3 colorDiffuse;
uniform vec3 colorSpecular;
uniform float brightness;

uniform vec3 lightPosition = vec3(0.0, 0.0, 0.0);

void main() {
    vec3 N = normalize(viewSpaceNormal);
    vec3 L = normalize(lightPosition - viewSpacePosition);
    float reflectionDiffuse = max(dot(N, L), 0.0);
    
    // ambient
    fragmentColor = ((flags & 8) != 0)
    ? texture(ambientMap, varyingTexcoord)
    : vec4(colorAmbient, 1.0);
    
    // diffuse
    fragmentColor += ((flags & 16) != 0)
    ? texture(diffuseMap, varyingTexcoord) * reflectionDiffuse
    : vec4(colorDiffuse * reflectionDiffuse, 1.0);
    
    // specular
    if ((flags & 6) != 0) { // skip for lambert shader
        // normal map (needs to be fixed with tangent space tingy that I don't yet understand)
        if ((flags & 64) != 0) N = normalize(texture(normalMap, varyingTexcoord).rgb * 2.0 - 1.0);
        
        float reflectionSpecular = 0.0;
        if (reflectionDiffuse > 0.0) {
            vec3 V = normalize(-viewSpacePosition);
            
            if ((flags & 2) != 0) { // phong
                vec3 R = reflect(-L, N);
                reflectionSpecular = pow(max(dot(V, R), 0.0), brightness);
            } else if ((flags & 4) != 0) { // blinn-phong
                vec3 H = normalize(V + L);
                reflectionSpecular = pow(max(dot(N, H), 0.0), brightness);
            }
        }
        
        // specular map alteration
        if ((flags & 32) != 0) reflectionSpecular *= texture(specularMap, varyingTexcoord).x;
        fragmentColor += vec4(colorSpecular * reflectionSpecular, 1.0);
    }
}
