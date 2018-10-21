#ifndef FILES__H
#define FILES__H
#include "Drawable.h"

using namespace std;

class Files: public Drawable{
    public:
        void draw(Graphics* window);
	private:
		vector<string> sizeB;
};

#endif

