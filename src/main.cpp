#include "ofMain.h"
#include "ofApp.h"

// Final Project for CS 126
// Audio Visualization
//
// by Simran Desai
// 04/07/2019

/**
 * The main function to be run.
 */
int main( ){

	// Set up the openFrameworks/openGL window which is the display for the application.
	// The first two parameters are the height and width of the screen. The last parameter is the display mode:
	// OF_WINDOW (display of specified width and height) or OF_FULLSCREEN (full-screen display).

	ofSetupOpenGL(1440,768,OF_FULLSCREEN);		

	// The line belows starts running my application.
	ofRunApp(new ofApp());

}
