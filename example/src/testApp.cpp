#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    ofFile file("patterns/de-DE-1901");
    ofBuffer buff = file.readToBuffer();
    
    
    stringstream ss;
    Base64Encoder encoder(ss);
    encoder << buff.getText();// "Hello, world!";
    encoder.close();
    cout << ">>" << ss.str() << "<<" << endl;
    
    stringstream dd;
    
    std::istringstream istr(ss.str());
    Base64Decoder decoder(istr);
    std::string s;
    int c = decoder.get();
    while (c != -1) { s += char(c); c = decoder.get(); }
    
    cout << s << endl;
     
    assert(buff.getText() == s);
    
     /*
    Hyphenate::Hyphenator hyph(ofFilePath::getAbsolutePath("patterns/en").c_str());
    
    string s = "The quick brown fox jumped over the lazy dog.";
    string shyph = hyph.hyphenate(s);
    
    cout << "From: " << s << endl;
    cout << "  To: " << shyph << endl;
    cout << "---" << endl;
    
    s = "example";
    shyph = hyph.hyphenate(s);
    cout << "From: " << s << endl;
    cout << "  To: " << shyph << endl;
    cout << "---" << endl;
    
    s = "Frank was a hot-headed cop";
    shyph = hyph.hyphenate(s);
    cout << "From: " << s << endl;
    cout << "  To: " << shyph << endl;
    cout << "---" << endl;

    s = "nonaffiliated, nonemergency, uninfected, inpatient, disorder, disbar, coworker, copayment, antismoking, antimanagement, hyperactive, hyperrealism, preoperative, prejudge, reoccur, readjust, resubmit, postoperative, posttraumatic, outpatient, outmoded, bimonthly, biannual, counterrevolutionary, counterculture, decompress, semifinal, semiannual, misinformed, misprint, megabyte, microcircuit, interconnected, interoffice, overempha­size, override, underrepresent, underestimated";
    shyph = hyph.hyphenate(s);
    cout << "From: " << s << endl;
    cout << "  To: " << shyph << endl;
    cout << "---" << endl;
    */
    
}


//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}