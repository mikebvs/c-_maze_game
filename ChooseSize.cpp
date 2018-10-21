#include "ChooseSize.h"
  
void ChooseSize::draw(Graphics* window){
    int width = window->getWidth();
    int height = window->getHeight();
	window->clearGraphics();
	window->setColor("WHITE");

	ifstream fin;
    string c = "";
    fin.open("MAPSELECT.txt");
    while(sizeR.size() != 0){
        sizeR.pop_back();
    }
    while(getline(fin,c)){
        sizeR.push_back(c);
    }
    fin.close();
    for(int i = 0; i<sizeR.size(); ++i){
        string title = sizeR[i];
        window->drawString(width/2-(sizeR[0].size()/2), height/2-16+i, title);
    }


	
    window->setColor("WHITE");
    vector<string> vec = {"[1] Small Maze", "[2] Medium Maze", "[3] Large Maze", "[Q] Back to Main Menu"};
	for(int i = 0; i<vec.size(); ++i){
		string todraw = vec[i];
		window->drawString(width/2-7,height/2-3+i,todraw);			
	}
}

