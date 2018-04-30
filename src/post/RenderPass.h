//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef POST_RENDERPASS_H_
#define POST_RENDERPASS_H_

#include <string>
using std::string;

#include "ofMain.h"
#include "UIWindow.h"

#define STRINGIFY(A) #A

struct RenderPass {
    typedef shared_ptr<RenderPass> Ptr;
    virtual void render(ofFbo& readFbo, ofFbo& writeFbo) {}
    
 protected:
    void texturedQuad(float, float);
};

#endif  // POST_RENDERPASS_H_

