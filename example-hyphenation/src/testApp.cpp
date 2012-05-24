#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    // dictionaries can be loaded from file, or by language using the default
    // dictionaries encoded in ofHyphenatorPatterns.h.

    {
        // english dictionary loaded by default from header file
        string s = "Word Hyphenation by Computer.";
        string shyph = hyph.hyphenate(s);
        cout << "    Normal: " << s << endl;
        cout << "Hyphenated: " << shyph << endl;
        cout << "---" << endl;
    }
    
    
    {
        // english dictionary loaded by default from header file
        string s = "Word Hyphenation by Computer.";
        string shyph = hyph.hyphenate(s,"XYZ"); // can hyphenate with any string
        cout << "    Normal: " << s << endl;
        cout << "Hyphenated: " << shyph << endl;
        cout << "---" << endl;
    }

    {
        // english dictionary loaded by default from header file
        string s = "Word Hyphenation by Computer.";
        string shyph = hyph.softHyphenate(s);
        cout << "    Normal: " << s << endl;
        cout << "Hyphenated: " << shyph << " << SOFT HYPHENS ARE INVISIBLE" << endl;
        cout << "---" << endl;
    }
    
    {
        // load a dictionary file from disk
        hyph.loadPatternsFromFile("patterns/fr");

        string s = "Césure des mots par ordinateur.";
        string shyph = hyph.hyphenate(s);
        cout << "    Normal: " << s << endl;
        cout << "Hyphenated: " << shyph << endl;
        cout << "---" << endl;
    }
    
    {
        // load one of the included dictionaries by name
        // if the lang is not included, it will default to english
        hyph.loadDefaultPattern("de");
        
        string s = "Silbentrennung durch Computer.";
        string shyph = hyph.hyphenate(s);
        cout << "    Normal: " << s << endl;
        cout << "Hyphenated: " << shyph << endl;
        cout << "---" << endl;
    }

    {
        // load one of the included dictionaries by name
        // if the lang is not included, it will default to english
        hyph.loadDefaultPattern("es");

        string s = "Palabra de Guiones por la computadora.";
        string shyph = hyph.hyphenate(s);
        cout << "    Normal: " << s << endl;
        cout << "Hyphenated: " << shyph << endl;
        cout << "---" << endl;
    }

    // done!
    
}