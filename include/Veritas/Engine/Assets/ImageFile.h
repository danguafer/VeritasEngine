#pragma once

#include <Veritas/Definitions/Definitions.h>
#include <string>

namespace Veritas {
    namespace Engine {
        namespace Assets {
            class ImageFile {
                public:
                    ImageFile(const std::string& path);
                    ~ImageFile();

                    bool isOpen() const;

                    uint32 getWidth() const;
                    uint32 getHeight() const;
                    uint8 getChannels() const;

                    void read(float32* data) const;
                    void read(uint8* data) const;
                private:
                    void* img;
                    uint32 width, height;
                    uint8 channels;
            };
        }
    }
}
