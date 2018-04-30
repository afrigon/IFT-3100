//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef POST_GAUSSIANBLURPASS_H_
#define POST_GAUSSIANBLURPASS_H_

#include "RenderPass.h"

class GaussianBlurPass: public RenderPass {
    ofShader shader;
    
public:
    typedef shared_ptr<GaussianBlurPass> Ptr;
    float radius = 10;
    ofVec2f direction = ofVec2f(1, 0);
    
    GaussianBlurPass();
    void render(ofFbo& readFbo, ofFbo& writeFbo);
};

#endif  // POST_GAUSSIANBLURPASS_H_

