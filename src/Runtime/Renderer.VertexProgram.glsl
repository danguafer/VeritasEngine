layout(location = 0) in vec3 positions;
layout(location = 1) in vec3 normals;
layout(location = 2) in vec3 uvs;

layout(location = 0) uniform mat4 projection;
layout(location = 1) uniform mat4 transform;

out vec3 position;
out vec3 normal;
out vec3 uv;

void main() {
    gl_Position = vec4(positions, 1.0);
    gl_Position = transform * gl_Position;
    position = gl_Position.xyz;
    gl_Position = projection * gl_Position;
    uv = uvs;
    normal = normals;
}
