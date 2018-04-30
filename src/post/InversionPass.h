//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef POST_INVERSIONPASS_H_
#define POST_INVERSIONPASS_H_

#include "RenderPass.h"

class InversionPass: public RenderPass {
    ofShader shader;
    
public:
    typedef shared_ptr<InversionPass> Ptr;
    
    InversionPass();
    void render(ofFbo& readFbo, ofFbo& writeFbo);
};

#endif  // POST_INVERSIONPASS_H_

