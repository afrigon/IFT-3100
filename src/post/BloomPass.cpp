//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "BloomPass.h"

BloomPass::BloomPass() {
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
        uniform sampler2D bloomedTex;

        void main() {
            fragmentColor = texture(readTex, varyingTexcoord) +
                            texture(bloomedTex, varyingTexcoord);
        }
    );
    oss.str("");
    oss << "#version 330" << endl << fragmentShader;
    this->shader.setupShaderFromSource(GL_FRAGMENT_SHADER, oss.str());
    this->shader.bindDefaults();
    this->shader.linkProgram();
}

void BloomPass::render(ofFbo& readFbo, ofFbo& writeFbo) {
    writeFbo.begin();
    ofClear(0, 0, 0, 255);
    
    ofFbo pingPong[2];
    ofFbo::Settings s;
    
    s.width = writeFbo.getWidth();
    s.height = writeFbo.getHeight();
    s.textureTarget = GL_TEXTURE_2D;
    
    pingPong[0].allocate(s);
    pingPong[1].allocate(s);
    
    brightPass.render(readFbo, pingPong[0]);
    gaussianBlurPass.direction = ofVec2f(1, 0);
    gaussianBlurPass.render(pingPong[0], pingPong[1]);
    gaussianBlurPass.direction = ofVec2f(0, 1);
    gaussianBlurPass.render(pingPong[1], pingPong[0]);
    
    this->shader.begin();
    this->shader.setUniformTexture("readTex", readFbo, 1);
    this->shader.setUniformTexture("bloomedTex", pingPong[0], 2);
    this->texturedQuad(writeFbo.getWidth(), writeFbo.getHeight());
    this->shader.end();
    
    writeFbo.end();
}
