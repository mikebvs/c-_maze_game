//starter code for main
#include "Console.h"
#include "Game.h"

#include <stack>
#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main(int argc,char** argv){
	srand(time(0));



//SCREENS
	Console console = Console();
	MainMenu screenMainMenu = MainMenu();
	Menu screenMenu = Menu();
	ChooseSize screenCS = ChooseSize();
	Instructions screenIns = Instructions();
	Load screenLoad	= Load();
	Saves screenSaves = Saves();
	Files screenFiles = Files();
	ShopScreen screenShop = ShopScreen();

//STARTING CONDITIONS
	Maze maze;
	console.setDrawable(&screenMainMenu);
	string mazeSize = "";
	console.initialize();
	string line = "";
	console.redraw();
	bool running = true;
	int status = 0;

//KEYPRESS FUNCTIONS WHILE GAME IS RUNNING
	while(running){
        if(console.getLine(line)){
        }else if(console.hasChanged()){
            Drawable* screen = console.getDrawable();
//IN MAIN MENU
			if(screen == &screenMainMenu){
				if(line[0] == 'q'){
					running = false;
				}
				if(line[0] == 'n'){
					console.setDrawable(&screenCS);
				}
				if(line[0] == 'i'){
					console.setDrawable(&screenIns);
				}
				if(line[0] == 'l'){
					console.setDrawable(&screenLoad);
				}
/*
				if(line[0] == 's'){
					console.setDrawable(&screenFiles);
				}
*/
			}
//IN SAVE FILES FROM MAIN MENU
			if(screen == &screenFiles){
				if(line[0] == 'q'){
					console.setDrawable(&screenMainMenu);
				}
			}
//IF IN INSTRUCTIONS
			if(screen == &screenIns){
				if(line[0] == 'q'){
					console.setDrawable(&screenMainMenu);
				}
			}
//IF IN CHOOSE SIZE OF MAP
			if(screen == &screenCS){
				if(line[0] == '1'){
					mazeSize = "Small";
					maze.generate(mazeSize);
					maze.load("TEMP.txt", "NewStats.txt");
					console.setDrawable(&maze);
				}
				if(line[0] == '2'){
                    mazeSize = "Medium";
                    maze.generate(mazeSize);
                    maze.load("TEMP.txt","NewStats.txt");
                    console.setDrawable(&maze);
                }
                if(line[0] == '3'){
                    mazeSize = "Large";
                    maze.generate(mazeSize);
                    maze.load("TEMP.txt", "NewStats.txt");
                    console.setDrawable(&maze);
                }
				if(line[0] == 'q'){
					console.setDrawable(&screenMainMenu);
				}
			}
//IF IN PAUSE MENU
			if(screen == &screenMenu){
				if(line[0] == 'q'){
					console.setDrawable(&screenMainMenu);
				}
				if(line[0] == 'r'){
					console.setDrawable(&maze);
				}
				if(line[0] == 's'){
					console.setDrawable(&screenSaves);
				}	
				if(line[0] == 'm'){							
					console.setDrawable(&screenShop);
				}	
			}
//IF IN SHOP SCREEN
			if(screen == &screenShop){							
				if(line[0] == '1'){
					maze.shop(1);
				}
				if(line[0] == '2'){
					maze.shop(2);
				}
				if(line[0] == 'r'){
					console.setDrawable(&screenMenu);
				}
			
			}

																

//IF IN SAVES SCREEN
			if(screen == &screenSaves){
				if(line[0] == '1'){
					maze.save("SaveOne.txt", "SaveOneStats.txt");
					console.setDrawable(&screenMenu);
				}
				if(line[0] == '2'){
					maze.save("SaveTwo.txt", "SaveTwoStats.txt");
                    console.setDrawable(&screenMenu);
				}
				if(line[0] == '3'){
					maze.save("SaveThree.txt", "SaveThreeStats.txt");
                    console.setDrawable(&screenMenu);
				}
				if(line[0] == '4'){
					maze.save("SaveFour.txt", "SaveFourStats.txt");
                    console.setDrawable(&screenMenu);
				}
				if(line[0] == '5'){
					maze.save("SaveFive.txt", "SaveFiveStats.txt");
                    console.setDrawable(&screenMenu);
				}
				if(line[0] == 'r'){
					console.setDrawable(&screenMenu);
				}
			}
//IF IN LOAD SAVES SCREEN
			if(screen == &screenLoad){
				if(line[0] == '1'){                                                       
					maze.load("SaveOne.txt", "SaveOneStats.txt");
					console.setDrawable(&maze);                                             
                }                                                                         
                if(line[0] == '2'){                                                       
                    maze.load("SaveTwo.txt", "SaveTwoStats.txt");
                    console.setDrawable(&maze);                                             
                }
                if(line[0] == '3'){                                                       
                    maze.load("SaveThree.txt", "SaveThreeStats.txt");                                           
                    console.setDrawable(&maze);
				}                                                                         
                if(line[0] == '4'){                                                       
                    maze.load("SaveFour.txt", "SaveFourStats.txt");
                    console.setDrawable(&maze);
                }
                if(line[0] == '5'){                                                       
                    maze.load("SaveFive.txt", "SaveFiveStats.txt");                                            
                    console.setDrawable(&maze);
                }    
				if(line[0] == 'q'){
					console.setDrawable(&screenMainMenu);
				}                                                            
			}
//IF IN MAZE
			if(screen == &maze){
				if(line[0] == 'a'){
                    Coord left = {-1,0};
                    maze.move(left);
                    console.setDrawable(&maze);
                }
                if(line[0] == 'w'){
                    Coord up = {0,-1};
                    maze.move(up);
                    console.setDrawable(&maze);
                }
                if(line[0] == 's'){
                    Coord down = {0,1};
                    maze.move(down);
                    console.setDrawable(&maze);
                }
                if(line[0] == 'd'){
                    Coord right = {1,0};
                    maze.move(right);
                    console.setDrawable(&maze);
                }
				if(line[0] == 'm'){
					console.setDrawable(&screenMenu);
				}
				if(line[0] == 'b'){
					Coord Bomb = {0,0};
					maze.move(Bomb);
					console.setDrawable(&maze);
				}
				if(line[0] == 'q'){
					console.setDrawable(&screenMainMenu);
				}
			}

        
            console.clearBuffer();
            console.redraw();
        }
	} 
    console.shutdown();
	

	return 0;
}
