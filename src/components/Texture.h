//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_TEXTURE_H_
#define COMPONENTS_TEXTURE_H_

#include <exception>
#include <string>
using std::string;

#include "components/AbstractComponent.h"
#include "ofMain.h"

namespace Components {
    class Texture : public AbstractComponent {
        string path = "";
        ofTexture tex;
        bool isLoaded = false;

     public:
        Texture();
        Texture* createInstance() override { return new Texture(); }
        //ofTexture& getTexture();
        bool loadTexture(string path);
        string getPath();
        
        // GameObject functions
        void bindTexture(int location);
        void unbindTexture(int location);
        
        // GL_CLAMP_TO_EDGE | GL_MIRRORED_REPEAT | GL_REPEAT
        void setWrappingMode(GLint wrapModeHorizontal, GLint wrapModeVertical);
    };
}  // namespace Components

#endif  // COMPONENTS_TEXTURE_H_
