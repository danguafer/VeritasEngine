#include <Veritas/Engine/Assets/Scene.h>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <Veritas/Engine/Assets/ImageFile.h>

using namespace Assimp;

using namespace Veritas;
using namespace Engine;
using namespace Assets;

using namespace GPU;
using namespace Textures;

using std::string;

Scene::Scene() {}
Scene::Scene(const std::__cxx11::string &path) {
    Importer importer;
    const aiScene* scene = importer.ReadFile(path.c_str(), aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_JoinIdenticalVertices | aiProcess_FlipUVs);

    assert(scene);

    std::string dirpath = path;
    dirpath = dirpath.substr(0, dirpath.find_last_of('/') + 1);

    for (uint32 m = 0; m < scene->mNumMeshes; m++) {
        std::vector<uint32> indexVector;
        for (uint32 f = 0; f < scene->mMeshes[m]->mNumFaces; f++) {
            indexVector.push_back(scene->mMeshes[m]->mFaces[f].mIndices[0]);
            indexVector.push_back(scene->mMeshes[m]->mFaces[f].mIndices[1]);
            indexVector.push_back(scene->mMeshes[m]->mFaces[f].mIndices[2]);
        }

        uint32 vertices = scene->mMeshes[m]->mNumVertices * sizeof(float32) * 3;

        Mesh mesh;
        mesh.vertices = new Buffer(vertices, scene->mMeshes[m]->mVertices);
        mesh.normals = new Buffer(vertices, scene->mMeshes[m]->mNormals);
        mesh.texcoords = new Buffer(vertices, scene->mMeshes[m]->mTextureCoords[0]);
        mesh.indices = new Buffer(indexVector.size() * sizeof(uint32), indexVector.data());

        // channels generalization
        aiString path;
        scene->mMaterials[scene->mMeshes[m]->mMaterialIndex]->GetTexture(aiTextureType_DIFFUSE, 0, &path);
        if (path.length) {
            string fullpath = string(dirpath.c_str()) + path.C_Str();
            ImageFile image(fullpath.c_str());

            float32 *data = new float32[image.getWidth() * image.getHeight() * image.getChannels()];
            image.read(data);

            mesh.diffuse = new Texture2D(image.getWidth(), image.getHeight(), image.getChannels() == 3 ? Texture::RGB : Texture::RGBA, Texture::FLOAT32, data);
            delete[] data;
        } else mesh.diffuse = 0;

        mesh.bump = 0;

        meshes.push_back(mesh);
    }
}

const Scene::Meshes& Scene::getMeshes() const { return meshes; }
