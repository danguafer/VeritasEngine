#pragma once

#include <Veritas/Engine/Assets/Mesh.h>

namespace Veritas {
    namespace Engine {
        namespace Assets {
            class Scene {
                public:
                    typedef std::vector<Mesh> Meshes;
                    Scene();
                    Scene(const std::string& path);

                    void add(const Mesh& mesh);

                    const Meshes& getMeshes() const;
                private:
                    Meshes meshes;
            };
        }
    }
}
