//
//  ofxHyphenate.h
//  ofxHyphenateExample
//
//  Created by Christopher Baker on 5/13/12.
//  Copyright (c) 2012 School of the Art Institute of Chicago. All rights reserved.
//

#pragma once

#include "ofMain.h"
#include "Hyphenator.h"
//#include "ofxHyphenatorPatterns.h"

class ofHyphenator {
public:
    ofHyphenator();
    virtual ~ofHyphenator();
    
    
    
protected:
    
private:
    
    Hyphenate::Hyphenator hyph;
    
};

