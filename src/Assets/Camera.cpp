#include <Veritas/Engine/Assets/Camera.h>

using namespace Veritas;
using namespace Engine;
using namespace Assets;

using namespace Math;
using namespace GPU;

Camera::Camera(float32 fieldOfView, FrameBuffer& framebuffer)
    : projection(mat4::perspective(fieldOfView, framebuffer.getWidth() / float32(framebuffer.getHeight()), 1.0f, 1000.0f))
    , framebuffer(framebuffer)
    , position(0.0)
    , direction(0.0, 0.0, -1.0)
    , up(0.0, 1.0, 0.0)
{}

FrameBuffer& Camera::getFrameBuffer() { return framebuffer; }
const FrameBuffer& Camera::getFrameBuffer() const { return framebuffer; }

const mat4& Camera::getProjection() const { return projection; }

void Camera::setPosition(const vec3 &position) { this->position = position; }
const vec3& Camera::getPosition() const { return position; }

void Camera::setDirection(const vec3 &direction) { this->direction = normalize(direction); }
const vec3& Camera::getDirection() const { return direction; }

const vec3& Camera::getUp() const { return up; }

mat4 Camera::getTransform() const { return mat4::lookAt(direction, up) * mat4::translation(-position); }
