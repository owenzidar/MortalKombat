#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <sstream>

using namespace std;

#ifndef TIMER_H
#define TIMER_H

//GLOBAL VARIABLES

//Screen dimensions and bits-per-pixel
const int screen_height = 849;
const int screen_width = 1200;
const int screen_bpp = 32;

SDL_Surface *background; //Background image, a Mortal Kombat landscape
SDL_Surface *winBackground;
SDL_Surface *screen; //The blank screen

SDL_Event event; //Used to check what events happen at the keyboard

//FUNCTIONS

//Load the image inputted to the function so it can be displayed later
SDL_Surface *load_image(string filename){
	SDL_Surface *loaded; //Loaded image
	SDL_Surface *optimized; //Pixel-optimized image
	
	loaded = IMG_Load(filename.c_str()); //Load the image

	//Change the background color for the loaded image so it doesn't show up
	Uint32 colorkey = SDL_MapRGB( loaded->format, 214, 214, 214 );
	SDL_SetColorKey( loaded, SDL_SRCCOLORKEY, colorkey );

	//Return the image
	return loaded; 
}

//Apply a loaded image to the screen at a certain place
void apply_surface(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect* clip = NULL){
	SDL_Rect offset;

	//Coordinates of where to place loaded image
	offset.x = x; 
	offset.y = y;
	
	//Display image to desired destination (most likely screen) at coordinates
	SDL_BlitSurface(source, clip, destination, &offset);
}

//Initialize the screen for SDL use
bool init(){
	//Initialize everything, return false if failed
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1){
		return false;
	}

	//Open up the screen with desired dimensions
	screen = SDL_SetVideoMode(screen_width, screen_height, screen_bpp, SDL_SWSURFACE);

	//Return if screen cannot open
	if(screen == NULL){
		return false;
	}

	SDL_WM_SetCaption("Mortal Kombat", NULL); //Set screen's title

	return true;
}

//Draws a filled-in rectangle on the screen
//This rectangle will be used to keep track of character's health
//Green bar = available health
//Dark red bar = health lost
//Code drawn from http://pbeblog.wordpress.com/2009/06/24/drawing-rectangles-sdl/
void FillRect(int x, int y, int w, int h, int color) {
	SDL_Rect health = {x,y,w,h}; // make a rectangle at (x,y) of length l and width w
	//Blit that rectangle onto the background filled in with color 
	SDL_FillRect(background, &health, color); 
}

//TIMER CLASS DEFINITION
//Timer class and implementation mostly drawn from lazyfoo.net 

class Timer{
    	public:
    		//Initializes variables
    		Timer();

		int getFRAMES_PER_SECOND();

    		//The various clock actions
    		void start();
    		void stop();
    		void pause();
    		void unpause();

    		//Gets the timer's time
    		int get_ticks();

    		//Checks the status of the timer
    		bool is_started();
    		bool is_paused();

	private:
    		int startTicks; //The clock time when the timer started
		int pausedTicks; //The ticks stored when the timer was paused
		bool paused; //true if timer is paused
		bool started; //true if timer is started
		int FRAMES_PER_SECOND; //desired numbers of frames for animation per second
};

//TIMER CLASS IMPLEMENTATION
//Timer class and implementation mostly drawn from lazyfoo.net

Timer::Timer(){
	//Initialize the variables
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
	FRAMES_PER_SECOND = 15;
}

int Timer::getFRAMES_PER_SECOND(){
	return FRAMES_PER_SECOND;
}

void Timer::start(){
    	//Start the timer
    	started = true;

    	//Unpause the timer
    	paused = false;

    	//Get the current clock time
    	startTicks = SDL_GetTicks();
}

void Timer::stop(){
    	//Stop the timer
    	started = false;

    	//Unpause the timer
    	paused = false;
}

void Timer::pause(){
    	//If the timer is running and isn't already paused
    	if( ( started == true ) && ( paused == false ) ){
        	//Pause the timer
        	paused = true;

        	//Calculate the paused ticks
        	pausedTicks = SDL_GetTicks() - startTicks;
    	}
}

void Timer::unpause(){
    	//If the timer is paused
    	if( paused == true ){
        	//Unpause the timer
        	paused = false;

        	//Reset the starting ticks
        	startTicks = SDL_GetTicks() - pausedTicks;

        	//Reset the paused ticks
        	pausedTicks = 0;
    	}
}

int Timer::get_ticks(){
    	//If the timer is running
    	if( started == true ){
        	//If the timer is paused
        	if( paused == true ){
            		//Return the number of ticks when the timer was paused
            		return pausedTicks;
        	}else{
            		//Return the current time minus the start time
            		return SDL_GetTicks() - startTicks;
        	}
    	}

    	//If the timer isn't running
    	return 0;
}

bool Timer::is_started(){
    	return started;
}

bool Timer::is_paused(){
    	return paused;
}

#endif
