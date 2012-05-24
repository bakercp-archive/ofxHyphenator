#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    stringstream texPat_H; // all of our data will be appended here

    texPat_H << "#pragma once" << endl << endl;

    texPat_H << "// THIS HEADER IS GENERATED AUTOMATICALLY" << endl;
    texPat_H << "// it includes base64 encoded strings representing the" << endl; 
    texPat_H << "// following TEX pattern files:" << endl;
    
    string folder = "patterns";
    
    ofDirectory patternDir(folder);
    
    int n = patternDir.listDir();
    for(int i = 0; i < n; i++) {
        ofFile file = patternDir.getFile(i);
        texPat_H << "//    " << folder << "/" << file.getBaseName() << endl;
    }

    texPat_H << "//" << endl;
    texPat_H << "// Christopher Baker <http://christopherbaker.net>" << endl << endl;

    texPat_H << "#define stringify(text) # text" << endl << endl;

    for(int i = 0; i < n; i++) {
        ofFile file(patternDir.getFile(i).getAbsolutePath());
        ofBuffer buff = file.readToBuffer();
        string str = buff.getText();
        
        ofUTF8::isValid(str);
        
        string stringName = folder + "_" + file.getBaseName();
        ofStringReplace(stringName,"-","_");

        texPat_H << "string " << stringName << " = stringify(" << endl;
        Poco::Base64Encoder encoder(texPat_H);
        encoder << str; // base64 encode file
        encoder.close();
        texPat_H << endl;
        texPat_H << ");";
        texPat_H << endl;
        texPat_H << endl;
    }
    
    ofFile out("ofHyphenatorPatterns.h",ofFile::WriteOnly);
    out << texPat_H.str();
    out.close();

    // now go move the generated file into the library.
}