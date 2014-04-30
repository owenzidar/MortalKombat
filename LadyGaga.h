/*
Kevin Epp, Mitch Patin, Owen Zidar  CSE 20212
Final Project  LadyGaga.h
Derived class for LadyGaga object, inherits from Character.h
*/

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <sstream>

#include "Character.h"

using namespace std;

#ifndef LADYGAGA_H
#define LADYGAGA_H

class LadyGaga : public Character{
	public:
		LadyGaga(int = 400, int = 600, int = 1); //Constructor
		virtual void clipStand(); //Clip the sprite sheet for the character to stand
		virtual void clipWalk(); //Clip the sprite sheet for the character to walk
		virtual void clipPunch(); //Clip the sprite sheet for the character to punch
		virtual void clipKick(); //Clip the sprite sheet for the character to kick
		virtual void clipBlock(); //Clip the sprite sheet for the character to block
		virtual void clipDeath(); //Clip the sprite sheet for the character to die
		virtual void show(SDL_Surface*); //Show the character on desired surface

	private:
		SDL_Rect standRight[9]; //Sprite clippings for standing facing right
		SDL_Rect standLeft[9]; //Sprite clippings for standing facing left
		SDL_Rect walkRight[9]; //Sprite clippings for walking facing right
		SDL_Rect walkLeft[9]; //Sprite clippings for walking facing left
		SDL_Rect punchRight[5]; //Sprite clippings for punching facing right
		SDL_Rect punchLeft[5]; //Sprite clippings for punching facing left
		SDL_Rect kickRight[8]; //Sprite clippings for kicking facing right
		SDL_Rect kickLeft[8]; //Sprite clippings for kicking facing left
		SDL_Rect blockRight[3]; //Sprite clippings for blocking facing right
		SDL_Rect blockLeft[3]; //Sprite clippings for blocking facing left
		SDL_Rect deadRight[6]; //Sprite clippings for dying facing right
		SDL_Rect deadLeft[6]; //Sprite clippings for dying facing left
};

//Constructor, uses member initialization syntax to access Character constructor
LadyGaga::LadyGaga(int xcoord, int ycoord, int walk) : Character(xcoord, ycoord, walk){}

//Clip the sprites for the character to stand, facing either right or left
void LadyGaga::clipStand(){
	standRight[ 0 ].x = 0; 
	standRight[ 0 ].y = 0; 
	standRight[ 0 ].w = 76; 
	standRight[ 0 ].h = 200;

	standRight[ 1 ].x = 76; 
	standRight[ 1 ].y = 0; 
	standRight[ 1 ].w = 76; 
	standRight[ 1 ].h = 200;

	standRight[ 2 ].x = 152; 
	standRight[ 2 ].y = 0; 
	standRight[ 2 ].w = 75; 
	standRight[ 2 ].h = 200;

	standRight[ 3 ].x = 227; 
	standRight[ 3 ].y = 0; 
	standRight[ 3 ].w = 75; 
	standRight[ 3 ].h = 200;

	standRight[ 4 ].x = 302; 
	standRight[ 4 ].y = 0; 
	standRight[ 4 ].w = 77; 
	standRight[ 4 ].h = 200;

	standRight[ 5 ].x = 379; 
	standRight[ 5 ].y = 0; 
	standRight[ 5 ].w = 82; 
	standRight[ 5 ].h = 200;

	standRight[ 6 ].x = 461; 
	standRight[ 6 ].y = 0; 
	standRight[ 6 ].w = 92; 
	standRight[ 6 ].h = 200;

	standRight[ 7 ].x = 553; 
	standRight[ 7 ].y = 0; 
	standRight[ 7 ].w = 99; 
	standRight[ 7 ].h = 200;

	standRight[ 8 ].x = 652; 
	standRight[ 8 ].y = 0; 
	standRight[ 8 ].w = 85; 
	standRight[ 8 ].h = 200;

	standLeft[ 0 ].x = 0; 
	standLeft[ 0 ].y = 3060; 
	standLeft[ 0 ].w = 76; 
	standLeft[ 0 ].h = 174;

	standLeft[ 1 ].x = 76; 
	standLeft[ 1 ].y = 3060; 
	standLeft[ 1 ].w = 76; 
	standLeft[ 1 ].h = 174;

	standLeft[ 2 ].x = 152; 
	standLeft[ 2 ].y = 3060; 
	standLeft[ 2 ].w = 75; 
	standLeft[ 2 ].h = 174;

	standLeft[ 3 ].x = 227; 
	standLeft[ 3 ].y = 3060; 
	standLeft[ 3 ].w = 75; 
	standLeft[ 3 ].h = 174;

	standLeft[ 4 ].x = 302; 
	standLeft[ 4 ].y = 3060; 
	standLeft[ 4 ].w = 77; 
	standLeft[ 4 ].h = 174;

	standLeft[ 5 ].x = 379; 
	standLeft[ 5 ].y = 3060; 
	standLeft[ 5 ].w = 82; 
	standLeft[ 5 ].h = 174;

	standLeft[ 6 ].x = 461; 
	standLeft[ 6 ].y = 3060; 
	standLeft[ 6 ].w = 92; 
	standLeft[ 6 ].h = 174;

	standLeft[ 7 ].x = 553; 
	standLeft[ 7 ].y = 3060; 
	standLeft[ 7 ].w = 99; 
	standLeft[ 7 ].h = 174;

	standLeft[ 8 ].x = 652; 
	standLeft[ 8 ].y = 3060; 
	standLeft[ 8 ].w = 85; 
	standLeft[ 8 ].h = 174;


}

//Clip the sprites for the character to walk, facing either Left or left
void LadyGaga::clipWalk(){
	walkRight[ 0 ].x = 0; 
	walkRight[ 0 ].y = 200; 
	walkRight[ 0 ].w = 79; 
	walkRight[ 0 ].h = 199;

	walkRight[ 1 ].x = 79; 
	walkRight[ 1 ].y = 200; 
	walkRight[ 1 ].w = 81; 
	walkRight[ 1 ].h = 199;

	walkRight[ 2 ].x = 160; 
	walkRight[ 2 ].y = 200; 
	walkRight[ 2 ].w = 78; 
	walkRight[ 2 ].h = 199;

	walkRight[ 3 ].x = 238; 
	walkRight[ 3 ].y = 200; 
	walkRight[ 3 ].w = 80; 
	walkRight[ 3 ].h = 199;

	walkRight[ 4 ].x = 318; 
	walkRight[ 4 ].y = 200; 
	walkRight[ 4 ].w = 79; 
	walkRight[ 4 ].h = 199;

	walkRight[ 5 ].x = 397; 
	walkRight[ 5 ].y = 200; 
	walkRight[ 5 ].w = 81; 
	walkRight[ 5 ].h = 199;

	walkRight[ 6 ].x = 478; 
	walkRight[ 6 ].y = 200; 
	walkRight[ 6 ].w = 78; 
	walkRight[ 6 ].h = 199;

	walkRight[ 7 ].x = 556; 
	walkRight[ 7 ].y = 200; 
	walkRight[ 7 ].w = 79; 
	walkRight[ 7 ].h = 199;

	walkRight[ 8 ].x = 635; 
	walkRight[ 8 ].y = 200; 
	walkRight[ 8 ].w = 81; 
	walkRight[ 8 ].h = 199;

	walkLeft[ 0 ].x = 0; 
	walkLeft[ 0 ].y = 3234; 
	walkLeft[ 0 ].w = 79; 
	walkLeft[ 0 ].h = 199;

	walkLeft[ 1 ].x = 79; 
	walkLeft[ 1 ].y = 3234; 
	walkLeft[ 1 ].w = 81; 
	walkLeft[ 1 ].h = 199;

	walkLeft[ 2 ].x = 160; 
	walkLeft[ 2 ].y = 3234; 
	walkLeft[ 2 ].w = 78; 
	walkLeft[ 2 ].h = 199;

	walkLeft[ 3 ].x = 238; 
	walkLeft[ 3 ].y = 3234; 
	walkLeft[ 3 ].w = 80; 
	walkLeft[ 3 ].h = 199;

	walkLeft[ 4 ].x = 318; 
	walkLeft[ 4 ].y = 3234; 
	walkLeft[ 4 ].w = 79; 
	walkLeft[ 4 ].h = 199;

	walkLeft[ 5 ].x = 397; 
	walkLeft[ 5 ].y = 3234; 
	walkLeft[ 5 ].w = 81; 
	walkLeft[ 5 ].h = 199;

	walkLeft[ 6 ].x = 478; 
	walkLeft[ 6 ].y = 3234; 
	walkLeft[ 6 ].w = 78; 
	walkLeft[ 6 ].h = 199;

	walkLeft[ 7 ].x = 556; 
	walkLeft[ 7 ].y = 3234; 
	walkLeft[ 7 ].w = 79; 
	walkLeft[ 7 ].h = 199;

	walkLeft[ 8 ].x = 635; 
	walkLeft[ 8 ].y = 3234; 
	walkLeft[ 8 ].w = 81; 
	walkLeft[ 8 ].h = 199;

	
}

//Clip the sprites for the character to punch, facing either right or left
void LadyGaga::clipPunch(){
	punchRight[ 0 ].x = 0; 
	punchRight[ 0 ].y = 1097; 
	punchRight[ 0 ].w = 77; 
	punchRight[ 0 ].h = 200;

	punchRight[ 1 ].x = 77; 
	punchRight[ 1 ].y = 1097; 
	punchRight[ 1 ].w = 99; 
	punchRight[ 1 ].h = 200;

	punchRight[ 2 ].x = 176; 
	punchRight[ 2 ].y = 1097; 
	punchRight[ 2 ].w = 136; 
	punchRight[ 2 ].h = 200;

	punchRight[ 3 ].x = 312; 
	punchRight[ 3 ].y = 1097; 
	punchRight[ 3 ].w = 115; 
	punchRight[ 3 ].h = 200;

	punchRight[ 4 ].x = 427; 
	punchRight[ 4 ].y = 1097; 
	punchRight[ 4 ].w = 116; 
	punchRight[ 4 ].h = 200;

	punchLeft[ 0 ].x = 0; 
	punchLeft[ 0 ].y = 4131; 
	punchLeft[ 0 ].w = 77; 
	punchLeft[ 0 ].h = 200;

	punchLeft[ 1 ].x = 77; 
	punchLeft[ 1 ].y = 4131; 
	punchLeft[ 1 ].w = 99; 
	punchLeft[ 1 ].h = 200;

	punchLeft[ 2 ].x = 176; 
	punchLeft[ 2 ].y = 4131; 
	punchLeft[ 2 ].w = 136; 
	punchLeft[ 2 ].h = 200;

	punchLeft[ 3 ].x = 312; 
	punchLeft[ 3 ].y = 4131; 
	punchLeft[ 3 ].w = 115; 
	punchLeft[ 3 ].h = 200;

	punchLeft[ 4 ].x = 427; 
	punchLeft[ 4 ].y = 4131; 
	punchLeft[ 4 ].w = 116; 
	punchLeft[ 4 ].h = 200;
}

//Clip the sprites for the character to kick, facing either right or left
void LadyGaga::clipKick(){
	kickRight[ 0 ].x = 0; 
	kickRight[ 0 ].y = 1745; 
	kickRight[ 0 ].w = 86; 
	kickRight[ 0 ].h = 193;	

	kickRight[ 1 ].x = 86; 
	kickRight[ 1 ].y = 1745; 
	kickRight[ 1 ].w = 80; 
	kickRight[ 1 ].h = 193;	

	kickRight[ 2 ].x = 166; 
	kickRight[ 2 ].y = 1745; 
	kickRight[ 2 ].w = 95; 
	kickRight[ 2 ].h = 193;	

	kickRight[ 3 ].x = 261; 
	kickRight[ 3 ].y = 1745; 
	kickRight[ 3 ].w = 143; 
	kickRight[ 3 ].h = 193;	

	kickRight[ 4 ].x = 404; 
	kickRight[ 4 ].y = 1745; 
	kickRight[ 4 ].w = 133; 
	kickRight[ 4 ].h = 193;	

	kickRight[ 5 ].x = 537; 
	kickRight[ 5 ].y = 1745; 
	kickRight[ 5 ].w = 87; 
	kickRight[ 5 ].h = 193;	

	kickRight[ 6 ].x = 624; 
	kickRight[ 6 ].y = 1745; 
	kickRight[ 6 ].w = 79; 
	kickRight[ 6 ].h = 193;	

	kickRight[ 7 ].x = 703; 
	kickRight[ 7 ].y = 1745; 
	kickRight[ 7 ].w = 85; 
	kickRight[ 7 ].h = 193;	

	kickLeft[ 0 ].x = 0; 
	kickLeft[ 0 ].y = 4779; 
	kickLeft[ 0 ].w = 86; 
	kickLeft[ 0 ].h = 193;	

	kickLeft[ 1 ].x = 86; 
	kickLeft[ 1 ].y = 4779; 
	kickLeft[ 1 ].w = 80; 
	kickLeft[ 1 ].h = 193;	

	kickLeft[ 2 ].x = 166; 
	kickLeft[ 2 ].y = 4779; 
	kickLeft[ 2 ].w = 95; 
	kickLeft[ 2 ].h = 193;	

	kickLeft[ 3 ].x = 261; 
	kickLeft[ 3 ].y = 4779; 
	kickLeft[ 3 ].w = 143; 
	kickLeft[ 3 ].h = 193;	

	kickLeft[ 4 ].x = 404; 
	kickLeft[ 4 ].y = 4779; 
	kickLeft[ 4 ].w = 133; 
	kickLeft[ 4 ].h = 193;	

	kickLeft[ 5 ].x = 537; 
	kickLeft[ 5 ].y = 4779; 
	kickLeft[ 5 ].w = 87; 
	kickLeft[ 5 ].h = 193;	

	kickLeft[ 6 ].x = 624; 
	kickLeft[ 6 ].y = 4779; 
	kickLeft[ 6 ].w = 79; 
	kickLeft[ 6 ].h = 193;	

	kickLeft[ 7 ].x = 703; 
	kickLeft[ 7 ].y = 4779; 
	kickLeft[ 7 ].w = 85; 
	kickLeft[ 7 ].h = 193;
}

//Clip the sprites for the character to block, facing either right or left
void LadyGaga::clipBlock(){
	blockRight[ 0 ].x = 0; 
	blockRight[ 0 ].y = 2557; 
	blockRight[ 0 ].w = 86; 
	blockRight[ 0 ].h = 184;

	blockRight[ 1 ].x = 86; 
	blockRight[ 1 ].y = 2557; 
	blockRight[ 1 ].w = 78; 
	blockRight[ 1 ].h = 184;

	blockRight[ 2 ].x = 164; 
	blockRight[ 2 ].y = 2557; 
	blockRight[ 2 ].w = 76; 
	blockRight[ 2 ].h = 184;

	blockLeft[ 0 ].x = 0; 
	blockLeft[ 0 ].y = 5591; 
	blockLeft[ 0 ].w = 86; 
	blockLeft[ 0 ].h = 184;

	blockLeft[ 1 ].x = 86; 
	blockLeft[ 1 ].y = 5591; 
	blockLeft[ 1 ].w = 78; 
	blockLeft[ 1 ].h = 184;

	blockLeft[ 2 ].x = 164; 
	blockLeft[ 2 ].y = 5591; 
	blockLeft[ 2 ].w = 76; 
	blockLeft[ 2 ].h = 184;
}

//Clip the sprites for the character to die, facing either right or left
void LadyGaga::clipDeath(){
	deadRight[ 0 ].x = 0; 
	deadRight[ 0 ].y = 2879; 
	deadRight[ 0 ].w = 45; 
	deadRight[ 0 ].h = 181;

	deadRight[ 1 ].x = 173; 
	deadRight[ 1 ].y = 2879; 
	deadRight[ 1 ].w = 91; 
	deadRight[ 1 ].h = 181;

	deadRight[ 2 ].x = 264; 
	deadRight[ 2 ].y = 2879; 
	deadRight[ 2 ].w = 115; 
	deadRight[ 2 ].h = 181;

	deadRight[ 3 ].x = 379; 
	deadRight[ 3 ].y = 2879; 
	deadRight[ 3 ].w = 152; 
	deadRight[ 3 ].h = 181;

	deadRight[ 4 ].x = 531; 
	deadRight[ 4 ].y = 2879; 
	deadRight[ 4 ].w = 151; 
	deadRight[ 4 ].h = 181;

	deadRight[ 5 ].x = 682; 
	deadRight[ 5 ].y = 2879; 
	deadRight[ 5 ].w = 179; 
	deadRight[ 5 ].h = 181;

	deadLeft[ 0 ].x = 0; 
	deadLeft[ 0 ].y = 5913; 
	deadLeft[ 0 ].w = 45; 
	deadLeft[ 0 ].h = 181;

	deadLeft[ 1 ].x = 173; 
	deadLeft[ 1 ].y = 5913; 
	deadLeft[ 1 ].w = 91; 
	deadLeft[ 1 ].h = 181;

	deadLeft[ 2 ].x = 264; 
	deadLeft[ 2 ].y = 5913; 
	deadLeft[ 2 ].w = 115; 
	deadLeft[ 2 ].h = 181;

	deadLeft[ 3 ].x = 379; 
	deadLeft[ 3 ].y = 5913; 
	deadLeft[ 3 ].w = 152; 
	deadLeft[ 3 ].h = 181;

	deadLeft[ 4 ].x = 531; 
	deadLeft[ 4 ].y = 5913; 
	deadLeft[ 4 ].w = 151; 
	deadLeft[ 4 ].h = 181;

	deadLeft[ 5 ].x = 682; 
	deadLeft[ 5 ].y = 5913; 
	deadLeft[ 5 ].w = 179; 
	deadLeft[ 5 ].h = 181;
}

//Display the dot
void LadyGaga::show(SDL_Surface* destination){
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
		if(status == 0 && frame >= 9){
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
		if(status == 3 && frame >= 8){
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
