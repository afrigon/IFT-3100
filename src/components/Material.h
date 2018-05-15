//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef COMPONENTS_MATERIAL_H_
#define COMPONENTS_MATERIAL_H_

#include <string>
using std::string;

#include "components/AbstractComponent.h"
#include "Vector3.h"
#include "ofImage.h"
#include "ofShader.h"
#include "ofColor.h"

namespace Components {
    class Map {
        string path;
        ofTexture image;
        
     public:
        bool isLoaded = false;
        void loadImage(string path);
        ofTexture getMap();
        string getPath();
    };
    
    class Material : public AbstractComponent {
        int flags = 4;
        /*  lambert     (1)
            phong       (2)
            blinn-phong (4)
            ambient     (8)
            diffuse     (16)
            spec        (32)
            normal      (64)
            reflection  (128)
         */
    public:
        ofColor ambientColor = ofColor();
        ofColor diffuseColor = ofColor();
        ofColor specularColor = ofColor();
        
        Map ambient;
        Map diffuse;
        Map specular;
        Map normal;
        Map reflection;
        
        double brightness = 20;
        
        Material();
        Material* createInstance() override { return new Material(); }
        
        void setupShader(ofShader shader);
        void illuminationTypeForward();
        void illuminationTypeBackward();
        int getFlags();
        
        UIKit::UIView* getUIView() override;
        int getUIViewHeight() override;
    };
}  // namespace Components

#endif  // COMPONENTS_MATERIAL_H_

