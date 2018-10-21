#ifndef SAVES__H
#define SAVES__H
#include "Drawable.h"

using namespace std;

class Saves: public Drawable{
    public:
        void draw(Graphics* window);
	private:
		vector<string> sizeA;
};

#endif

