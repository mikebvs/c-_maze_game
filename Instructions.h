#ifndef INSTRUCTIONS__H
#define INSTRUCTIONS__H
#include "Drawable.h"

using namespace std;

class Instructions: public Drawable{
    public:
        void draw(Graphics* window);
	private:
		vector<string> sizeD;
};

#endif


