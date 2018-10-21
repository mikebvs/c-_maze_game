#include "Coord.h"

Coord::Coord(){
	x = 0;
	y = 0;
}

Coord::Coord(int a,int b){
	x = a;
	y = b;
}

Coord Coord::operator+(const Coord& rhs){
	return Coord(x+rhs.x,y+rhs.y);
}

Coord Coord::operator-(const Coord& rhs){
	return Coord(x-rhs.x,y-rhs.y);
}

Coord Coord::operator/(int rhs){
	return Coord(x/rhs,y/rhs);
}

bool Coord::operator<(const Coord& rhs){
	return x < rhs.x && y < rhs.y;
}

bool Coord::operator>(const Coord& rhs){
	return x > rhs.x && y > rhs.y;
}

bool Coord::operator<=(const Coord& rhs){
	return x <= rhs.x && y <= rhs.y;
}

bool Coord::operator>=(const Coord& rhs){
	return x >= rhs.x && y >= rhs.y;
}

string Coord::asString(){
	stringstream sin;
	sin << "{" << x << "," << y << "}";
	return sin.str();
}

double Coord::distance(const Coord& rhs){
	double a = x-rhs.x;
	double b = y-rhs.y;
	return sqrt(a*a+b*b);
}

void Coord::abs(){
	x = std::abs(x);
	y = std::abs(y);	
}

void Coord::cap(const Coord& rhs){
	x = min(x,rhs.x);
	y = min(y,rhs.y);	
}

