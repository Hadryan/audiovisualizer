#include "ofApp.h"


const int numberOfDots = 450;
//Range for frequency of audio
const int numberOfBars = 400;
//Two dimensional vector-like structure to hold dots and their x,y coordinates
int barWidth = 10;
int maxBarHeight = 250;
ofVec2f dots[numberOfDots];
int distanceThreshold = 50;
double dotSpeed = .1;
int animationRadius = 500;
double currentTime = 0;
float dotRadius = 3;
float lineWidth = 2;
float speedMultiplier = 2;
vector<bool> isConnected(numberOfDots, false);
//Vector that determines the offset of the x,y coordindates of each dot to ensure they remain centered and on screen
vector<double> yOffset(numberOfDots), xOffset(numberOfDots);
float soundSpectrum[numberOfBars];
bool maxBarHeightReached = false;



void ofApp::setup() {
	backgroundImage.load("C:\\Users\\simde\\source\\repos\\of_v0.10.1_vs2017_release\\apps\\myApps\\finalProject - sdesai51\\bin\\data\\sunset.jpg`");
	soundPlayer.loadSound("..//..//audio//audioBeats.wav");
	soundPlayer.play();
	for (int i = 0; i < numberOfDots; i++) {
		xOffset[i] = ofRandom(0, 1000);
		yOffset[i] = ofRandom(0, 1000);
	
	}
	for (int i = 0; i < numberOfBars; i++) {
		soundSpectrum[i] = 0.0f;
	}
}

void ofApp::update(){
	ofSoundUpdate();
	//Gets a frequency spectrum sample 
	float *value = ofSoundGetSpectrum(numberOfBars);
	updateDots();
	for (int i = 0; i < numberOfBars; i++) {
		soundSpectrum[i] = max(soundSpectrum[i], value[i]);
	}
}

void ofApp::draw(){
	backgroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());
	drawBars();
	drawDots();

}

//Setup, Update, and Draw Dots for foreground animation of the Audio Visualizer
void ofApp::drawDots() {
	if (maxBarHeightReached) {
		dotRadius = 4;
		lineWidth = 3;
	} else {
		dotRadius = 3;
		lineWidth = 2;
	}
	//Centers the dots within the animation 
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//Choose the color of the dots and create circles at those dots
	for (int i = 0; i < numberOfDots; i++) {
		if (isConnected[i]) {
			ofDrawCircle(dots[i].x, dots[i].y, dotRadius);
		}
	}
	linkDots();
	ofPopMatrix();
}

//Link dots when they are a specific distance from one another
void ofApp::linkDots() {
	for (int i = 0; i < numberOfDots; i++) {
		isConnected[i] = false;
		for (int j = i + 1; j < numberOfDots; j++) {
			double distance = ofDist(dots[i].x, dots[i].y, dots[j].x, dots[j].y);
			if (distance < distanceThreshold) {
				isConnected[i] = true;
				ofSetLineWidth(lineWidth);
				ofDrawLine(dots[i], dots[j]);
			}
		}
	}
}

//Updates the positioning of the dots on the screen
void ofApp::updateDots() {
	double timeElapsed = ofGetElapsedTimef();
	//The difference in time since the last update happened
	double timeDifference = timeElapsed - currentTime;
	currentTime = timeElapsed;
	for (int i = 0; i < numberOfDots; i++) {
		//Retrieve the total moved distance by the dots
		yOffset[i] += dotSpeed * timeDifference;
		xOffset[i] += dotSpeed * timeDifference;
		//Update the coordinates of each dot with Perlin Noise
		dots[i].x = ofSignedNoise(xOffset[i]) * animationRadius;
		dots[i].y = ofSignedNoise(yOffset[i]) * animationRadius - 20;
	}
}

void ofApp::drawBars() {
	maxBarHeightReached = false;
	float barHeight;
	//Draw rectangles based on audio frequency
	for (int i = 0; i < numberOfBars; i++) {
		float barHeight = -soundSpectrum[i] * 250;
		ofRect(i * 5, ofGetHeight(), 4, barHeight);
		if (-barHeight >= 250) {
			maxBarHeightReached = true;
		}
	}
}






