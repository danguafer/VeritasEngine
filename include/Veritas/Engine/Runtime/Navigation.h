#pragma once

#include <Veritas/Engine/Assets/Camera.h>
#include <Veritas/Windowing/Window.h>

namespace Veritas {
    namespace Engine {
        namespace Runtime {
            class Navigation {
                public:
                    Navigation(Assets::Camera& camera, Windowing::Window& input);

                    void run(float32 dt);
                private:
                    Assets::Camera& camera;
                    Math::vec3 velocity;
                    Math::vec2 rotation, rotationVelocity;
            };
        }
    }
}
