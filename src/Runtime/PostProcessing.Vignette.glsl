precision highp float;

layout(location = 0) uniform sampler2D tex;
layout(location = 1) uniform float p0;
layout(location = 2) uniform float p1;

in vec2 texcoord;
out vec4 color;

float vignette(vec2 coord) {
    return smoothstep(p1, p0, length(coord));
}

void main(void) {
    vec2 coord = texcoord * 2.0 - 1.0;
    color = texture(tex, texcoord) * vec4(vec3(vignette(coord)), 1.0);
}
