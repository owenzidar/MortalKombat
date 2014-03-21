/*
	Character base class for use with Mortal Komabat.
	
*/

#include <iostream>

#include "Character.h"

using namespace std;

// non-default constructor
Character :: Character(string n, int x, int y, double h, double w, double a, double l){
	name = n;
	posx = x;
	posy = y;
	height = h;
	weight = w;
	armreach = a;
	legreach = l;
}

// moves character right one pixel
void Character :: moveRight(){
	posx++;
}

// moves character right one pixel
void Character :: moveLeft(){
	posx--;
}
