#version 330 core
layout (location = 0) in vec3 vert;
layout (location = 1) in vec3 trans;

uniform mat4 view_projection;

out vec2 quad_coord;

void main()
{
    quad_coord = vert.xy;
    gl_Position = projection * view * vec4(vert + trans, 1.0);
}
