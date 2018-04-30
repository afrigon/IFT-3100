//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef POST_BLOOMPASS_H_
#define POST_BLOOMPASS_H_

#include "RenderPass.h"
#include "BrightPass.h"
#include "GaussianBlurPass.h"

class BloomPass: public RenderPass {
    BrightPass brightPass;
    GaussianBlurPass gaussianBlurPass;
    ofShader shader;
    
 public:
    typedef shared_ptr<BloomPass> Ptr;
    
    BloomPass();
    void render(ofFbo& readFbo, ofFbo& writeFbo);
};

#endif  // POST_BLOOMPASS_H_

