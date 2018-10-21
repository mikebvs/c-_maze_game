#include "Console.h"

Console::Console(){
    blink = false;
    reverse = false;
    bold = false;
    pair = 0;
    canvas = NULL;
    update = true;
}

void Console::clearBuffer(){
	buffer = "";
}


bool Console::getLine(string& line){
    int c = wgetch(window);
    update = true;
    if(c == 8 || c == 127){
        if(buffer.size() > 0){
            buffer.erase(buffer.size()-1);
        }
    }else if(c == '\n' || c == '\r'){
        line = buffer;
        buffer = "";
        return true;
    }else if(iscntrl(c)){
        
    }else if(isprint(c)){
        buffer += c;
    }else{
        update = false;
    }
    line = buffer;
    return false;
}

bool Console::hasChanged(){
	return update;
}

void Console::redraw(){
    if(canvas == NULL)
        return;
    canvas->draw(this);
}

string Console::getBuffer(){
    return buffer;
}


int Console::getWidth(){
    int height,width;
    getmaxyx(window,height,width);
    return width;
}

int Console::getHeight(){
    int height,width;
    getmaxyx(window,height,width);
    return height;
}

void Console::clearGraphics(){
    clear();
}

void Console::drawString(int x,int y,string str){
    mvwaddstr(window,y,x,str.c_str());
}

void Console::setColor(string fg){
    int p = 0;
    if(fg== "BLACK"){
        p = 1;
    }else if(fg== "RED"){
        p = 2;
    }else if(fg== "GREEN"){
        p = 3;
    }else if(fg== "YELLOW"){
        p = 4;
    }else if(fg== "BLUE"){
        p = 5;
    }else if(fg== "MAGENTA"){
        p = 6;
    }else if(fg== "CYAN"){
        p = 7;
    }else if(fg== "WHITE"){
        p = 8;
    }
    if(pair != p){
        attroff(COLOR_PAIR(pair));
        pair = p;
        attron(COLOR_PAIR(pair));
    }
}

void Console::toggleAttribute(string attr){
    if(attr == "BLINK"){
        if(blink){
        attroff(A_BLINK);
        }else{
            attron(A_BLINK);
        }
        blink = !blink;
    }else if(attr == "BOLD"){
        if(bold){
            attroff(A_BOLD);
        }else{
            attron(A_BOLD);
        }
        bold = !bold;
    }else if(attr == "REVERSE"){
        if(reverse){
            attroff(A_REVERSE);
        }else{
            attron(A_REVERSE);
        }
        reverse = !reverse;
    }

}


void Console::initialize(){
    window = initscr();
    int height,width;
    getmaxyx(window,height,width);
    noecho();
    nodelay(window,true);
    curs_set(0);
    refresh();
    
    if(has_colors()){
        start_color();
        use_default_colors();
        init_pair(1, COLOR_BLACK  , -1);
        init_pair(2, COLOR_RED    , -1);
        init_pair(3, COLOR_GREEN  , -1);
        init_pair(4, COLOR_YELLOW , -1);
        init_pair(5, COLOR_BLUE   , -1);
        init_pair(6, COLOR_MAGENTA, -1);
        init_pair(7, COLOR_CYAN   , -1);
        init_pair(8, COLOR_WHITE  , -1);
        pair = 0;
    }
    
}

void Console::shutdown(){
    delwin(window);
    endwin();
    refresh();
}


