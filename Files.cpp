#include "Files.h"
  
void Files::draw(Graphics* window){
    int width = window->getWidth();
    int height = window->getHeight();
    window->clearGraphics();

    window->setColor("WHITE");

    ifstream fin;
    string c = "";
    fin.open("SAVESCREEN.txt");
    while(sizeB.size() != 0){
        sizeB.pop_back();
    }
    while(getline(fin,c)){
        sizeB.push_back(c);
    }
    fin.close();
    for(int i = 0; i<sizeB.size(); ++i){
        string title = sizeB[i];
        window->drawString(width/2-(sizeB[0].size()/2), height/2-16+i, title);
    }



    window->setColor("WHITE");
    vector<string> vec = {"[1] SAVE ONE", "[2] SAVE TWO", "[3] SAVE THREE", "[4] SAVE FOUR", "[5] SAVE FIVE","[Q]UIT TO MAIN MENU"};
    for(int i = 0; i<vec.size(); ++i){
        string todraw = vec[i];
        window->drawString(width/2-7,height/2-3+i,todraw);
    }
}
