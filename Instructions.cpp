#include "Instructions.h"
  
void Instructions::draw(Graphics* window){
    int width = window->getWidth();
    int height = window->getHeight();
    window->clearGraphics();

	ifstream fin;
    string c = "";
    fin.open("INSTRUCTIONS.txt");
    while(sizeD.size() != 0){
        sizeD.pop_back();
    }
    while(getline(fin,c)){
        sizeD.push_back(c);
    }
    fin.close();
    for(int i = 0; i<sizeD.size(); ++i){
        string title = sizeD[i];
        window->drawString(width/2-(sizeD[0].size()/2), height/2-25+i, title);
    }



    window->setColor("WHITE");
    vector<string> vec = {"Move using w,a,s,d","Select a small, medium, or large map","Coins look like: $","Traps look like: ^","Your goal is to find the \"F\" at the end of the maze","Use \"M\" to open the shop while in game", "You can save and load at any point in the Pause Menu","You have a limited amount of health, use it wisely","You start the game with 2 bombs and can buy more with coins", "", "[Q]UIT TO MAIN MENU"};
    for(int i = 0; i<vec.size(); ++i){
        string todraw = vec[i];
        window->drawString(width/2-(vec[i].size()/2),height/2-3+i,todraw);
    }
}

