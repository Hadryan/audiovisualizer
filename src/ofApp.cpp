#include "ofApp.h"

const int numberOfDots = 200;
ofVec2f dots[numberOfDots];
vector<bool> isConnected(numberOfDots, false);
vector<double> yOffset(numberOfDots), xOffset(numberOfDots);



void ofApp::setup() {
	for (int i = 0; i < numberOfDots; i++) {
		xOffset[i] = ofRandom(0, 100);
		yOffset[i] = ofRandom(0, 100);
	}
}

void ofApp::update(){
	updateDots();
}

void ofApp::draw(){
	ofBackground(backgroundColor->purpleColor, backgroundColor->whiteColor, backgroundColor->pinkColor);
	drawDots();

}

//Setup, Update, and Draw Dots for foreground animation of the Audio Visualizer
void ofApp::drawDots() {
	//Centers the dots within the animation 
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//Choose the color of the dots and create circles at those dots
	ofSetColor(dotColor->purpleColor, dotColor->whiteColor, dotColor->pinkColor);
	ofFill();
	for (int i = 0; i < numberOfDots; i++) {
		ofDrawCircle(dots[i].x, dots[i].y, 2);
	}
	linkDots();
	ofPopMatrix();
}

//Link dots when they are a specific distance from one another
void ofApp::linkDots() {
	for (int i = 0; i < numberOfDots; i++) {
		for (int j = i + 1; j < numberOfDots; j++) {
			double distance = ofDist(dots[i].x, dots[i].y, dots[j].x, dots[j].y);
			if (distance < distanceThreshold) {
				isConnected[i] = true;
				if (isConnected[i]) {
					ofSetColor(ofRandom(255));
				}
				else {
					ofSetColor(0, 0, 0);
				}
				ofDrawLine(dots[i], dots[j]);
			}
			isConnected[i] = false;
		}
	}
}

void ofApp::updateDots() {
	double timeElapsed = ofGetElapsedTimef();
	//The difference in time since the previous update occured
	double timeDifference = timeElapsed - currentTime;
	currentTime = timeElapsed;
	for (int i = 0; i < numberOfDots; i++) {
		//Retieve the total moved distance by the dots
		yOffset[i] += dotSpeed * timeDifference;
		xOffset[i] += dotSpeed * timeDifference;
		//Update the coordinates of each dot with Perlin Noise 
		dots[i].x = ofSignedNoise(xOffset[i]) * animationRadius;
		dots[i].y = ofSignedNoise(yOffset[i]) * animationRadius;
	}
}


