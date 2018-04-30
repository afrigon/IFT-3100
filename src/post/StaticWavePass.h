//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef POST_STATICWAVEPASS_H_
#define POST_STATICWAVEPASS_H_

#include "RenderPass.h"

class StaticWavePass: public RenderPass {
    ofShader shader;
    
public:
    typedef shared_ptr<StaticWavePass> Ptr;
    float offset = 0;
    
    StaticWavePass();
    void render(ofFbo& readFbo, ofFbo& writeFbo);
};

#endif  // POST_STATICWAVEPASS_H_



