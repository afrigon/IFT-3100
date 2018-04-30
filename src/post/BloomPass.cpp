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
                                      
        void main() {
            fragmentColor = vec4(1.0, 0.0, 0.0, 1.0);
        }
    );
    oss.str("");
    oss << "#version 330" << endl << fragmentShader;
    this->shader.setupShaderFromSource(GL_FRAGMENT_SHADER, oss.str());
    this->shader.linkProgram();
}

void BloomPass::render(ofFbo& readFbo, ofFbo& writeFbo) {
    writeFbo.begin();
    ofClear(0, 0, 0, 255);
    
    this->shader.begin();
    this->shader.setUniformTexture("readTex", readFbo.getTexture(), 0);
    
    ofMesh m = ofMesh();
    m.setMode(ofPrimitiveMode::OF_PRIMITIVE_TRIANGLE_FAN);
    
    m.addVertex(ofVec3f(-writeFbo.getWidth()/2, -writeFbo.getHeight()/2, 0));
    m.addTexCoord(ofVec2f(0, 0));
    
    m.addVertex(ofVec3f(writeFbo.getWidth()/2, -writeFbo.getHeight()/2, 0));
    m.addTexCoord(ofVec2f(1, 0));
    
    m.addVertex(ofVec3f(writeFbo.getWidth()/2, writeFbo.getHeight()/2, 0));
    m.addTexCoord(ofVec2f(1, 1));
    
    m.addVertex(ofVec3f(-writeFbo.getWidth()/2, writeFbo.getHeight()/2, 0));
    m.addTexCoord(ofVec2f(0, 1));
    
    m.draw();
    //ofDrawRectangle(-writeFbo.getWidth()/2, -writeFbo.getHeight()/2, writeFbo.getWidth(), writeFbo.getHeight());
    this->shader.end();
    
    writeFbo.end();
}
