#pragma once
#include "ofMain.h"
#include "ofxAlembic.h"

//
//  abcNode.h
//  base_alembic
//
//  Created by bob white III on 12/28/13.
//
//

#ifndef __base_alembic__abc__
#define __base_alembic__abc__

#include <iostream>

#endif /* defined(__base_alembic__abc__) */


class abcNode : public ofNode {
    
    
    
    
    ofxAlembic::Reader abc;
    //ofVboMesh mesh;
    
    ofColor materialColor;
    ofMaterial material;
    
    float runningTime;
    bool this_anim;
    float aTime;
    
    bool runAbc;
    
    bool doNormals;
    bool doReport;
    bool doResetNormals;
    
    bool showWireframe;
    
    string whoAreYou;
    
    
    
    public:

        abcNode();
        void init(string abc_file, bool _doNormals);
        void customDraw();
        void setPlayMode(bool animate, float animTime);
        void setShowWireframe(bool _showWireframe);
    
        void reportOnMe(string _name);
    
        void resetNormals();
        // we call this update function ourselves
        //  at the beginning of customDraw
        void update();
    
        void setNormals( ofMesh &mesh );
    
};