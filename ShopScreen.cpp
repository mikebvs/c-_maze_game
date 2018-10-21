#include "ShopScreen.h"


void ShopScreen::draw(Graphics* window){
    int width = window->getWidth();
    int height = window->getHeight();
    window->clearGraphics();
    ifstream fin;
    string c = "";
    fin.open("SHOP.txt");
    while(shops.size() != 0){  
        shops.pop_back();
    }                       
    while(getline(fin,c)){
        shops.push_back(c);
    }
    fin.close();
    for(int i = 0; i<shops.size(); ++i){
        string title = shops[i];
        window->drawString(width/2-(shops[0].size()/2), height/2-16+i, title);
    }
	
    window->setColor("WHITE");
    vector<string> vec = {"[1] 2 Bombs - 5 Coins", "[2] FlashLight - 10 Coins", "", "[R]ETURN"};
    for(int i = 0; i<vec.size(); ++i){
        string todraw = vec[i];
        window->drawString(width/2-7,height/2-3+i,todraw);
    }
}


