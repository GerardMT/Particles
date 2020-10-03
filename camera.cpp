#include "camera.h"

#include <glm/gtc/matrix_transform.hpp>

void Camera::compute_view_projection() {
    glm::mat4 view = glm::lookAt(pos_, pos_ + front_, UP_);

    float ratio_ = static_cast<float>(width_) / static_cast<float>(height_);
    glm::mat4 projection = glm::perspective(fov_y_, ratio_, near_, far_);

    view_projection = projection * view;
}

void Camera::forward(float d_time) {
    pos_ += d_time * speed_ * front_;
}

void Camera::backwards(float d_time) {
    pos_ -= d_time * speed_ * front_;
}

void Camera::left(float d_time) {
    pos_ -= d_time * speed_ * right_;
}

void Camera::right(float d_time) {
    pos_ += d_time * speed_ * right_;
}

void Camera::rotate(int x, int y, float d_time) {
    yaw_ += x * d_time * sensitivity_;
    pitch_ -= y * d_time * sensitivity_;

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

void Camera::viewport() const {
    glViewport(0, 0, width_, height_);
}
