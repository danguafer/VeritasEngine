precision highp float;

layout(location = 0) uniform sampler2D tex;

in vec2 texcoord;
out vec4 color;

void main(void) {
    vec2 uv = texcoord;
    color.x = texture(tex, uv + vec2(0.01, 0.0)).x;
    color.y = texture(tex, uv + vec2(-0.01, 0.0)).y;
    color.z = texture(tex, uv).z;
}
