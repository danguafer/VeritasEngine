#pragma once

#include <Veritas/Engine/Assets/Scene.h>
#include <Veritas/Engine/Assets/Camera.h>

#include <Veritas/GPU/Textures/Sampler.h>
#include <Veritas/GPU/Programs/Programs.h>

#include <Veritas/Windowing/Window.h>

#include <Veritas/Engine/Runtime/PostProcessing.h>

namespace Veritas {
        namespace Engine {
		namespace Runtime {
            class Renderer {
                public:
                    Renderer(GPU::Context& context);
                    ~Renderer();

                    GPU::Context& getContext();

                    void render(const Assets::Scene& theScene, Assets::Camera& withCamera);
                private:
                    GPU::Context& context;
                    GPU::Programs::FragmentProgram fp;
                    GPU::Programs::VertexProgram vp;

                    GPU::Textures::Sampler sampler;
                    GPU::Programs::ClearProgram cp;
                    GPU::Programs::RasterProgram rp;
			};
		}
	}
}
