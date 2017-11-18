precision highp float;

layout(location = 0) uniform sampler2D tex;

in vec2 texcoord;
out vec4 color;

void main(void) {
    color = texture(tex, texcoord);
    color.x = 1.0 - color.x;
}
