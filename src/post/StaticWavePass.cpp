//
//  Copyright (c) 2018 Alexandre Frigon / Alexandre Rouleau
//
//  Use of this source code is governed by a MIT license that can be
//  found in the LICENSE file.
//

#include "StaticWavePass.h"

StaticWavePass::StaticWavePass() {
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
        uniform float offset;
                                      
        void main() {
            vec2 texcoord = varyingTexcoord;
            texcoord.x += sin(texcoord.y * 4*2*3.14159 + offset) / 100;
            fragmentColor = texture(readTex, texcoord);
        }
    );
    oss.str("");
    oss << "#version 330" << endl << fragmentShader;
    this->shader.setupShaderFromSource(GL_FRAGMENT_SHADER, oss.str());
    this->shader.bindDefaults();
    this->shader.linkProgram();
}

void StaticWavePass::render(ofFbo& readFbo, ofFbo& writeFbo) {
    writeFbo.begin();
    ofClear(0, 0, 0, 255);
    
    this->shader.begin();
    this->shader.setUniformTexture("readTex", readFbo, 1);
    this->shader.setUniform1f("offset", ofGetElapsedTimef() * 2*3.14159 * 0.75);
    this->texturedQuad(writeFbo.getWidth(), writeFbo.getHeight());
    this->shader.end();
    
    writeFbo.end();
}
