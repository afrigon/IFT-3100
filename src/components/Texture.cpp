//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "Texture.h"

ofTexture& Components::Texture::getTexture() {
    return tex;
}

bool Components::Texture::loadTexture(std::string path) {
    if (ofLoadImage(tex, path)) {
        this->setWrappingMode(GL_REPEAT);
        try {
            //GenerateMipmap fails if the image in invalid (such as non-power of 2)
            tex.generateMipmap();
        } catch (const std::exception&) {}
        tex.setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
        return true;
    }
    return false;
}

void Components::Texture::bindTexture(int location) {
    tex.bind(location);
}

void Components::Texture::unbindTexture(int location) {
    tex.unbind(location);
}

void Components::Texture::setWrappingMode(GLint wrapMode) {
    tex.setTextureWrap(wrapMode, wrapMode);
}

void Components::Texture::setWrappingMode(GLint wrapModeHorizontal, GLint wrapModeVertical) {
    tex.setTextureWrap(wrapModeHorizontal, wrapModeVertical);
}