#include <Veritas/Engine/Assets/ImageFile.h>

#include <OpenImageIO/imageio.h>

using namespace Veritas;
using namespace Engine;
using namespace Assets;

using std::string;

using namespace OIIO;

ImageFile::ImageFile(const string &path) {
    img = OIIO::ImageInput::open(path.c_str());
    OIIO::ImageSpec spec = ((OIIO::ImageInput*) img)->spec();
    width = spec.width;
    height = spec.height;
    channels = spec.nchannels;
}
ImageFile::~ImageFile() {
    delete (OIIO::ImageInput*) img;
}

uint32 ImageFile::getWidth() const { return width; }
uint32 ImageFile::getHeight() const { return height; }
uint8 ImageFile::getChannels() const { return channels; }

void ImageFile::read(float32 *data) const { ((OIIO::ImageInput*) img)->read_image(TypeDesc::FLOAT, data); }
void ImageFile::read(uint8* data) const { ((OIIO::ImageInput*) img)->read_image(TypeDesc::UINT8, data); } // not tested
