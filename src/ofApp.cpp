#include "ofApp.h"

const int numberOfDots = 324;
ofVec2f dots[numberOfDots];
int dotSpacing = 15;



void ofApp::setup() {
	dotCoordinateSetUp();
	ofLoadImage(texture, "C:\\Users\\simde\\source\\repos\\of_v0.10.1_vs2017_release\\apps\\myApps\\finalProject-sdesai51\\images\\sunset.jpg");
}

void ofApp::update(){

}

void ofApp::draw(){
	texture.draw(100, 100, 1);
	ofBackground(blueBackGround, redBackground, greenBackground);
	drawDots();
}

void ofApp::dotCoordinateSetUp() {
	int index = 0;
	for (int i = 0; i < sqrt(numberOfDots); i++) {
		for (int j = 0; j < sqrt(numberOfDots); j++) {
			dots[index].set(i * dotSpacing, j * dotSpacing);
			index++;
		}
	}
}

void ofApp::drawDots() {
	int size = (sqrt(numberOfDots)) * dotSpacing;
	ofPushMatrix();
	ofTranslate((ofGetWidth() - size) / 2, (ofGetHeight() - size) / 2);
	ofSetColor(blueDot, redDot, greenDot);
	ofFill();
	for (int i = 0; i < numberOfDots; i++) {
		ofCircle(dots[i].x, dots[i].y, 2);
	}
	ofPopMatrix();
}



