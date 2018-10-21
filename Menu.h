#ifndef MENU__H
#define MENU__H
#include "Drawable.h"
#include <string>
#include <vector>
using namespace std;

class Menu: public Drawable{
    public:
        void draw(Graphics* window);
	private:
		vector<string> paused;
};

#endif

