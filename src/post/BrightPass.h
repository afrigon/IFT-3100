//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef POST_BRIGHTPASS_H_
#define POST_BRIGHTPASS_H_

#include "RenderPass.h"

class BrightPass: public RenderPass {
    ofShader shader;
    
public:
    typedef shared_ptr<BrightPass> Ptr;
    float threshold = 0.7;
    
    BrightPass();
    void render(ofFbo& readFbo, ofFbo& writeFbo);
};

#endif  // POST_BRIGHTPASS_H_

