//
//  ofxHyphenate.h
//  ofxHyphenateExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "Poco/Base64Decoder.h"
#include "Hyphenator.h"


class ofHyphenator {
public:
    ofHyphenator();
    virtual ~ofHyphenator();

    bool loadDefaultPattern(string lang);
    bool loadPatternsFromFile(string filename);
    bool loadPatternsFromString(string dictString);

    string softHyphenate(const string &word);
    string hyphenate(const string &word, const string &hyphen = "-");

    

protected:

    string getEncodedPattern(string lang);
    
private:
    
    Hyphenate::Hyphenator* hyph;
    
};

