#include "Load.h"
  
void Load::draw(Graphics* window){
    int width = window->getWidth();
    int height = window->getHeight();
    window->clearGraphics();
	window->setColor("WHITE");

	ifstream fin;
    string c = "";
    fin.open("LOAD.txt");
    while(sizeC.size() != 0){
        sizeC.pop_back();
    }
    while(getline(fin,c)){
        sizeC.push_back(c);
    }
    fin.close();
    for(int i = 0; i<sizeC.size(); ++i){
        string title = sizeC[i];
        window->drawString(width/2-(sizeC[0].size()/2), height/2-16+i, title);
    }

    window->setColor("WHITE");
    vector<string> vec = {"[1] LOAD ONE", "[2] LOAD TWO", "[3] LOAD THREE", "[4] LOAD FOUR", "[5] LOAD FIVE","[Q]UIT TO MAIN MENU"};
    for(int i = 0; i<vec.size(); ++i){
        string todraw = vec[i];
        window->drawString(width/2-7,height/2-3+i,todraw);
    }
}


