ofxHyphenate
============

An implementation of Liangs hy­phen­ation al­go­rithm via Steve Wolter's libhyphenate.

http://www.tug.org/docs/liang/
http://swolter.sdf1.org/software/libhyphenate.html

This ofxAddon includes a modified version of libhyphenate that uses openFramworks ofUnicode / ofUTF8 for Unicode/UTF8 support rather than glib-2.0 and libiconv.

It also implements a system for saving default dictionary patterns to strings so they do not have to be read from disk.

You can find ofUnicode and ofUTF8 here for now:

https://github.com/bakercp/ofxUnicode
