#include "Menu.h"

void Menu::draw(Graphics* window){
    int width = window->getWidth();
    int height = window->getHeight();
	window->clearGraphics();
	ifstream fin;
	string c = "";
	fin.open("PAUSE.txt");
	while(paused.size() != 0){		
		paused.pop_back();
	}								
	while(getline(fin,c)){
		paused.push_back(c);
	}	
	fin.close();
	for(int i = 0; i<paused.size(); ++i){
		string title = paused[i];
		window->drawString(width/2-(paused[0].size()/2), height/2-16+i, title);
	}
    window->setColor("WHITE");
    vector<string> vec = {"[R]ESUME", "[S]AVE GAME", "[M]ENU SHOP", "[Q]UIT"};
    for(int i = 0; i<vec.size(); ++i){
        string todraw = vec[i];
        window->drawString(width/2-7,height/2-3+i,todraw);
    }
}
