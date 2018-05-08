//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "BrightPass.h"

BrightPass::BrightPass() {
    ostringstream oss;
    string vertexShader = STRINGIFY(
        in vec4 position;
        in vec2 texcoord;
        out vec2 varyingTexcoord;
                                    
        void main() {
            varyingTexcoord = texcoord;
            gl_Position = position;
        }
    );
    oss << "#version 330" << endl << vertexShader;
    this->shader.setupShaderFromSource(GL_VERTEX_SHADER, oss.str());
    
    string fragmentShader = STRINGIFY(
        in vec2 varyingTexcoord;
        out vec4 fragmentColor;

        uniform sampler2D readTex;
        uniform float threshold;

        void main() {
            fragmentColor = texture(readTex, varyingTexcoord);
            float brightness = fragmentColor.r * 0.2125 + fragmentColor.g * 0.7154 + fragmentColor.b * 0.0721;
            if (brightness <= threshold) {
                fragmentColor = vec4(0.0);
            }
        }
    );
    oss.str("");
    oss << "#version 330" << endl << fragmentShader;
    this->shader.setupShaderFromSource(GL_FRAGMENT_SHADER, oss.str());
    this->shader.bindDefaults();
    this->shader.linkProgram();
}

void BrightPass::render(ofFbo& readFbo, ofFbo& writeFbo) {
    writeFbo.begin();
    ofClear(0, 0, 0, 255);
    
    this->shader.begin();
    this->shader.setUniformTexture("readTex", readFbo, 1);
    this->shader.setUniform1f("threshold", this->threshold);
    this->texturedQuad(writeFbo.getWidth(), writeFbo.getHeight());
    this->shader.end();
    
    writeFbo.end();
}
