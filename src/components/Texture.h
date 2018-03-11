#pragma once
#include "components/AbstractComponent.h"
#include "ofMain.h"

namespace Components
{
    class Texture : public AbstractComponent {
        ofTexture tex;
        bool isLoaded = false;

        public:
        Texture();
        ~Texture();

        ofTexture& getTexture();
        bool loadTexture(std::string path);
        void bindTexture(int location);
        void unbindTexture(int location);
        void setWrappingMode(GLint wrapMode);
        void setWrappingMode(GLint wrapModeHorizontal, GLint wrapModeVertical);
    };
}
