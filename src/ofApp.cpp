#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofLoadImage(texture, "C:\\Users\\simde\\source\\repos\\of_v0.10.1_vs2017_release\\apps\\myApps\\finalProject-sdesai51\\images\\sunset.jpg");
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	texture.draw(100, 100, 1);
}

//--------------------------------------------------------------
