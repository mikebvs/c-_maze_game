#ifndef COORD__H
#define COORD__H

#include <sstream>
#include <cmath>
using namespace std;

class Coord{
	public:
		Coord();
		Coord(int a,int b);

		int x;
		int y;

		Coord operator+(const Coord& rhs);
		Coord operator-(const Coord& rhs);
		Coord operator/(int rhs);

		bool  operator<(const Coord& rhs);		
		bool  operator>(const Coord& rhs);
		bool  operator<=(const Coord& rhs);
		bool  operator>=(const Coord& rhs);

		string asString();

		double distance(const Coord& rhs);
		void abs();
		void cap(const Coord& rhs);

};

#endif
