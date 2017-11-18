#pragma once

#include <Veritas/GPU/Programs/Programs.h>
#include <Veritas/GPU/SwapChain.h>
#include <Veritas/Engine/Assets/SourceFile.h>

namespace Veritas {
    namespace Engine {
        namespace Runtime {
            class PostProcessing {
                public:
                    PostProcessing(const Assets::SourceFile& source);

                    GPU::Programs::FragmentProgram& getFragmentProgram();

                    void render(GPU::SwapChain& swapChain, const GPU::Programs::Program::Bindings& fixedBindings = {});
                private:
                    GPU::Programs::FragmentProgram fp;
                    GPU::Programs::VertexProgram vp;
                    GPU::Programs::RasterProgram rp;
                    GPU::Buffer vertices, texcoords, indices;
                    GPU::Textures::Sampler sampler;
                    GPU::Programs::Program::Bindings fixedBindings;
            };
        }
    }
}
