#pragma once

#include <Veritas/GPU/GPU.h>

namespace Veritas {
    namespace Engine {
        namespace Assets {
            class Mesh {
                public:
                    const GPU::Buffer* getVertices() const;
                    const GPU::Buffer* getNormals() const;
                    const GPU::Buffer* getTexCoords() const;

                    const GPU::Buffer* getIndices() const;

                    const GPU::Textures::Texture2D* getDiffuse() const;
                    const GPU::Textures::Texture2D* getBump() const;
                private:
                    friend class Scene;
                    GPU::Buffer *vertices, *normals, *texcoords, *indices;
                    GPU::Textures::Texture2D *diffuse, *bump;
            };
        }
    }
}
