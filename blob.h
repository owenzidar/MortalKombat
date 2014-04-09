/*
Kevin Epp  CSE 20212
Lab9  blob.h
This program contains the functions that are used in main.cpp, the Blob class
definition, and the Blob class implementation.
It displays a dot on an SDL screen and performs various functions so that
Mortal Kombat can be implemented using this class and functions
*/

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <sstream>

using namespace std;

//GLOBAL VARIABLES

//Screen dimensions and bits-per-pixel
const int screen_height = 849;
const int screen_width = 1200;
const int screen_bpp = 32;

SDL_Surface *background; //Background image, a Mortal Kombat landscape
SDL_Surface *screen; //The blank screen

SDL_Event event; //Used to check what events happen at the keyboard

SDL_Rect standRight[7]; //Sprite clippings for standing facing right
SDL_Rect standLeft[7]; //Sprite clippings for standing facing left
SDL_Rect walkRight[9]; //Sprite clippings for walking facing right
SDL_Rect walkLeft[9]; //Sprite clippings for walking facing left
SDL_Rect punchRight[5]; //Sprite clippings for punching facing right
SDL_Rect punchLeft[5]; //Sprite clippings for punching facing left
SDL_Rect kickRight[9]; //Sprite clippings for kicking facing right
SDL_Rect kickLeft[9]; //Sprite clippings for kicking facing left
SDL_Rect blockRight[3]; //Sprite clippings for blocking facing right
SDL_Rect blockLeft[3]; //Sprite clippings for blocking facing left
SDL_Rect deadRight[7]; //Sprite clippings for dying facing right
SDL_Rect deadLeft[7]; //Sprite clippings for dying facing left

//FUNCTIONS

//Load the image inputted to the function so it can be displayed later
SDL_Surface *load_image(string filename){
	SDL_Surface *loaded; //Loaded image
	SDL_Surface *optimized; //Pixel-optimized image
	
	loaded = IMG_Load(filename.c_str()); //Load the image

	optimized = SDL_DisplayFormat(loaded); //Optimize the image
	SDL_FreeSurface(loaded); //Free the loaded image to avoid memory leak

	//Change the background color for the loaded image so it doesn't show up
	Uint32 colorkey = SDL_MapRGB( optimized->format, 214, 214, 214 );
	SDL_SetColorKey( optimized, SDL_SRCCOLORKEY, colorkey );

	//Return optimized image
	return optimized;
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

//BLOB CLASS DEFINITION

class Blob{
	public:
		Blob(int = 400, int = 450, int = 1); //Constructor
		void input1(Blob &); //Make the desired move according to key pressed (Character 1)
		void input2(Blob &); //Make the desired move according to key pressed (Character 2)
		void move1(Blob &); //Move the character
		void move2(Blob &); //Move the character	
		void show(SDL_Surface*); //Show the character on desired surface
		void free(); //Free the character's space in memory
		void show_health(int, int); //Display the current character's health bar using FillRect
		void punch(Blob &); //Punch the opposing character, if close enough
		void kick(Blob &); //Kick the opposing character, if close enough
		int isDone(); //Check to see if the game is over
		void clipStand(); //Clip the sprite sheet for the character to stand
		void clipWalk(); //Clip the sprite sheet for the character to walk
		void clipPunch(); //Clip the sprite sheet for the character to punch
		void clipKick(); //Clip the sprite sheet for the character to kick
		void clipBlock(); //Clip the sprite sheet for the character to block
		void clipDeath(); //Clip the sprite sheet for the character to die
		void setStatus(int); //Set the status of the character
		void setFrame(int); //Set the current frame for animation

	private:
		int x; //x-coordinate
		int y; //y-coordinate
		int xVel; // x velocity
		int yVel; //y velocity
		int health; //Current health remaining of the character (out of 100)
		int block; //If the user is attempting to block
		SDL_Surface *image; //Image of the character
		int change; //If there is a change in action; this will trigger a reset of frame to 0
		int status; //Current status of the character, tells the program what set of sprites to animate
		int frame; //Current frame for animation, number of frames varies by action
		int walkWay; //Which way the character is facing (right = 1, left = 0)
		int punchkickblock; //Is 1 is the character is punching, kicking, or blocking
		//The following five variables are used to verify that the user can only do one action at a time
		int pressed1; //If the character is moving left
		int pressed2; //If the character is moving right
		int pressed3; //If the character is punching
		int pressed4; //If the character is kicking
		int pressed5; //If the character is blocking
};

//BLOB CLASS IMPLEMENTATION

//Initialize dot
Blob::Blob(int xcoord, int ycoord, int walk){
	x = xcoord; //x-coordinate
	y = ycoord; //y-coordinate
	walkWay = walk; //Which way character is facing, 1 for right and 0 for left
	xVel = 0; //x velocity
	yVel = 0; //y velocity
	image = load_image("CharlesBarkley.png"); //Load image of the dot
	health = 100; //Initialize character health to 100
	block = 0; //Initialize character to not blocking
	status = 0; //Initialize animation to character standing around
	frame = 0; //Initial frame for animation
	punchkickblock = 0; //Character is not attacking or blocking
	//No keys are pressed initially for the character
	pressed1 = 0;
	pressed2 = 0;
	pressed3 = 0;
	pressed4 = 0;
	pressed5 = 0;
}
//Clip the sprites for the character to stand, facing either right or left
void Blob::clipStand(){
	standRight[ 0 ].x = 0; 
	standRight[ 0 ].y = 0; 
	standRight[ 0 ].w = 77; 
	standRight[ 0 ].h = 200;

	standRight[ 1 ].x = 77; 
	standRight[ 1 ].y = 0; 
	standRight[ 1 ].w = 80; 
	standRight[ 1 ].h = 200;

	standRight[ 2 ].x = 157; 
	standRight[ 2 ].y = 0; 
	standRight[ 2 ].w = 85; 
	standRight[ 2 ].h = 200;

	standRight[ 3 ].x = 242; 
	standRight[ 3 ].y = 0; 
	standRight[ 3 ].w = 87; 
	standRight[ 3 ].h = 200;

	standRight[ 4 ].x = 329; 
	standRight[ 4 ].y = 0; 
	standRight[ 4 ].w = 83; 
	standRight[ 4 ].h = 200;

	standRight[ 5 ].x = 412; 
	standRight[ 5 ].y = 0; 
	standRight[ 5 ].w = 77; 
	standRight[ 5 ].h = 200;

	standRight[ 6 ].x = 489; 
	standRight[ 6 ].y = 0; 
	standRight[ 6 ].w = 75; 
	standRight[ 6 ].h = 200;

	standLeft[ 0 ].x = 0; 
	standLeft[ 0 ].y = 3051; 
	standLeft[ 0 ].w = 77; 
	standLeft[ 0 ].h = 200;

	standLeft[ 1 ].x = 77; 
	standLeft[ 1 ].y = 3051; 
	standLeft[ 1 ].w = 80; 
	standLeft[ 1 ].h = 200;

	standLeft[ 2 ].x = 157; 
	standLeft[ 2 ].y = 3051; 
	standLeft[ 2 ].w = 85; 
	standLeft[ 2 ].h = 200;

	standLeft[ 3 ].x = 242; 
	standLeft[ 3 ].y = 3051; 
	standLeft[ 3 ].w = 87; 
	standLeft[ 3 ].h = 200;

	standLeft[ 4 ].x = 329; 
	standLeft[ 4 ].y = 3051; 
	standLeft[ 4 ].w = 83; 
	standLeft[ 4 ].h = 200;

	standLeft[ 5 ].x = 412; 
	standLeft[ 5 ].y = 3051; 
	standLeft[ 5 ].w = 77; 
	standLeft[ 5 ].h = 200;

	standLeft[ 6 ].x = 489; 
	standLeft[ 6 ].y = 3051; 
	standLeft[ 6 ].w = 75; 
	standLeft[ 6 ].h = 200;


}

//Clip the sprites for the character to walk, facing either right or left
void Blob::clipWalk(){
	walkRight[ 0 ].x = 0; 
	walkRight[ 0 ].y = 200; 
	walkRight[ 0 ].w = 78; 
	walkRight[ 0 ].h = 200;

	walkRight[ 1 ].x = 78; 
	walkRight[ 1 ].y = 200; 
	walkRight[ 1 ].w = 76; 
	walkRight[ 1 ].h = 200;

	walkRight[ 2 ].x = 154; 
	walkRight[ 2 ].y = 200; 
	walkRight[ 2 ].w = 75; 
	walkRight[ 2 ].h = 200;

	walkRight[ 3 ].x = 229; 
	walkRight[ 3 ].y = 200; 
	walkRight[ 3 ].w = 76; 
	walkRight[ 3 ].h = 200;

	walkRight[ 4 ].x = 305; 
	walkRight[ 4 ].y = 200; 
	walkRight[ 4 ].w = 76; 
	walkRight[ 4 ].h = 200;

	walkRight[ 5 ].x = 381; 
	walkRight[ 5 ].y = 200; 
	walkRight[ 5 ].w = 75; 
	walkRight[ 5 ].h = 200;

	walkRight[ 6 ].x = 456; 
	walkRight[ 6 ].y = 200; 
	walkRight[ 6 ].w = 76; 
	walkRight[ 6 ].h = 200;

	walkRight[ 7 ].x = 532; 
	walkRight[ 7 ].y = 200; 
	walkRight[ 7 ].w = 77; 
	walkRight[ 7 ].h = 200;

	walkRight[ 8 ].x = 609; 
	walkRight[ 8 ].y = 200; 
	walkRight[ 8 ].w = 77; 
	walkRight[ 8 ].h = 200;

	walkLeft[ 0 ].x = 0; 
	walkLeft[ 0 ].y = 3251; 
	walkLeft[ 0 ].w = 78; 
	walkLeft[ 0 ].h = 200;

	walkLeft[ 1 ].x = 78; 
	walkLeft[ 1 ].y = 3251; 
	walkLeft[ 1 ].w = 76; 
	walkLeft[ 1 ].h = 200;

	walkLeft[ 2 ].x = 154; 
	walkLeft[ 2 ].y = 3251; 
	walkLeft[ 2 ].w = 75; 
	walkLeft[ 2 ].h = 200;

	walkLeft[ 3 ].x = 229; 
	walkLeft[ 3 ].y = 3251; 
	walkLeft[ 3 ].w = 76; 
	walkLeft[ 3 ].h = 200;

	walkLeft[ 4 ].x = 305; 
	walkLeft[ 4 ].y = 3251; 
	walkLeft[ 4 ].w = 76; 
	walkLeft[ 4 ].h = 200;

	walkLeft[ 5 ].x = 381; 
	walkLeft[ 5 ].y = 3251; 
	walkLeft[ 5 ].w = 75; 
	walkLeft[ 5 ].h = 200;

	walkLeft[ 6 ].x = 456; 
	walkLeft[ 6 ].y = 3251; 
	walkLeft[ 6 ].w = 76; 
	walkLeft[ 6 ].h = 200;

	walkLeft[ 7 ].x = 532; 
	walkLeft[ 7 ].y = 3251; 
	walkLeft[ 7 ].w = 77; 
	walkLeft[ 7 ].h = 200;

	walkLeft[ 8 ].x = 625; 
	walkLeft[ 8 ].y = 3251; 
	walkLeft[ 8 ].w = 77; 
	walkLeft[ 8 ].h = 200;

	
}

//Clip the sprites for the character to punch, facing either right or left
void Blob::clipPunch(){
	punchRight[ 0 ].x = 0; 
	punchRight[ 0 ].y = 1093; 
	punchRight[ 0 ].w = 88; 
	punchRight[ 0 ].h = 199;

	punchRight[ 1 ].x = 88; 
	punchRight[ 1 ].y = 1093; 
	punchRight[ 1 ].w = 114; 
	punchRight[ 1 ].h = 199;

	punchRight[ 2 ].x = 202; 
	punchRight[ 2 ].y = 1093; 
	punchRight[ 2 ].w = 150; 
	punchRight[ 2 ].h = 199;

	punchRight[ 3 ].x = 352; 
	punchRight[ 3 ].y = 1093; 
	punchRight[ 3 ].w = 118; 
	punchRight[ 3 ].h = 199;

	punchRight[ 4 ].x = 470; 
	punchRight[ 4 ].y = 1093; 
	punchRight[ 4 ].w = 119; 
	punchRight[ 4 ].h = 199;

	punchLeft[ 0 ].x = 0; 
	punchLeft[ 0 ].y = 4144; 
	punchLeft[ 0 ].w = 88; 
	punchLeft[ 0 ].h = 199;

	punchLeft[ 1 ].x = 88; 
	punchLeft[ 1 ].y = 4144; 
	punchLeft[ 1 ].w = 114; 
	punchLeft[ 1 ].h = 199;

	punchLeft[ 2 ].x = 202; 
	punchLeft[ 2 ].y = 4144; 
	punchLeft[ 2 ].w = 150; 
	punchLeft[ 2 ].h = 199;

	punchLeft[ 3 ].x = 352; 
	punchLeft[ 3 ].y = 4144; 
	punchLeft[ 3 ].w = 118; 
	punchLeft[ 3 ].h = 199;

	punchLeft[ 4 ].x = 470; 
	punchLeft[ 4 ].y = 4144; 
	punchLeft[ 4 ].w = 119; 
	punchLeft[ 4 ].h = 199;
}

//Clip the sprites for the character to kick, facing either right or left
void Blob::clipKick(){
	kickRight[ 0 ].x = 0; 
	kickRight[ 0 ].y = 1764; 
	kickRight[ 0 ].w = 109; 
	kickRight[ 0 ].h = 186;	

	kickRight[ 1 ].x = 109; 
	kickRight[ 1 ].y = 1764; 
	kickRight[ 1 ].w = 93; 
	kickRight[ 1 ].h = 186;	

	kickRight[ 2 ].x = 202; 
	kickRight[ 2 ].y = 1764; 
	kickRight[ 2 ].w = 93; 
	kickRight[ 2 ].h = 186;	

	kickRight[ 3 ].x = 295; 
	kickRight[ 3 ].y = 1764; 
	kickRight[ 3 ].w = 127; 
	kickRight[ 3 ].h = 186;	

	kickRight[ 4 ].x = 422; 
	kickRight[ 4 ].y = 1764; 
	kickRight[ 4 ].w = 139; 
	kickRight[ 4 ].h = 186;	

	kickRight[ 5 ].x = 561; 
	kickRight[ 5 ].y = 1764; 
	kickRight[ 5 ].w = 142; 
	kickRight[ 5 ].h = 186;	

	kickRight[ 6 ].x = 703; 
	kickRight[ 6 ].y = 1764; 
	kickRight[ 6 ].w = 133; 
	kickRight[ 6 ].h = 186;	

	kickRight[ 7 ].x = 836; 
	kickRight[ 7 ].y = 1764; 
	kickRight[ 7 ].w = 100; 
	kickRight[ 7 ].h = 186;	

	kickRight[ 8 ].x = 936; 
	kickRight[ 8 ].y = 1764; 
	kickRight[ 8 ].w = 62; 
	kickRight[ 8 ].h = 186;	

	kickLeft[ 0 ].x = 0; 
	kickLeft[ 0 ].y = 4815; 
	kickLeft[ 0 ].w = 109; 
	kickLeft[ 0 ].h = 186;	

	kickLeft[ 1 ].x = 109; 
	kickLeft[ 1 ].y = 4815; 
	kickLeft[ 1 ].w = 93; 
	kickLeft[ 1 ].h = 186;	

	kickLeft[ 2 ].x = 202; 
	kickLeft[ 2 ].y = 4815; 
	kickLeft[ 2 ].w = 93; 
	kickLeft[ 2 ].h = 186;	

	kickLeft[ 3 ].x = 295; 
	kickLeft[ 3 ].y = 4815; 
	kickLeft[ 3 ].w = 127; 
	kickLeft[ 3 ].h = 186;	

	kickLeft[ 4 ].x = 422; 
	kickLeft[ 4 ].y = 4815; 
	kickLeft[ 4 ].w = 139; 
	kickLeft[ 4 ].h = 186;	

	kickLeft[ 5 ].x = 561; 
	kickLeft[ 5 ].y = 4815; 
	kickLeft[ 5 ].w = 142; 
	kickLeft[ 5 ].h = 186;	

	kickLeft[ 6 ].x = 703; 
	kickLeft[ 6 ].y = 4815; 
	kickLeft[ 6 ].w = 133; 
	kickLeft[ 6 ].h = 186;	

	kickLeft[ 7 ].x = 836; 
	kickLeft[ 7 ].y = 4815; 
	kickLeft[ 7 ].w = 100; 
	kickLeft[ 7 ].h = 186;	

	kickLeft[ 8 ].x = 936; 
	kickLeft[ 8 ].y = 4815; 
	kickLeft[ 8 ].w = 62; 
	kickLeft[ 8 ].h = 186;
}

//Clip the sprites for the character to block, facing either right or left
void Blob::clipBlock(){
	blockRight[ 0 ].x = 0; 
	blockRight[ 0 ].y = 2553; 
	blockRight[ 0 ].w = 85; 
	blockRight[ 0 ].h = 184;

	blockRight[ 1 ].x = 85; 
	blockRight[ 1 ].y = 2553; 
	blockRight[ 1 ].w = 78; 
	blockRight[ 1 ].h = 184;

	blockRight[ 2 ].x = 163; 
	blockRight[ 2 ].y = 2553; 
	blockRight[ 2 ].w = 81; 
	blockRight[ 2 ].h = 184;

	blockLeft[ 0 ].x = 0; 
	blockLeft[ 0 ].y = 5604; 
	blockLeft[ 0 ].w = 85; 
	blockLeft[ 0 ].h = 184;

	blockLeft[ 1 ].x = 85; 
	blockLeft[ 1 ].y = 5604; 
	blockLeft[ 1 ].w = 78; 
	blockLeft[ 1 ].h = 184;

	blockLeft[ 2 ].x = 163; 
	blockLeft[ 2 ].y = 5604; 
	blockLeft[ 2 ].w = 81; 
	blockLeft[ 2 ].h = 184;
}

//Clip the sprites for the character to die, facing either right or left
void Blob::clipDeath(){
	deadRight[ 0 ].x = 0; 
	deadRight[ 0 ].y = 5926; 
	deadRight[ 0 ].w = 80; 
	deadRight[ 0 ].h = 176;

	deadRight[ 1 ].x = 80; 
	deadRight[ 1 ].y = 5926; 
	deadRight[ 1 ].w = 125; 
	deadRight[ 1 ].h = 176;

	deadRight[ 2 ].x = 205; 
	deadRight[ 2 ].y = 5926; 
	deadRight[ 2 ].w = 173; 
	deadRight[ 2 ].h = 176;

	deadRight[ 3 ].x = 378; 
	deadRight[ 3 ].y = 5926; 
	deadRight[ 3 ].w = 147; 
	deadRight[ 3 ].h = 176;

	deadRight[ 4 ].x = 525; 
	deadRight[ 4 ].y = 5926; 
	deadRight[ 4 ].w = 139; 
	deadRight[ 4 ].h = 176;

	deadRight[ 5 ].x = 664; 
	deadRight[ 5 ].y = 5926; 
	deadRight[ 5 ].w = 171; 
	deadRight[ 5 ].h = 176;

	deadRight[ 6 ].x = 835; 
	deadRight[ 6 ].y = 5926; 
	deadRight[ 6 ].w = 189; 
	deadRight[ 6 ].h = 176;

	deadLeft[ 0 ].x = 0; 
	deadLeft[ 0 ].y = 2875; 
	deadLeft[ 0 ].w = 80; 
	deadLeft[ 0 ].h = 176;

	deadLeft[ 1 ].x = 80; 
	deadLeft[ 1 ].y = 2875; 
	deadLeft[ 1 ].w = 125; 
	deadLeft[ 1 ].h = 176;

	deadLeft[ 2 ].x = 205; 
	deadLeft[ 2 ].y = 2875; 
	deadLeft[ 2 ].w = 173; 
	deadLeft[ 2 ].h = 176;

	deadLeft[ 3 ].x = 378; 
	deadLeft[ 3 ].y = 2875; 
	deadLeft[ 3 ].w = 147; 
	deadLeft[ 3 ].h = 176;

	deadLeft[ 4 ].x = 525; 
	deadLeft[ 4 ].y = 2875; 
	deadLeft[ 4 ].w = 139; 
	deadLeft[ 4 ].h = 176;

	deadLeft[ 5 ].x = 664; 
	deadLeft[ 5 ].y = 2875; 
	deadLeft[ 5 ].w = 171; 
	deadLeft[ 5 ].h = 176;

	deadLeft[ 6 ].x = 835; 
	deadLeft[ 6 ].y = 2875; 
	deadLeft[ 6 ].w = 189; 
	deadLeft[ 6 ].h = 176;
}

//Make a desired move for Character 1
void Blob::input1(Blob &otherDot){
	//If key was pressed and no other keys are currently pressed
	if(event.type == SDL_KEYDOWN && (pressed1 == 0) && (pressed2 == 0) && (pressed3 == 0) && (pressed4 == 0) && (pressed5 == 0)){ 
		switch(event.key.keysym.sym){
			case SDLK_s: //If s was pressed
				xVel += 5; //increase character velocity to the right
				punchkickblock = 0; //Not attacking or blocking
				change = 1; //Reset frame to 0
				pressed1 = 1; //Change key's status to pressed
				break;
			case SDLK_a: //If a was pressed
				xVel -= 5; //increase character velocity to the left
				punchkickblock = 0;
				change = 1;
				pressed2 = 1;
				break;
			case SDLK_q: //If q was pressed
				punch(otherDot); //Invoke punch function to punch other character
				punchkickblock = 1; //Punching
				change = 1;
				pressed3 = 1;
				break;
			case SDLK_w: //If w was pressed
				kick(otherDot); //Invoke kick function to kick other character
				punchkickblock = 2; //Kicking
				change = 1;
				pressed4 = 1;
				break;
			case SDLK_e: //If e was pressed
				block = 1; //Set blockP to 1 (character is attempting to block punch)
				punchkickblock = 3; //Blocking
				change = 1;
				pressed5 = 1;
				break;
		}
	}else if(event.type == SDL_KEYUP){
		switch( event.key.keysym.sym ){
			case SDLK_s: //If s was released
				if(pressed1 == 1) //If key was pressed
					xVel -= 5; //Make x velocity 0 again
				pressed1 = 0; //Reset pressed to released status
				break;
			case SDLK_a: //If a was released
				if(pressed2 == 1)
					xVel += 5; //Make x velocity 0 again
				pressed2 = 0;
				break;
			case SDLK_q: //If q was released
				pressed3 = 0;
				break;
			case SDLK_w: //If w was released
				pressed4 = 0;
				break;
			case SDLK_e: //If e was released
				if(pressed5 == 1){
					block = 0; //Set block to 0 (character is not attempting to block attack)
					punchkickblock = 0; //Not attacking or blocking
				}
				pressed5 = 0;
				break;
		}
	}
}

//Make a desired move for Character 2
void Blob::input2(Blob &otherDot){
	//If key was pressed and no other keys are currently pressed
	if(event.type == SDL_KEYDOWN && (pressed1 == 0) && (pressed2 == 0) && (pressed3 == 0) && (pressed4 == 0) && (pressed5 == 0)){ 
		switch(event.key.keysym.sym){
			case SDLK_k: //If k was pressed
				xVel += 5; //increase character velocity to the right
				punchkickblock = 0; //Not attacking or blocking
				change = 1; //Reset frame to 0
				pressed1 = 1; //Change key's status to pressed
				break;
			case SDLK_j: //If j was pressed
				xVel -= 5; //increase character velocity to the left
				punchkickblock = 0;
				change = 1;
				pressed2 = 1;
				break;
			case SDLK_u: //If u was pressed
				punch(otherDot); //Invoke punch function to punch other character
				punchkickblock = 1; //Punching
				change = 1;
				pressed3 = 1;
				break;
			case SDLK_i: //If i was pressed
				kick(otherDot); //Invoke kick function to kick other character
				punchkickblock = 2; //Kicking
				change = 1;
				pressed4 = 1;
				break;
			case SDLK_o: //If o was pressed
				block = 1; //Set block to 1 (character is attempting to block punch)
				punchkickblock = 3; //Blocking
  				change = 1;
				pressed5 = 1;
				break;
		}
	}else if(event.type == SDL_KEYUP){
		switch( event.key.keysym.sym ){
			case SDLK_k: //If k was released
				if(pressed1 == 1)
					xVel -= 5; //Make x velocity 0 again
				pressed1 = 0;
				break;
			case SDLK_j: //If j was released
				if(pressed2 == 1)
					xVel += 5; //Make x velocity 0 again
				pressed2 = 0;
				break;
			case SDLK_u: //If u was released
				pressed3 = 0;
				break;
			case SDLK_i: //If i was released
				pressed4 = 0;
				break;
			case SDLK_o: //If o was released
				if(pressed5 == 1){
					block = 0; //Set block to 0 (character is not attempting to block attack)
					punchkickblock = 0; //Not attacking or blocking
				}
				pressed5 = 0;
				break;
		}
	}
}

//Move character 1 based on its velocity
void Blob::move1(Blob &otherDot){
	//If moving to the right
	if(xVel > 0){
		//If within screen boundary and not colliding with other player
		if(x <= screen_width - 100 && x <= (otherDot.x - 80)){
			x +=xVel; //Move character's position
		}
	}

	//If moving to the left
	if(xVel < 0){
		//If within screen boundary
		if(x >= 0){
			x += xVel; //Move character's position
		}
	}
}	

//Move character 2 based on its velocity
void Blob::move2(Blob &otherDot){
	//If moving to the right
	if(xVel > 0){
		//If within screen boundary
		if(x <= screen_width - 100){
			x +=xVel; //Move character's position
		}
	}

	//If moving left
	if(xVel < 0){
		//If within screen boundary and not colliding with other player
		if(x >= 0 && x >= (otherDot.x + 80)){
			x += xVel; //Move character's position
		}
	}
}

//Display the health bar for the character
//Avaible health is displayed as green while depleted health is dark red
void Blob::show_health(int x, int y){
	//Draw a rectangle whose length is 4 times the character's health (for better visability)
	//and width is 30 at (x,y) with a light green color (HEX: 1FEB11)
	FillRect(x, y, health*4, 30, 0x1FEB11); 
	
	if(health < 100){ //If character is not at full health

		//Draw the remainder of the rectangle with a dark red color (HEX: 660000)
		FillRect(x + health*4, y, (400 - (health*4)), 30, 0x660000);
	}
}

//Punch the other character and deplete their health if no more than 100 pixels away
void Blob::punch(Blob &otherDot){
	//If facing right
	if(walkWay == 1){
		//If other dot within 100 pixels to the right and is not blocking left
		if((x >= (otherDot.x - 100)) && (x <= (otherDot.x)) && (otherDot.block == 0 || otherDot.walkWay == walkWay)){ 
											    	  
			if(otherDot.health > 0){ //If the other character still has health left
	
				if(otherDot.health <= 3){ //If the other character cannot take a full punch
					otherDot.health = 0; //Set other character's health to 0
				}else{ //Other character can take a full punch
					otherDot.health = otherDot.health - 3; //Take 3 health away from other character
				}
			}
		}
	//If facing left
	}else{
		//If other dot within 100 pixels to the left and is not blocking right
		if((x >= (otherDot.x)) && (x <= (otherDot.x + 100)) && (otherDot.block == 0 || otherDot.walkWay == walkWay)){ 
											    	   
			if(otherDot.health > 0){ //If the other character still has health left
	
				if(otherDot.health <= 3){ //If the other character cannot take a full punch
					otherDot.health = 0; //Set other character's health to 0
				}else{ //Other character can take a full punch
					otherDot.health = otherDot.health - 3; //Take 3 health away from other character
				}
			}
		}
	}	
}

//Kick the other character and deplete their health if no more than 100 pixels away
void Blob::kick(Blob &otherDot){
	//If facing right
	if(walkWay == 1){
		//If other dot within 100 pixels to the right and is not blocking left
		if((x >= (otherDot.x - 100)) && (x <= (otherDot.x)) && (otherDot.block == 0 || otherDot.walkWay == walkWay)){ 
											    	  
			if(otherDot.health > 0){ //If the other character still has health left
	
				if(otherDot.health <= 5){ //If the other character cannot take a full kick
					otherDot.health = 0; //Set other character's health to 0
				}else{ //Other character can take a full kick
					otherDot.health = otherDot.health - 5; //Take 5 health away from other character
				}
			}
		}
	//If facing left
	}else{
		//If other dot within 100 pixels to the left and is not blocking right
		if((x >= (otherDot.x)) && (x <= (otherDot.x + 100)) && (otherDot.block == 0 || otherDot.walkWay == walkWay)){ 
											    	   
			if(otherDot.health > 0){ //If the other character still has health left
	
				if(otherDot.health <= 5){ //If the other character cannot take a full kick
					otherDot.health = 0; //Set other character's health to 0
				}else{ //Other character can take a full kick
					otherDot.health = otherDot.health - 5; //Take 5 health away from other character
				}
			}
		}
	}
}

//Display the dot
void Blob::show(SDL_Surface* destination){
	//If character's status is not dead
	if(status != 5){
		//If new action to animate	
		if(change == 1){
			frame = 0; //Reset frame to 0
		}
	
		//If not kicking, punching, or blocking
		if(punchkickblock == 0){
			//If moving right	
			if(xVel > 0){
				status = 1;
				walkWay = 1; //Facing right
				frame++; //Increment frame for animation
			//If standing still
			}else if(xVel == 0){			
				status = 0;
				frame++;
			//If moving left
			}else if(xVel < 0){
				status = -1;
				walkWay = 0; //Facing left
				frame++;
			}
		//If punching
		}else if(punchkickblock == 1){
			status = 2;
			frame++;
		//If kicking
		}else if(punchkickblock == 2){
			status = 3;
			frame++;
		//If blocking
		}else if(punchkickblock == 3){
			status = 4;
			frame++;
		}
	
		//If standing and sprite frames are done, reset frame to 0 to loop animation
		if(status == 0 && frame >= 7){
			frame = 0;
		}
	
		//If moving right and sprite frames are done, reset frame to 0 to loop animation
		if(status == 1 && frame >= 9){
			frame = 0;
		}
	
		//If moving left and sprite frames are done, reset frame to 0 to loop animation
		if(status == -1 && frame >= 9){
			frame = 0;
		}

		//If punching and sprite frames are done, reset frame to 0 and set punchkickblock to 0 to stop animation
		//after one loop
		if(status == 2 && frame >= 5){
			punchkickblock = 0;
			frame = 0;
		}
	
		//If kicking and sprite frames are done, reset frame to 0 and set punchkickblock to 0 to stop animation
		//after one loop
		if(status == 3 && frame >= 9){
			punchkickblock = 0;
			frame = 0;
		}

		//If blocking and sprite frames are done, reset frame to 2 and hold it to animate holding block
		if(status == 4 && frame >=3){
			frame = 2;
		}		
	
		//If standing
		if(status == 0){
			if(walkWay == 1) //If facing right
				apply_surface(x,y,image, destination, &standRight[ frame ]); //Apply appropriate sprite clips
			if(walkWay == 0) //If facing left
				apply_surface(x,y,image, destination, &standLeft[ frame ]);
		//If moving right
		}else if(status == 1){
			apply_surface(x,y,image, destination, &walkRight [ frame ]);
		//If moving left
		}else if(status == -1){
			apply_surface(x,y,image, destination, &walkLeft [ frame ]);
		//If punching
		}else if(status == 2){
			if(walkWay == 1)
				apply_surface(x,y,image, destination, &punchRight[ frame ]);
			if(walkWay == 0)
				apply_surface(x,y,image, destination, &punchLeft[ frame ]);
		//If kicking
		}else if(status == 3){
			if(walkWay == 1)
				apply_surface(x,y,image, destination, &kickRight[ frame ]);
			if(walkWay == 0)
				apply_surface(x,y,image, destination, &kickLeft[ frame ]);
		//If blocking
		}else if(status == 4){
			if(walkWay == 1)
				apply_surface(x,y,image, destination, &blockRight[ frame ]);
			if(walkWay == 0)
				apply_surface(x,y,image, destination, &blockLeft[ frame ]);
		}
	
		change = 0; //Reset change so frame doesn't keep resetting to 0 prematurely
	//Character's status is dead (5)
	}else{
		if(walkWay == 1) //If facing right
				apply_surface(x,y,image, destination, &deadRight[ frame ]); //Apply appropriate sprite clip
		if(walkWay == 0) //If facing left
				apply_surface(x,y,image, destination, &deadLeft[ frame ]);

		frame++; //Increment frame
	}
}

//Set the character's status
void Blob::setStatus(int userStatus){
	status = userStatus;
}

//Set the current frame for animation
void Blob::setFrame(int userFrame){
	frame = userFrame;
}

//Free the dot in memory
void Blob::free(){
	SDL_FreeSurface(image);
}

//Check if game is over (i.e someone has run out of health)
int Blob::isDone(){
	if(health <= 0){ //If character's health is depleted
		return 1; //Game is over
	}
	return 0; //Otherwise, game is not over
}
