/*
Kevin Epp, Mitch Patin, Owen Zidar  CSE 20212
Final Project  Menu.h
Header for Menu class, which displays main menu
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
		Menu(); //Constructor
		SDL_Surface * load_image( std::string filename ); //Load an image
		void apply_surface(int, int, SDL_Surface*, SDL_Surface*, SDL_Rect*); //Apply image to a surface
		bool init(); //Initialize SDL screen
		bool load_files(); //Load picture files
		void clean_up(); //Free everything
		int* go(); //Run the main menu

	private:
		vector <SDL_Surface *> players; //Vector containing images of all characters
		vector <SDL_Surface *> levels; //Vector containing images of all levels
		SDL_Surface *controlsScreen; //Images of the controls screen
		SDL_Surface *menuScreen; //Image of the menu screen
		SDL_Surface *screen; //The main SDL screen
		//The event structure
		SDL_Event event;
		int levelNum; //Current level choice
		int player1Num; //Current character choice for Player 1
		int player2Num; //Current character choice for Player 2
};

#endif
