#include <Veritas/Engine/Assets/SourceFile.h>

#include <Veritas/Definitions/Definitions.h>

#include <cstdio>
#include <cassert>

using namespace Veritas;
using namespace Engine;
using namespace Assets;

using std::string;

#include <iostream>

SourceFile::SourceFile(const string &path) {
    FILE *file = fopen(path.c_str(), "rb");
    assert(file);

    uint8 c;
    while (!feof(file) && fread(&c, 1, 1, file) > 0)
        source += c;

    fclose(file);
}

const string& SourceFile::getSource() const { return source; }
