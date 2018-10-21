#ifndef CHOOSESIZE__H
#define CHOOSESIZE__H
#include "Drawable.h"
using namespace std;

class ChooseSize: public Drawable{
    public:
        void draw(Graphics* window);
	private:
		vector<string> sizeR;
};

#endif

