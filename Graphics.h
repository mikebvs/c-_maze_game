#ifndef GRAPHICS__H
#define GRAPHICS__H

#include <string>
using namespace std;

class Graphics{
public:
    
    virtual void drawString(int x,int y,string str) = 0;
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
    virtual void clearGraphics() = 0;
    virtual void toggleAttribute(string attr) =0;
	virtual void setColor(string fg) = 0;
};

#endif
