#include "Saves.h"
  
void Saves::draw(Graphics* window){
    int width = window->getWidth();
    int height = window->getHeight();
    window->clearGraphics();

    window->setColor("WHITE");

    ifstream fin;
    string c = "";
    fin.open("SAVESCREEN.txt");
    while(sizeA.size() != 0){
        sizeA.pop_back();
    }
    while(getline(fin,c)){
        sizeA.push_back(c);
    }
    fin.close();
    for(int i = 0; i<sizeA.size(); ++i){
        string title = sizeA[i];
        window->drawString(width/2-(sizeA[0].size()/2), height/2-16+i, title);
    }


    window->setColor("WHITE");
    vector<string> vec = {"[1] SAVE ONE", "[2] SAVE TWO", "[3] SAVE THREE", "[4] SAVE FOUR", "[5] SAVE FIVE","[R]ETURN TO PREVIOUS MENU"};
    for(int i = 0; i<vec.size(); ++i){
        string todraw = vec[i];
        window->drawString(width/2-7,height/2-3+i,todraw);
    }
}


