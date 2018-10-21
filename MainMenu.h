#ifndef MAINMENU__H
#define MAINMENU__H
#include "Drawable.h"

using namespace std;

class MainMenu: public Drawable{
    public:
        void draw(Graphics* window);
	private:
		vector<string> menuT;
		vector<string> menuR;
};

#endif

