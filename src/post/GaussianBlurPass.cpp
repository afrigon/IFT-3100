//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "GaussianBlurPass.h"

GaussianBlurPass::GaussianBlurPass() {
    ostringstream oss;
    string vertexShader = STRINGIFY(
        in vec4 position;
        in vec2 texcoord;
        out vec2 blurTexcoords[11];
                         
        uniform float targetWidth;
        uniform vec2 direction;
                                    
        void main() {
            float pixelSize = 1.0 / targetWidth;
            for (int i = -5; i <= 5; ++i) {
                blurTexcoords[i + 5] = texcoord + vec2(pixelSize * i * direction.y, pixelSize * i * direction.y);
            }
            gl_Position = position;
        }
    );
    oss << "#version 330" << endl << vertexShader;
    this->shader.setupShaderFromSource(GL_VERTEX_SHADER, oss.str());
    
    string fragmentShader = STRINGIFY(
        in vec2 blurTexcoords[11];
        out vec4 fragmentColor;

        uniform sampler2D readTex;
                                      
        void main() {
            fragmentColor = vec4(0.0);
            fragmentColor += texture(readTex, blurTexcoords[0]) * 0.0093;
            fragmentColor += texture(readTex, blurTexcoords[1]) * 0.028002;
            fragmentColor += texture(readTex, blurTexcoords[2]) * 0.065984;
            fragmentColor += texture(readTex, blurTexcoords[3]) * 0.121703;
            fragmentColor += texture(readTex, blurTexcoords[4]) * 0.175713;
            fragmentColor += texture(readTex, blurTexcoords[5]) * 0.198596;
            fragmentColor += texture(readTex, blurTexcoords[6]) * 0.175713;
            fragmentColor += texture(readTex, blurTexcoords[7]) * 0.121703;
            fragmentColor += texture(readTex, blurTexcoords[8]) * 0.065984;
            fragmentColor += texture(readTex, blurTexcoords[9]) * 0.028002;
            fragmentColor += texture(readTex, blurTexcoords[10]) * 0.0093;
        }
    );
    oss.str("");
    oss << "#version 330" << endl << fragmentShader;
    this->shader.setupShaderFromSource(GL_FRAGMENT_SHADER, oss.str());
    this->shader.bindDefaults();
    this->shader.linkProgram();
}

void GaussianBlurPass::render(ofFbo& readFbo, ofFbo& writeFbo) {
    writeFbo.begin();
    ofClear(0, 0, 0, 255);
    
    this->shader.begin();
    this->shader.setUniformTexture("readTex", readFbo, 1);
    this->shader.setUniform1f("targetWidth", writeFbo.getWidth());
    this->shader.setUniform2f("direction", this->direction);
    this->texturedQuad(writeFbo.getWidth(), writeFbo.getHeight());
    this->shader.end();
    
    writeFbo.end();
}
