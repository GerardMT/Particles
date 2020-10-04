#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

void Camera::compute_view_projection()
{
    glm::mat4 view = glm::lookAt(pos_, pos_ + front_, UP_);

    float ratio_ = static_cast<float>(width_) / static_cast<float>(height_);
    glm::mat4 projection = glm::perspective(fov_y_, ratio_, near_, far_);

    view_projection = projection * view;
}

void Camera::lookAt(glm::vec3 pos)
{
    front_ = glm::normalize(pos - pos_);

    yaw_ = acos(pos.z);
    pitch_ = atan(pos.y / pos.x);
}

void Camera::forward(float dt)
{
    pos_ += dt * speed_ * front_;
}

void Camera::backwards(float dt)
{
    pos_ -= dt * speed_ * front_;
}

void Camera::left(float dt)
{
    pos_ -= dt * speed_ * right_;
}

void Camera::right(float dt)
{
    pos_ += dt * speed_ * right_;
}

void Camera::rotate(int x, int y, float dt)
{
    yaw_ += x * dt * sensitivity_;
    pitch_ -= y * dt * sensitivity_;

    if (pitch_ > 89.0f) {
        pitch_ = 89.0f;
    }
    if (pitch_ < -89.0f) {
        pitch_ = -89.0f;
    }

    front_.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
    front_.y = sin(glm::radians(pitch_));
    front_.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));

    right_ = glm::normalize(glm::cross(front_, UP_));
}

void Camera::viewport() const
{
    glViewport(0, 0, width_, height_);
}
