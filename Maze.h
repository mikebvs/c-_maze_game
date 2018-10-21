#ifndef MAZE__H
#define MAZE__H

#include "Drawable.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "Coord.h"
#include <stack>
#include <iostream>
#include <string>
#include <vector>

class Maze: public Drawable{
	public:
		Maze();
		void draw(Graphics* window);
		void load(string filename, string filenametwo);
		void save(string filename, string filenametwo);
		void generate(string mazeSize);
		void move(Coord dir);
		void shop(int x);		
	private:
		vector<string> fileMaze;
		vector<string> GameOver; 
		vector<string> WinScreen; 
		Coord player;
		Coord moveMaze;
		vector<string> life;
		int pushes;
		int cash;
		int bomb;
		bool flashlight;
		bool end = false;	
		vector<string> filePrint;
};

#endif
