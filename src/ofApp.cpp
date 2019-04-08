#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	bool did_load_succeed = ofLoadImage(texture, "C:\\Users\\simde\\source\\repos\\of_v0.10.1_vs2017_release\\apps\\myApps\\finalProject-sdesai51\\images\\sunset.jpg");
	if (did_load_succeed) {
		std::cout << "load succeeded\n";
	}
	else {
		std::cout << "failed\n"; 
	}

	//image.load("C:\\Users\simde\source\repos\of_v0.10.1_vs2017_release\apps\myApps\finalProject-sdesai51\images\sunset.jpg");
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	texture.draw(100, 100, 1);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
