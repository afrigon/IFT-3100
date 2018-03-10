#pragma once

#include "components/RenderableComponent.h"

namespace Components
{
    class Cubemap : public RenderableComponent {
        float distance;
        vector<ofTexture> textures;
        vector<ofMesh> meshes;

        void generateMeshes();

        public:
        Cubemap();
        ~Cubemap();

        void render(bool useTexture);
        float getDistance();
        void loadMap(std::string path);
        void loadMap(std::string path[6]);
        void loadMap(std::string image1, std::string image2, std::string image3, std::string image4, std::string image5, std::string image6);
        void loadMap(ofImage image);
        void loadMap(ofImage images[6]);
        void loadMap(ofImage image1, ofImage image2, ofImage image3, ofImage image4, ofImage image5, ofImage image6);
        void setDistance(float distance);
    };
}
