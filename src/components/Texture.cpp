//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Texture.h"
#include "views/TextureView.h"

Components::Texture::Texture() {
    this->name = "Material";
}

//ofTexture& Components::Texture::getTexture() {
//    return tex;
//}

bool Components::Texture::loadTexture(string path) {
    this->path = path;
    if((isLoaded = ofLoadImage(tex, path))) {
        this->setWrappingMode(GL_REPEAT, GL_REPEAT);
        try {
            //GenerateMipmap fails if the image in invalid (such as non-power of 2)
            tex.generateMipmap();
        } catch (const std::exception&) {}
        tex.setTextureMinMagFilter(GL_LINEAR, GL_LINEAR);
    }
    return isLoaded;
}

string Components::Texture::getPath() {
    return this->path;
}

void Components::Texture::bindTexture(int location) {
    if(isLoaded) tex.bind(location);
}

void Components::Texture::unbindTexture(int location) {
    if(isLoaded) tex.unbind(location);
}

void Components::Texture::setWrappingMode(GLint wrapModeHorizontal, GLint wrapModeVertical) {
    tex.setTextureWrap(wrapModeHorizontal, wrapModeVertical);
}

UIKit::UIView* Components::Texture::getUIView() {
    return new Components::Views::Texture(this);
}

int Components::Texture::getUIViewHeight() {
    return 20 + 30;
}
