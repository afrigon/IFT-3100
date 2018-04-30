//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#ifndef POST_POSTPROCESSING_H_
#define POST_POSTPROCESSING_H_

#include <vector>

#include "RenderPass.h"
#include "BloomPass.h"
#include "BrightPass.h"
#include "GaussianBlurPass.h"
#include "InversionPass.h"
#include "StaticWavePass.h"

class PostProcessing {
    ofFbo raw;
    ofFbo pingPong[2];
    vector<RenderPass::Ptr> passes;
    
    void setup();
    void process();
    
 public:
    PostProcessing();
    ~PostProcessing();
    void resize(ofResizeEventArgs&);
    void begin();
    void end();
    
    template<class T>
    void createPass() { passes.push_back(shared_ptr<T>(new T())); }
};

#endif  // POST_POSTPROCESSING_H_
