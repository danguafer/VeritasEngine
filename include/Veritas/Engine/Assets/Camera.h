#pragma once

#include <Veritas/GPU/FrameBuffer.h>

namespace Veritas {
    namespace Engine {
        namespace Assets {
            class Camera {
                public:
                    Camera(float32 fieldOfView, GPU::FrameBuffer& framebuffer);

                    float32 getFieldOfView() const;

                    void setPosition(const Math::vec3& position);
                    const Math::vec3& getPosition() const;

                    void setDirection(const Math::vec3& direction);
                    const Math::vec3& getDirection() const;

                    const Math::vec3& getUp() const;

                    const Math::vec2& getResolution() const;
                    const Math::mat4& getProjection() const;
                    Math::mat4 getTransform() const;

                    GPU::FrameBuffer& getFrameBuffer();
                    const GPU::FrameBuffer& getFrameBuffer() const;
                private:
                    GPU::FrameBuffer& framebuffer;
                    Math::vec3 position, direction, up;
                    Math::mat4 projection;
            };
        }
    }
}
