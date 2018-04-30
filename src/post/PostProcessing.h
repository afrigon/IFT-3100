//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef POST_POSTPROCESSING_H_
#define POST_POSTPROCESSING_H_

#include "RenderPass.h"
#include "BloomPass.h"
#include <vector>

class PostProcessing {
    ofFbo raw;
    ofFbo pingPong[2];
    vector<RenderPass::Ptr> passes;
    
    void setup();
    void process();
    
 public:
    PostProcessing();
    void resize();
    void begin();
    void end();
    
    template<class T>
    void createPass() { passes.push_back(shared_ptr<T>(new T())); }
};

#endif  // POST_POSTPROCESSING_H_
