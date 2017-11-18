#include <Veritas/Engine/Runtime/Navigation.h>

using namespace Veritas;
using namespace Engine;
using namespace Runtime;
using namespace Assets;

using namespace Windowing;

using namespace Math;

Navigation::Navigation(Camera &camera, Window &input)
    : camera(camera)
    , velocity(0.0, 0.0, 0.0)
    , rotation(0.0, 0.0)
    , rotationVelocity(0.0)
{
    input.onKeyDown([&](Window::KEY key) {
        switch (key) {
            case Window::W: velocity.z =  1.0; break;
            case Window::S: velocity.z = -1.0; break;
            case Window::A: velocity.x = -1.0; break;
            case Window::D: velocity.x =  1.0; break;
            case Window::Q: velocity.y = -1.0; break;
            case Window::E: velocity.y =  1.0; break;
            case Window::LEFT: rotationVelocity.y = -1.0; break;
            case Window::RIGHT: rotationVelocity.y = 1.0; break;
            case Window::UP: rotationVelocity.x = -1.0; break;
            case Window::DOWN: rotationVelocity.x = 1.0; break;
        }
    });
    input.onKeyUp([&](Window::KEY key) {
        switch (key) {
            case Window::W: velocity.z = 0.0; break;
            case Window::S: velocity.z = 0.0; break;
            case Window::A: velocity.x = 0.0; break;
            case Window::D: velocity.x = 0.0; break;
            case Window::Q: velocity.y = 0.0; break;
            case Window::E: velocity.y = 0.0; break;
            case Window::LEFT: rotationVelocity.y = 0.0; break;
            case Window::RIGHT: rotationVelocity.y = 0.0; break;
            case Window::UP: rotationVelocity.x = 0.0; break;
            case Window::DOWN: rotationVelocity.x = 0.0; break;
        }
    });
}

vec3 operator*(const mat3& m, const vec3& v) {
    return vec3(v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0],
                v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1],
                v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2]);
}

void Navigation::run(float32 dt) {
    static const float32 EPS = 0.000001f;
    rotation += rotationVelocity * dt * 2.0;
    rotation.x = clamp(rotation.x, -PI / 2.0f + EPS, PI / 2.0f - EPS);
    camera.setDirection(mat3::yRotation(rotation.y) * mat3::xRotation(rotation.x) * vec3(0.0, 0.0, -1.0));

    vec3 direction = camera.getDirection() * velocity.z;
    vec3 up = camera.getUp() * velocity.y;
    vec3 side = normalize(cross(camera.getDirection(), camera.getUp())) * velocity.x;
    camera.setPosition(camera.getPosition() + 10.0 * (side + up + direction) * dt);
}
