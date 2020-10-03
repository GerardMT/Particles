#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class Camera
{
public:
    glm::vec3 UP_ = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::mat4 view_projection;

    glm::vec3 pos_ = glm::vec3(0.0, 0.0, 0.0);

    glm::vec3 front_ = glm::vec3(1.0, 0.0, 0.0);
    glm::vec3 right_;

    float yaw_ = 0.0;
    float pitch_ = 0.0;

    GLuint width_;
    GLuint height_;
    GLfloat ratio_;
    GLfloat fov_y_;
    GLfloat near_ = 0.1f;
    GLfloat far_ = 100.0f;

    float speed_ = 5.0;
    float sensitivity_ = 10.0;

    void position(glm::vec3 p);

    void forward(float d_time);

    void backwards(float d_time);

    void left(float d_time);

    void right(float d_time);

    void rotate(int x, int y, float d_time);

    void compute_view_projection();

    void viewport() const;
};

#endif // CAMERA_H
