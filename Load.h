#ifndef LOAD__H
#define LOAD__H
#include "Drawable.h"

using namespace std;

class Load: public Drawable{
    public:
        void draw(Graphics* window);
	private:
		vector<string> sizeC;
};

#endif

