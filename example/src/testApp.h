#pragma once

#include "ofMain.h"
#include "ofxHyphenator.h"
#include "Hyphenator.h"

#include "Poco/Base64Encoder.h"
#include "Poco/Base64Decoder.h"
#include <iostream>
using Poco::Base64Encoder;
using Poco::Base64Decoder;

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
};
