#version 330

in vec4 position;
in vec4 normal;
in vec2 texcoord;

out vec3 vPos;
out vec3 vNorm;
out vec3 viewSpacePosition;
out vec3 viewSpaceNormal;
out vec2 vTex;

uniform mat4x4 modelViewMatrix;
uniform mat4x4 projectionMatrix;

void main() {
    mat4x4 normalMatrix = transpose(inverse(modelViewMatrix));
    viewSpaceNormal = vec3(normalMatrix * normal);
    vNorm = normal.xyz;
    viewSpacePosition = vec3(modelViewMatrix * position);
    gl_Position = projectionMatrix * modelViewMatrix * position;
    vPos = -position.xyz;
    vTex = texcoord;
}
