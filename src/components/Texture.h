//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_TEXTURE_H_
#define COMPONENTS_TEXTURE_H_

#include "components/AbstractComponent.h"
#include "ofMain.h"

namespace Components {
    class Texture : public AbstractComponent {
        ofTexture tex;

     public:
        ofTexture& getTexture();
        bool loadTexture(std::string path);
        void bindTexture(int location);
        void unbindTexture(int location);
        void setWrappingMode(GLint wrapMode);
        void setWrappingMode(GLint wrapModeHorizontal, GLint wrapModeVertical);
    };
}  // namespace Components

#endif  // COMPONENTS_TEXTURE_H_
