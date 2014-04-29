/*
	Class which represents controls and displays the main menu
	
*/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <vector>

//Screen attributes
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 849;
const int SCREEN_BPP = 32;

using namespace std;

class Menu {
	public:
		Menu();
		SDL_Surface * load_image( std::string filename );
		void apply_surface(int, int, SDL_Surface*, SDL_Surface*, SDL_Rect*);
		bool init();
		bool load_files();
		void clean_up();
		int* go();

	private:
		vector <SDL_Surface *> players;
		vector <SDL_Surface *> levels;
		SDL_Surface *controlsScreen;
		SDL_Surface *menuScreen;
		SDL_Surface *screen;
		//The event structure
		SDL_Event event;
		int levelNum;
		int player1Num;
		int player2Num;
};

#endif
