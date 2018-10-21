#ifndef SAVESCREEN__H
#define SAVESCREEN__H
#include "Drawable.h"
using namespace std;

class SaveScreen: public Drawable{
    public:
        void draw(Graphics* window);
};

#endif

