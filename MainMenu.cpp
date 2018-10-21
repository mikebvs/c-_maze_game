#include "MainMenu.h"

void MainMenu::draw(Graphics* window){
    int width = window->getWidth();
    int height = window->getHeight();
	window->clearGraphics();

    window->toggleAttribute("BOLD");

	ifstream fin;
    string c = "";
    fin.open("MENU.txt");
	while(menuT.size() != 0){
		menuT.pop_back();
	}
    while(getline(fin,c)){
        menuT.push_back(c);
    }
    fin.close();
    for(int i = 0; i<menuT.size(); ++i){
        string title = menuT[i];
        window->drawString(width/2-(menuT[0].size()/2), height/2-25+i, title);
	}

	window->toggleAttribute("BOLD");	
    fin.open("MENUTHING.txt");
    while(menuR.size() != 0){
        menuR.pop_back();
    }
    while(getline(fin,c)){
        menuR.push_back(c);
    }
    fin.close();
    for(int i = 0; i<menuR.size(); ++i){
        string title = menuR[i];
        window->drawString(width/2-(menuR[0].size()/2), height/2-15+i, title);
    }

    window->setColor("WHITE");
	vector<string> vec = {"[N]EW GAME", "[L]OAD GAME", "[I]NSTRUCTIONS", "[Q]UIT GAME"};
	for(int i = 0; i<vec.size(); ++i){
	    string todraw = vec[i];
		window->drawString(width/2-7,height/2-3+i,todraw);
	}
}

