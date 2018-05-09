#version 330

in vec3 viewSpacePosition;
in vec3 viewSpaceNormal;
in vec2 varyingTexcoord;

out vec4 fragmentColor;

uniform int flags = 0;

uniform sampler2D ambientMap;
uniform sampler2D diffuseMap;
uniform sampler2D specularMap;
uniform sampler2D normalMap;
uniform sampler2D reflectionMap;

struct PerLight {
    vec4 position;
    vec4 color;
	
    float constant;
    float linear;
    float quadratic;
};

#define MAX_LIGHT 16

uniform int ambCount = 0;
uniform int lightCount = 0;

uniform PerLight lights[MAX_LIGHT];

uniform vec3 colorAmbient = vec3(1.0);
uniform vec3 colorDiffuse = vec3(0.0);
uniform vec3 colorSpecular = vec3(0.0);
uniform float brightness = 20.0;
uniform vec3 camPos = vec3(0.0);



vec3 calcLight(PerLight light, float attenuation, vec3 diff,
            vec3 spec, vec3 N, vec3 V, vec3 L) {
    float reflectionDiffuse = max(dot(N, L), 0.0);
    
    float reflectionSpecular = 0.0;
    if ((flags & 6) != 0 && reflectionDiffuse > 0.0) {
        if ((flags & 2) != 0) { // phong
            vec3 R = reflect(-L, N);
            reflectionSpecular = pow(max(dot(V, R), 0.0), brightness);
        } else if ((flags & 4) != 0) { // blinn-phong
            vec3 H = normalize(V + L);
            reflectionSpecular = pow(max(dot(N, H), 0.0), brightness);
        }
    }
    return (light.color.xyz * attenuation *
            (reflectionDiffuse * diff + reflectionSpecular * spec));
}



void main() {
    if(lightCount == 0) {
        fragmentColor = vec4(colorAmbient, 1.0);
        return;
    }
    vec3 N = normalize(viewSpaceNormal);
    vec3 Nm = N;
    vec3 V = normalize(-viewSpacePosition);
    fragmentColor = vec4(0.0);
    
    // ambient
    vec4 ambientColor = vec4(colorAmbient, 1.0);
    if((flags & 8) != 0)
        ambientColor = texture(ambientMap, varyingTexcoord) * vec4(colorAmbient, 1.0);
    if(ambCount == 0) {
        fragmentColor += ambientColor;
    }
    
    // diffuse
    vec4 diffuseColor = ((flags & 16) != 0)
    ? texture(diffuseMap, varyingTexcoord)
    : vec4(colorDiffuse, 1.0);
    
    // specular
    vec4 specularColor = vec4(colorSpecular, 1.0);
    if ((flags & 6) != 0) {
        if ((flags & 64) != 0) Nm = normalize(texture(normalMap, varyingTexcoord).rgb * 2.0 - 1.0);
        if ((flags & 32) != 0) specularColor *= texture(specularMap, varyingTexcoord).x;
    }
    
    for(int i = 0; i < lightCount && i < MAX_LIGHT; i++) {
        //Ambient
        if(lights[i].position.w == 0)
            fragmentColor += lights[i].color * ambientColor;
        
        //Directional Lights
        else if(lights[i].position.w == 1)
            fragmentColor += vec4(calcLight(lights[i], 1.0, diffuseColor.xyz, specularColor.xyz,
                            Nm, V, normalize(lights[i].position.xyz)), lights[i].color.w);
        
        //Point Lights
        else if(lights[i].position.w == 2) {
            vec3 L = normalize(lights[i].position.xyz - viewSpacePosition);
            
            float distance = length(lights[i].position.xyz - viewSpacePosition);
            float attenuation = 1.0 / (lights[i].constant + lights[i].linear *
                        distance + lights[i].quadratic * (distance * distance));
            
            fragmentColor += vec4(calcLight(lights[i], attenuation, diffuseColor.xyz,
                                specularColor.xyz, Nm, V, L), lights[i].color.w);
        }
    }
}
