#version 330

smooth in vec3 eye_normal;
smooth in vec3 eye_vertex;

vec3 color = vec3(0.6);

out vec4 frag_color;

void main (void) {
 vec3 L = vec3(0, 0, 1);

 vec3 N = normalize(eye_normal);
 vec3 E = normalize(-eye_vertex);
 vec3 R = normalize(-reflect(L, N));

 vec3 Iamb = color;

 vec3 Idiff = color * vec3(max(dot(N, L), 0.0));

 vec3 Ispec = color * pow(max(dot(R, E), 0.0), 2.2);
 Ispec = clamp(Ispec, 0.0, 1.0);

 frag_color = vec4(Iamb * 0.4 + Idiff * 0.6 + Ispec * 0.2, 0.5);
}
