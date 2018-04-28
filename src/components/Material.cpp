//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "components/Material.h"
#include "views/MaterialView.h"

void Components::Map::loadImage(string path) {
    // may have to change when the loads fail (hoping image will be set to null)
    if((isLoaded = ofLoadImage(this->image, path))) {
        this->path = path;
    } else {
        this->path = "Could not load this image";
    }
}

ofTexture Components::Map::getMap() {
    return this->image;
}

string Components::Map::getPath() {
    return this->path;
}

Components::Material::Material() {
    this->name = "Material";
}

int Components::Material::getFlags() {
    this->flags &= 0b00000111;
    if (this->ambient.isLoaded) this->flags |= 8;
    if (this->diffuse.isLoaded) this->flags |= 16;
    if (this->specular.isLoaded) this->flags |= 32;
    if (this->normal.isLoaded) this->flags |= 64;
    if (this->reflection.isLoaded) this->flags |= 128;
    return this->flags;
}

void Components::Material::illuminationTypeForward() {
    int flags = (this->flags << 1) & 0b111;
    if (flags == 0) flags = 1;
    this->flags = flags;
}

void Components::Material::illuminationTypeBackward() {
    int flags = (this->flags >> 1) & 0b111;
    if (flags == 0) flags = 4;
    this->flags = flags;
}

void Components::Material::setupShader(ofShader shader) {
    if (this->ambient.isLoaded) shader.setUniformTexture("ambientMap", this->ambient.getMap(), 1);
    if (this->diffuse.isLoaded) shader.setUniformTexture("diffuseMap", this->diffuse.getMap(), 2);
    if (this->specular.isLoaded) shader.setUniformTexture("specularMap", this->specular.getMap(), 3);
    if (this->normal.isLoaded) shader.setUniformTexture("normalMap", this->normal.getMap(), 4);
    
    int color = this->ambientColor.getHex();
    shader.setUniform3f("colorAmbient",  ((color >> 16) & 0xFF) / 255.0, ((color >> 8) & 0xFF) / 255.0, (color & 0xFF) / 255.0);
    
    color = this->diffuseColor.getHex();
    shader.setUniform3f("colorDiffuse",  ((color >> 16) & 0xFF) / 255.0, ((color >> 8) & 0xFF) / 255.0, (color & 0xFF) / 255.0);
    
    color = this->specularColor.getHex();
    shader.setUniform3f("colorSpecular", ((color >> 16) & 0xFF) / 255.0, ((color >> 8) & 0xFF) / 255.0, (color & 0xFF) / 255.0);
    
    shader.setUniform1f("brightness", this->brightness);
    shader.setUniform1i("flags", this->getFlags());
}

UIKit::UIView* Components::Material::getUIView() {
    return new Components::Views::Material(this);
}

int Components::Material::getUIViewHeight() {
    return 20 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30 + 30;
}
