precision highp float;

layout(location = 0) uniform sampler2D diffuse;
layout(location = 1) uniform sampler2D bump;
layout(location = 2) uniform vec3 cameraPosition;
layout(location = 3) uniform mat3 rotation;

in vec3 normal;
in vec3 uv;

in vec3 position;

out vec4 color;
void main() {
    vec3 view = normalize(position - cameraPosition);
    color = texture(diffuse, uv.xy);
}
