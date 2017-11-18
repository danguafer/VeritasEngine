#include <Veritas/Engine/Assets/Mesh.h>

using namespace Veritas;
using namespace Engine;
using namespace Assets;

using namespace GPU;
using namespace Textures;

const Buffer* Mesh::getVertices() const { return vertices; }
const Buffer* Mesh::getNormals() const { return normals; }
const Buffer* Mesh::getTexCoords() const { return texcoords; }
const Buffer* Mesh::getIndices() const { return indices; }

const Texture2D* Mesh::getDiffuse() const { return diffuse; }
const Texture2D* Mesh::getBump() const { return bump; }
