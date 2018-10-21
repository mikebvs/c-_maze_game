#ifndef SHOPSCREEN__H
#define SHOPSCREEN__H
#include "Drawable.h"
#include <string>
#include <vector>
using namespace std;

class ShopScreen: public Drawable{
    public:
        void draw(Graphics* window);
	private:			
		vector<string> shops;		
};

#endif

