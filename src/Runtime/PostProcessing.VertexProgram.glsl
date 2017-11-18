layout(location = 0) in vec2 vertices;
layout(location = 1) in vec2 texcoords;

out vec2 texcoord;

void main(void) {
    gl_Position = vec4(vertices, 0.0, 1.0);
    texcoord = texcoords;
}
