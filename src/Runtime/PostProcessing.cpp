#include <Veritas/Engine/Runtime/PostProcessing.h>
#include <Veritas/GPU/VertexBinding.h>
#include <Veritas/GPU/Textures/SamplerBinding.h>

using namespace Veritas;
using namespace Engine;
using namespace Assets;
using namespace Runtime;

using namespace GPU;
using namespace Programs;
using namespace Textures;

static vec2 verticesData[] = {
    vec2(-1.0,  1.0), vec2(1.0,  1.0),
    vec2(-1.0, -1.0), vec2(1.0, -1.0)
};
static vec2 texcoordsData[] = {
    vec2(0.0, 1.0), vec2(1.0, 1.0),
    vec2(0.0, 0.0), vec2(1.0, 0.0)
};
static uint32 indicesData[] = {
    0, 1, 2,
    2, 1, 3
};

PostProcessing::PostProcessing(const SourceFile &source)
    : vp(SourceFile("./assets/PostProcessing.VertexProgram.glsl").getSource())
    , fp(source.getSource())
    , rp(vp, fp)
    , vertices(sizeof(verticesData), verticesData)
    , texcoords(sizeof(texcoordsData), texcoordsData)
    , indices(sizeof(indicesData), indicesData)
    , fixedBindings({ VertexBinding(0, vertices, 2), VertexBinding(1, texcoords, 2) })
    , sampler(Sampler::LINEAR, Sampler::LINEAR, Sampler::CLAMP_TO_EDGE, Sampler::CLAMP_TO_EDGE)
{}

FragmentProgram& PostProcessing::getFragmentProgram() { return fp; }

void PostProcessing::render(GPU::SwapChain& swapChain, const Program::Bindings& bindings) {
    Program::Bindings mergedBindings = fixedBindings;
    for (auto binding : bindings) mergedBindings.push_back(binding);
    mergedBindings.push_back(SamplerBinding(0, sampler, fp, *swapChain.get(0).getColorBuffer(), 0));
    rp.triangles(swapChain.get(1), 2, false, false, IndexBinding(indices, IndexBinding::UINT32), mergedBindings);
    swapChain.advance();
}
