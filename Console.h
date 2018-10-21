#ifndef CONSOLE__H
#define CONSOLE__H
#include <unistd.h>
#include <curses.h>
#include <string>
#include <map>
#include "Graphics.h"
#include "Drawable.h"

using namespace std;


class Console:public Graphics{
public:
    Console();
    void setDrawable(Drawable* draw){ canvas = draw;}
	Drawable* getDrawable(){ return canvas; }
    void initialize();
    void shutdown();
    
    bool getLine(string& line);
    
    void drawString(int x,int y,string str);
    void toggleAttribute(string attr);
    
    int getWidth();
    int getHeight();
    
    void clearGraphics();
    
    void redraw();
    string getBuffer();
	void clearBuffer();
    void setColor(string fg);
	bool hasChanged();
private:
    Drawable* canvas;
    WINDOW* window;
    bool blink,reverse,bold,update;
    int pair;
    map<string,int> pairs;
    
    string buffer;
    
};

#endif
