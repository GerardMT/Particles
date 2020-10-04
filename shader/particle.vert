#version 330

layout (location = 0) in vec3 vert;
layout (location = 1) in vec3 trans;
layout (location = 2) in vec3 camera_dir;

uniform mat4 view_projection;

smooth out vec2 quad_coord;

void main()
{
    mat4 model;
    model[0] = vec4(normalize(cross(camera_dir, trans)), 0.0);
    model[1] = vec4(0.0, 1.0, 0.0, 0.0);
    model[2] = vec4(camera_dir, 0);
    model[3] = vec4(trans, 1.0);

    quad_coord = vert.xy;
    gl_Position = view_projection * model * vec4(vert, 1.0);
}
