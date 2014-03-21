/*
	Character base class for use with Mortal Komabat.
	
*/

#ifndef Package_H
#define Package_H

#include <iostream>

using namespace std;

class Character {
	public:
		Character(string n, int x, int y, double h, double w, double a, double l);
		void moveRight();
		void moveLeft();
		void highKick();
		void lowKick();
		void highPunch();
		void lowPunch();
		void block();
		void jump();		
		void specialAttack();		

	protected:
		string name;
		int posx;
		int posy;
		double height;
		double weight;
		double armreach;
		double legreach;
		
};

#endif
