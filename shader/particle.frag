#version 330 core

int vec3 quad_coord;

out vec4 frag_color;

const float blur = 0.005;
const float radius = 0.5;

void main()
{
    float col = smoothstep(radius, radius - blur, abs(length(quad_coord - vec2(0.5, 0.5))));

    fragColor = vec4(col);
}
