//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "ofMain.h"
#include "ofApp.h"

int main() {
    ofGLWindowSettings windowSettings;
    windowSettings.width  = 1024;
    windowSettings.height = 1024;
    //windowSettings.setGLVersion(2, 1);
    windowSettings.setGLVersion(3, 3);
    ofCreateWindow(windowSettings);
    
    ofRunApp(new ofApp());
    return 0;
}
