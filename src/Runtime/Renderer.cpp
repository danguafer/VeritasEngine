#include <Veritas/Engine/Runtime/Renderer.h>

#include <Veritas/Engine/Assets/SourceFile.h>

using namespace Veritas;
using namespace Engine;
using namespace Runtime;
using namespace Assets;

using namespace GPU;
using namespace Programs;
using namespace Textures;

using namespace Windowing;

using namespace Math;

#include <GLES3/gl32.h>

Renderer::Renderer(Context& context)
    : context(context)
    , vp(SourceFile("./assets/Renderer.VertexProgram.glsl").getSource())
    , fp(SourceFile("./assets/Renderer.FragmentProgram.glsl").getSource())
    , rp(vp, fp)
{}
Renderer::~Renderer() {}

void Renderer::render(const Assets::Scene &scene, Assets::Camera &camera) {
    cp.clear(camera.getFrameBuffer(), vec4(vec3(0.0f), 1.0f), 1.0f);
    for (auto& mesh : scene.getMeshes()) {
        RasterProgram::Bindings bindings = {
            VertexBinding(0, *mesh.getVertices(), 3),
            VertexBinding(1, *mesh.getNormals(), 3),
            VertexBinding(2, *mesh.getTexCoords(), 3),
            UniformBinding(0, vp, camera.getProjection()),
            UniformBinding(1, vp, camera.getTransform()),
            UniformBinding(2, fp, camera.getPosition()),
            UniformBinding(3, fp, mat3::lookAt(camera.getDirection(), camera.getUp()))
        };
        if (mesh.getDiffuse()) bindings.push_back(SamplerBinding(0, sampler, fp, *mesh.getDiffuse(), 0));
        if (mesh.getBump()) bindings.push_back(SamplerBinding(1, sampler, fp, *mesh.getBump(), 1));
        rp.triangles(camera.getFrameBuffer(), mesh.getIndices()->getSize() / sizeof(uint32) / 3, true, true, IndexBinding(*mesh.getIndices(), IndexBinding::UINT32), bindings);
    }
}

Context& Renderer::getContext() { return context; }
