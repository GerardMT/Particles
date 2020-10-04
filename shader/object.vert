#version 330

layout (location = 0) in vec3 vert;
layout (location = 1) in vec3 norm;

smooth out vec3 eye_normal;
smooth out vec3 eye_vertex;

uniform mat4 model;
uniform mat4 view_projection;

void main()
{
    mat4 mvp = view_projection * model;

    gl_Position = mvp * vec4(vert, 1.0);

    eye_normal = gl_Position;
    eye_vertex = mvp * vec4(norm, 0.0);
}
