precision highp float;

layout(location = 0) uniform sampler2D tex;
layout(location = 1) uniform float time;

in vec2 texcoord;
out vec4 color;

void main(void) {
    vec2 uv = texcoord;
    uv += vec2(cos(uv.y * 10.0 - time), sin(uv.x * 10.0 - time)) * 0.1;
    color = texture(tex, uv);
}
