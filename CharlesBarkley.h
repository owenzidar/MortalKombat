/*
Kevin Epp, Mitch Patin, Owen Zidar  CSE 20212
Final Project  CharlesBarkley.h
Derived class for CharlesBarkley object, inherits from Character.h
*/

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <sstream>

#include "Character.h"

using namespace std;

#ifndef CHARLESBARKLEY_H
#define CHARLESBARKLEY_H

class CharlesBarkley : public Character{
	public:
		CharlesBarkley(int = 400, int = 600, int = 1); //Constructor
		virtual void clipStand(); //Clip the sprite sheet for the character to stand
		virtual void clipWalk(); //Clip the sprite sheet for the character to walk
		virtual void clipPunch(); //Clip the sprite sheet for the character to punch
		virtual void clipKick(); //Clip the sprite sheet for the character to kick
		virtual void clipBlock(); //Clip the sprite sheet for the character to block
		virtual void clipDeath(); //Clip the sprite sheet for the character to die
		virtual void show(SDL_Surface*); //Show the character on desired surface

	private:
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
};

//Constructor, uses member initialization syntax to access Character constructor
CharlesBarkley::CharlesBarkley(int xcoord, int ycoord, int walk) : Character(xcoord, ycoord, walk){}

//Clip the sprites for the character to stand, facing either right or left
void CharlesBarkley::clipStand(){
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
void CharlesBarkley::clipWalk(){
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
void CharlesBarkley::clipPunch(){
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
void CharlesBarkley::clipKick(){
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
void CharlesBarkley::clipBlock(){
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
void CharlesBarkley::clipDeath(){
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

//Display the dot
void CharlesBarkley::show(SDL_Surface* destination){
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

#endif
