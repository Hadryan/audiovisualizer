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

