//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_CUBEMAP_H_
#define COMPONENTS_CUBEMAP_H_

#include <string>
using std::string;

#include "components/RenderableComponent.h"

namespace Components {
    class Cubemap : public RenderableComponent {
        string path = "";
        vector<ofTexture> textures;
        vector<ofMesh> meshes;

        void generateMeshes();
        
     public:
        float distance = 1000;
        
        Cubemap();
        Cubemap* createInstance() override { return new Cubemap(); }
        void render(bool useTexture) override;
        void loadMap(string path);
        string getPath();
//        void loadMap(std::string path[6]);
//        void loadMap(std::string image1, std::string image2, std::string image3, std::string image4, std::string image5, std::string image6);
//        void loadMap(ofImage images[6]);
//        void loadMap(ofImage image1, ofImage image2, ofImage image3, ofImage image4, ofImage image5, ofImage image6);
    };
}  // namespace Components

#endif  // COMPONENTS_CUBEMAP_H_
