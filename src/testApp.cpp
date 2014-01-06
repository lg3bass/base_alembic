#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    
    myButton.addListener(this,&testApp::myButtonPressed);
    testBut.addListener(this,&testApp::resetNormalsPressed);
    
    gui.setup("panel");
    gui.add(animP.setup("Auto Animate", false));
    gui.add(toggleWire.setup("Toggle Wireframe",true));
    gui.add(timeP.setup("Time",0.5,0.0,1.0));
    gui.add(myButton.setup("report"));
	gui.add(testBut.setup("reset"));
    
    //ofSetFrameRate(60);
    //ofBackground(10, 10, 10);
    
    //for some reason this is interfering with the gui
    ofEnableDepthTest(); //make sure we test depth for 3d
    
     // turn on smooth lighting //
    ofSetSmoothLighting(true);
	ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    bHide = true;
    
    // light the scene to show off why normals are important
    light.enable();
    light.setPointLight();
    light.setPosition(0,0,100);

    myABC_1.init("vbo_1_s1_n20.abc",false);
    myABC_1.setScale(25.0);//multiply x10 to get from Maya cm to m.
    
    //myABC_2.init("vbo_2_general_64_12-tri.abc",false);// original 1.2 mb.
    //myABC_2.init("vbo_2_g64-12-quad-s25.abc",false);// shot the moon. set the mesh to quads. 4mb
    myABC_2.init("vbo_2_g32-4-quad-s2-n25.abc",false);//like candy!!! ;) 3.4 mb.  smoothed the mesh x2
    myABC_2.setScale(25.0);//multiply x10 to get from Maya cm to m.
    myABC_2.setPosition(0,0,50);
    
    
    myABC_3.init("vbo_3_general_4_3-tri_3_locked.abc",false);
    myABC_3.setScale(25.0);
    myABC_3.setPosition(0,100,-50);
    
    //EPIPHANY: 12/30/13 -  fuckin normals need to be HARD like my dong!
    //myABC_4.init("vbo_4.abc",false);
    myABC_4.init("vbo_4b_normalAngle25.abc",false);//Normal angle = 25. Set from Maya>Normals>Set Normal Angle.
    myABC_4.setScale(25.0);
    myABC_4.setPosition(0,0,75);
    
    
    //dont think this is being used.
    center.set(ofGetWidth()*.5, ofGetHeight()*.5, 0);
    
   
}

//--------------------------------------------------------------
void testApp::exit(){
    myButton.removeListener(this,&testApp::myButtonPressed);
    testBut.removeListener(this,&testApp::resetNormalsPressed);
}


//--------------------------------------------------------------
void testApp::myButtonPressed(){
    myABC_1.reportOnMe("myABC_1");
    myABC_2.reportOnMe("myABC_2");
    myABC_3.reportOnMe("myABC_3");
    myABC_4.reportOnMe("myABC_4");
}


//--------------------------------------------------------------
void testApp::resetNormalsPressed(){
    myABC_1.resetNormals();
    myABC_2.resetNormals();
    myABC_3.resetNormals();
    myABC_4.resetNormals();

}



//--------------------------------------------------------------
void testApp::update(){
    ofSetWindowTitle("fps: "+ofToString(ofGetFrameRate())+" - "+ofToString(ofGetWidth())+","+ofToString(ofGetHeight()));
    
    //cam.setPosition(ofPoint(ofGetWidth()/2, ofGetHeight()/2, -300));
    myABC_1.setShowWireframe(toggleWire);
    myABC_2.setShowWireframe(toggleWire);
    myABC_3.setShowWireframe(toggleWire);
    myABC_4.setShowWireframe(toggleWire);
}

//--------------------------------------------------------------
void testApp::draw(){

    ofEnableLighting();
    
    
    
    ofBackgroundGradient(ofColor(200,200,200),ofColor(0,0,0) );
    if( bHide ){
        ofDisableDepthTest();
		gui.draw();
        ofEnableDepthTest();
	}
   

    
    cam.begin();
    
    if(animP){
        myABC_1.setPlayMode(animP, timeP);
        myABC_2.setPlayMode(animP, timeP);
        myABC_3.setPlayMode(animP, timeP);
        myABC_4.setPlayMode(animP, timeP);
    } else {
        myABC_1.setPlayMode(false, timeP);
        myABC_2.setPlayMode(false, timeP);
        myABC_3.setPlayMode(false, timeP);
        myABC_4.setPlayMode(false, timeP);
    }
    

    myABC_1.draw();
    myABC_2.draw();
    myABC_3.draw();
    myABC_4.draw();
        
    light.draw();
    
    //show Axix, messages and central axis
    ofPushStyle();
    ofDisableLighting();
    ofSetColor(255,0,0,255);
    ofLine(0,0,0,50,0,0);
    ofSetColor(0,255,0,255);
    ofLine(0,0,0,0,50,0);
    ofSetColor(0,0,255,255);
    ofLine(0,0,0,0,0,50);
    ofPopStyle();
    

    
    cam.end();
    
    
    ofPushStyle();
    ofSetColor(0,255,255);
    ofDrawBitmapString("press any key or mouse button to disable mesh normals", 20,20);
    ofDrawBitmapString("light", cam.worldToScreen(light.getGlobalPosition()) + ofPoint(10,0));
    ofPopStyle();
   
    
    


}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
