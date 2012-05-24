//
//  ofxHyphenator.cpp
//  ofxHyphenatorExample
//
//  Created by Christopher Baker on 5/24/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#include "ofHyphenator.h"
#include "ofHyphenatorPatterns.h"

//--------------------------------------------------------------
ofHyphenator::ofHyphenator() {
    loadDefaultPattern("en");
}

//--------------------------------------------------------------
ofHyphenator::~ofHyphenator() {
    // hyphenate is internally represented with an autoptr, so nothing to do.
}

//--------------------------------------------------------------
bool ofHyphenator::loadDefaultPattern(string lang) {
    string dictString = getEncodedPattern(lang);
    // hyphenate is internally represented with an autoptr, so nothing to do.
    hyph = new Hyphenate::Hyphenator(dictString);
}
//--------------------------------------------------------------
bool ofHyphenator::loadPatternsFromFile(string filename) {
    ofFile file(filename);
    if(file.exists()) {
        // hyphenate is internally represented with an autoptr, so nothing to do.
        hyph = new Hyphenate::Hyphenator(file.getAbsolutePath().c_str());
    } else {
        ofLog(OF_LOG_ERROR,"ofHyphenator::loadPatternsFromFile : " + filename + " not found.");
    }

}
//--------------------------------------------------------------
bool ofHyphenator::loadPatternsFromString(string dictString) {
    // hyphenate is internally represented with an autoptr, so nothing to do.
    hyph = new Hyphenate::Hyphenator(dictString);
}

//--------------------------------------------------------------
string ofHyphenator::softHyphenate(const string &word) {
    return hyphenate(word,"\u00AD"); // \u00AD is a soft hyphen SHY
}
       
//--------------------------------------------------------------
string ofHyphenator::hyphenate(const string &word, const string &hyphen) {
    if(hyph != NULL) {
        return hyph->hyphenate(word,hyphen);
    } else {
        ofLog(OF_LOG_ERROR,"ofHyphenator::hyphenate : no hyphenation dictionary loaded.");
        return word;
    }
}

//--------------------------------------------------------------
string ofHyphenator::getEncodedPattern(string lang) {
    string base64EncodedString;
    string dictionary;

    // read one of the pattern files from the 
    // ofHyphenateTexLangPattern.h file.
    if(lang == "en") {
        base64EncodedString = patterns_en;
    } else if(lang == "fr") {
        base64EncodedString = patterns_fr;
    } else if(lang == "es") {
        base64EncodedString = patterns_es;
    } else if(lang == "de") {
        base64EncodedString = patterns_de;
    } else if(lang == "de_DE_1901") {
        base64EncodedString = patterns_de_DE_1901;
    } else {
        ofLog(OF_LOG_ERROR,"ofHyphenator::getEncodedPattern : no default dictionary for " + lang + " defaulting to English.");
        base64EncodedString = patterns_en;
    }

    // decode the base64 encoded patterns
    istringstream istr(base64EncodedString);
    Poco::Base64Decoder decoder(istr);
    // copy the decoded string into the dictionary strin for output
    int c = decoder.get();
    while (c != -1) { dictionary += char(c); c = decoder.get(); }
    return dictionary;
}

