#include "Maze.h"
#include "Console.h"
#include "Graphics.h"
#include "Drawable.h"
#include "Coord.h"
#include <sstream>
#include <cmath>

Maze::Maze(){

}

void Maze::draw(Graphics* window){
	int width = window->getWidth();
	int height = window->getHeight();
	window->clearGraphics();	
	player.x=width/2-1;
	player.y=height/2-1;
	stringstream sout;
	stringstream sout2;	
		
	int space = 2;
	

	Coord radius;
	if(flashlight == false){
		radius = {moveMaze.x+4,moveMaze.y+4};
	}
	if(flashlight == true){
		radius = {moveMaze.x+8,moveMaze.y+8};
	}	

	filePrint=fileMaze;
	for(int i = 0; i<fileMaze.size();++i){
		for(int j = 0; j<fileMaze[i].size();++j){
			Coord ij = {j-1,i-1};
			if(moveMaze.distance(ij) > moveMaze.distance(radius)){
				filePrint[i][j] = ' ';
			}
		}
	}
	for(int i = 0; i<fileMaze.size();++i){
        for(int j = 0; j<fileMaze[i].size();++j){
			char drawme = filePrint[i][j];
			string print = string(1,drawme);
			window->setColor("WHITE");
			if(filePrint[i][j] == '$'){
				window->setColor("GREEN");
			}else if(filePrint[i][j] == '^'){
				window->setColor("MAGENTA");
			}else if(filePrint[i][j] == '.'){
				window->setColor("BLUE");
			}else if(filePrint[i][j] == 'F'){
				window->setColor("RED");
			}
			window->drawString((player.x-moveMaze.x+j), (player.y-moveMaze.y+i), print);
		}
    }

	



	//Constant Player Draw
	window->setColor("YELLOW");
	window->drawString((width/2), (height/2), "@");

	//LIFE Window
	window->setColor("WHITE");
	window->drawString(0,0,"LIFE: ");
	window->setColor("RED");
	for(int i = 0; i<life.size(); ++i){
		window->drawString(4+space, 0, "<3");
		space = space+2;
	}
	window->setColor("WHITE");	
	window->drawString(0,3,"Coord: ");
	window->setColor("YELLOW");			
	string coord1 = to_string(moveMaze.x);
	string coord2 = to_string(moveMaze.y);
	window->drawString(7,3,"{");
	window->drawString(8,3,coord1);
	if(moveMaze.x > 9){
		window->drawString(11,3,coord2);
	}else{
		window->drawString(10,3,coord2);
	}
	if(moveMaze.x > 9 && moveMaze.y <= 9){	
		window->drawString(12,3,"}");
	}else if(moveMaze.x <= 9 && moveMaze.y <=9){
		window->drawString(11,3,"}");
	}
	if( moveMaze.y > 9){
		window->drawString(13,3,"}");
	}									
	//BOMB Window
	window->setColor("WHITE");
	window->drawString(0,1, "BOMBS: ");
	string bomb1 = to_string(bomb);
	window->setColor("MAGENTA");
	window->drawString(7,1,bomb1);
	window->setColor("WHITE");
	
	//CASH Window
	window->drawString(0,2,"CASH: ");
	string money = to_string(cash);
	window->setColor("GREEN");
	window->drawString(6,2,money);
	window->setColor("WHITE");

    if(life.size() == 0){			
        window->clearGraphics();
        ifstream fin;
        string c = "";
        fin.open("GAMEOVER.txt");
        while(GameOver.size() != 0){
            GameOver.pop_back();
        }
        while(getline(fin,c)){
            GameOver.push_back(c);
        }
        fin.close();
        for(int i = 0; i<GameOver.size(); ++i){
            string title = GameOver[i];
            window->drawString(width/2-(GameOver[0].size()/2), height/2-16+i, title);
        }
		window->drawString((width/2)-7,(height/2)-3,"[Q]uit to Main Menu");
    }

    while(WinScreen.size() != 0){
         WinScreen.pop_back();
    }																	
	if(end == true){
		window->clearGraphics();
        ifstream fin;
        string c = "";
        fin.open("WIN.txt");
        while(WinScreen.size() != 0){
            WinScreen.pop_back();
        }
        while(getline(fin,c)){
            WinScreen.push_back(c);
        }
        fin.close();
        for(int i = 0; i<WinScreen.size(); ++i){
            string title = WinScreen[i];
            window->drawString(width/2-(WinScreen[0].size()/2), height/2-16+i, title);
        }
        window->drawString((width/2)-11,(height/2)-3,"[Q]uit to Main Menu");
	}			
																	
}


void Maze::load(string filename, string filenametwo){
	ifstream fin;
	fin.open(filename);
	while(fileMaze.size() != 0){
		fileMaze.pop_back();
	}
	string c = "";
	while(getline(fin,c)){
		fileMaze.push_back(c);
	}
	fin.close();
	fin.open(filenametwo);
	vector<string> stoof;
	string p = "";	

	while(getline(fin,p)){
		stoof.push_back(p);
	}

	string lifes = stoof[0];
	int lifers = 0;
	lifers = stoi(lifes);
	while(life.size() != 0){
		life.pop_back();
	}
	for(int i = 0; i<lifers; ++i){
		life.push_back("<3");
	}
	string bombers = stoof[1];
	bomb = stoi(bombers);

	string cashers = stoof[2];
	cash = stoi(cashers);

	string boolers = stoof[3];
	if(boolers == "0"){
		flashlight = false;
	}else if(boolers == "1"){
		flashlight = true;
	}


	string xer = stoof[4];
	moveMaze.x = stoi(xer);

	string yer = stoof[5];
	moveMaze.y = stoi(yer);

	fin.close();
	
	end = false;
}


void Maze::save(string filename, string filenametwo){
	ofstream saveFile;
	saveFile.open(filename);
	
	for(int i = 0; i < fileMaze.size(); ++i){
		saveFile << fileMaze[i] << endl;
	}
	saveFile.close();
	saveFile.open(filenametwo);
	saveFile  << life.size() << endl << bomb << endl << cash << endl;
	if(flashlight == true){
		saveFile << 1 << endl;
	}else if(flashlight == false){
		saveFile << 0 << endl;
	}
	saveFile << moveMaze.x << endl << moveMaze.y;
}

void Maze::generate(string mazeSize){

//Size Selection (Will be passed in via keypress)
vector<string> maze;
if(mazeSize == "Small"){
	vector<string> smallMap;
	for(int i = 0; i<=18; ++i){
		string smallString = "";
		for(int j = 0; j<=36; ++j){
            smallString += "#";
        }
        smallMap.push_back(smallString);
    }
maze = smallMap;
}

if(mazeSize == "Medium"){
	vector<string> mediumMap;
    for(int i = 0; i<=36; ++i){
	    string mediumString = "";
        for(int j = 0; j<=76; ++j){
            mediumString += "#";
        }
        mediumMap.push_back(mediumString);
    }
maze = mediumMap;
}

if(mazeSize == "Large"){
	vector<string> largeMap;
	for(int i = 0; i<=46; ++i){
        string largeString = "";
        for(int j = 0; j<=90; ++j){
            largeString += "#";
        }
        largeMap.push_back(largeString);
    }
maze = largeMap;
}



//Generation Code
	stack<Coord> revisit;
    Coord position = {1,1};
    revisit.push(position);
    maze[1][1] = '.';
    int randCheck = 0;
    Coord move = {0,0};
//Directions
    Coord up = {0,-2};
    Coord down = {0,2};
    Coord left = {-2,0};
    Coord right = {2,0};
    vector<Coord> possible;
	flashlight = false;

    while(revisit.size() > 0){
        while(possible.size() != 0){
            possible.pop_back();
        }
        //Move Up
        move = position + up;
        if(move.y > 0 && maze[move.y][move.x] == '#'){
            possible.push_back(move);
        }
        //Move Down
        move = position + down;
        if(move.y < maze.size()-1 && maze[move.y][move.x] == '#'){
            possible.push_back(move);
        }
        //Move Right
        move = position + right;
        if(move.x < maze[1].size() && maze[move.y][move.x] == '#'){
            possible.push_back(move);
        }
        //Move Left
        move = position + left;
        if(move.x > 0 && maze[move.y][move.x] == '#'){
            possible.push_back(move);
        }
        if(possible.size() != 0){
			int coinGen = rand()%30;   
			int trapGen = rand()%10;   
            revisit.push(position);
            randCheck = rand()%possible.size();
            Coord step;
            step.x = possible[randCheck].x-position.x;
            step.y = possible[randCheck].y-position.y;
            if(step.x == down.x && step.y == down.y){
				 if(coinGen > 20){														
					maze[position.y+step.y][position.x+step.x] = '$';
                    maze[position.y+1][position.x] = '.';
                    position = position + step;
				}else if(trapGen == 5 || trapGen == 8){
					maze[position.y+step.y][position.x+step.x] = '^';
				    maze[position.y+1][position.x] = '.';
                    position = position + step;
				}else{
			        maze[position.y+step.y][position.x+step.x] = '.';
                    maze[position.y+1][position.x] = '.';
                    position = position + step;
				}																
            }else if(step.x == up.x && step.y == up.y){
					maze[position.y+step.y][position.x+step.x] = '.';
					maze[position.y-1][position.x] = '.';
					position = position + step;
            }else if(step.x == right.x && step.y == right.y){
				maze[position.y+step.y][position.x+step.x] = '.';
				maze[position.y][position.x+1] = '.';
				position = position + step;
            }else if(step.x == left.x && step.y == left.y){
                maze[position.y+step.y][position.x+step.x] = '.';
                maze[position.y][position.x-1] = '.';
                position = position + step;
			}
        }
		//"Recursive Step"
        if(possible.size() == 0){
            position = revisit.top();
            revisit.pop();
        }
    }
	ofstream fout;
	fout.open("TEMP.txt");
	for(string str:maze){
		fout << str << endl;
	}
	fout.close();

	while(life.size() != 0){
        life.pop_back();
    }
	flashlight = false;
	moveMaze = {0,0};	
	end = false;

}

void Maze::shop(int x){			
	if(x == 1 && cash > 4){
		cash = cash - 5;
		bomb = bomb + 2;
	}
	if(x == 2 && cash > 9){
		cash = cash - 10;
		flashlight = true;
	}
}									




void Maze::move(Coord dir){
	if(moveMaze.x+dir.x == -1 || moveMaze.x+dir.x == fileMaze[0].size()-2 || moveMaze.y+dir.y == -1 || moveMaze.y+dir.y == fileMaze.size()-2){
	}else{
		if(fileMaze[moveMaze.y+dir.y+1][moveMaze.x+dir.x+1] != '#'){
				if(fileMaze[moveMaze.y+dir.y+1][moveMaze.x+dir.x+1] == '^'){
					life.pop_back();
					fileMaze[moveMaze.y+dir.y+1][moveMaze.x+dir.x+1] = '.';
				}else if(fileMaze[moveMaze.y+dir.y+1][moveMaze.x+dir.x+1] == '$'){
					cash = cash + 1;
					fileMaze[moveMaze.y+dir.y+1][moveMaze.x+dir.x+1] = '.';
				}else if(fileMaze[moveMaze.y+dir.y+1][moveMaze.x+dir.x+1] == 'F'){	
					end = true;
					fileMaze[moveMaze.y+dir.y+1][moveMaze.x+dir.x+1] = '.';
				}																
			moveMaze = moveMaze + dir;
			fileMaze[fileMaze.size()-4][fileMaze[0].size()-4] = 'F';

	}
}
	if(dir.x == 0 && dir.y == 0 && bomb > 0){								
		bomb = bomb - 1;
	if(moveMaze.y+dir.y+2 < fileMaze.size()-2 && fileMaze[moveMaze.y+dir.y+2][moveMaze.x+dir.x+1] != 'F'){
		fileMaze[moveMaze.y+dir.y+2][moveMaze.x+dir.x+1] = '.';	
	}
	if(moveMaze.x+dir.x+2 < fileMaze[0].size()-2 && fileMaze[moveMaze.y+dir.y+1][moveMaze.x+dir.x+2] != 'F'){
		fileMaze[moveMaze.y+dir.y+1][moveMaze.x+dir.x+2] = '.';
	}
	if(moveMaze.x+dir.x > fileMaze.size()-2 && fileMaze[moveMaze.y+dir.y+1][moveMaze.x+dir.x] != 'F'){
		fileMaze[moveMaze.y+dir.y+1][moveMaze.x+dir.x] = '.';
	}        
	if(moveMaze.y+dir.y > 0 && fileMaze[moveMaze.y+dir.y][moveMaze.x+dir.x+1] != 'F'){
		fileMaze[moveMaze.y+dir.y][moveMaze.x+dir.x+1] = '.';
	}
	}															
}




