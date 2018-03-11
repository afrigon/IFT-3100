#include "Texture.h"

Components::Texture::Texture() {}

Components::Texture::~Texture() {}

ofTexture& Components::Texture::getTexture() {
    return tex;
}

bool Components::Texture::loadTexture(std::string path) {
    if(isLoaded = ofLoadImage(tex, path)) {
        this->setWrappingMode(GL_REPEAT);
        try {
            //GenerateMipmap fails if the image in invalid (such as non-power of 2)
            tex.generateMipmap();
        } catch(const std::exception&) {}
        tex.setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
    }
    return isLoaded;
}

void Components::Texture::bindTexture(int location) {
    if(isLoaded) tex.bind(location);
}

void Components::Texture::unbindTexture(int location) {
    if(isLoaded) tex.unbind(location);
}

void Components::Texture::setWrappingMode(GLint wrapMode) {
    tex.setTextureWrap(wrapMode, wrapMode);
}

void Components::Texture::setWrappingMode(GLint wrapModeHorizontal, GLint wrapModeVertical) {
    tex.setTextureWrap(wrapModeHorizontal, wrapModeVertical);
}
