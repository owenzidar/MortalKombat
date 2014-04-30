/*
Kevin Epp, Mitch Patin, Owen Zidar  CSE 20212
Final Project  Leprechaun.h
Derived class for Leprechaun object, inherits from Character.h
*/

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <sstream>

#include "Character.h"

using namespace std;

#ifndef LEPRECHAUN_H
#define LEPRECHAUN_H

class Leprechaun : public Character{
	public:
		Leprechaun(int = 400, int = 600, int = 1); //Constructor
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
Leprechaun::Leprechaun(int xcoord, int ycoord, int walk) : Character(xcoord, ycoord, walk){}

//Clip the sprites for the character to stand, facing either right or left
void Leprechaun::clipStand(){
	standRight[ 0 ].x = 0; 
	standRight[ 0 ].y = 0; 
	standRight[ 0 ].w = 75; 
	standRight[ 0 ].h = 200;

	standRight[ 1 ].x = 75; 
	standRight[ 1 ].y = 0; 
	standRight[ 1 ].w = 79; 
	standRight[ 1 ].h = 200;

	standRight[ 2 ].x = 154; 
	standRight[ 2 ].y = 0; 
	standRight[ 2 ].w = 83; 
	standRight[ 2 ].h = 200;

	standRight[ 3 ].x = 237; 
	standRight[ 3 ].y = 0; 
	standRight[ 3 ].w = 88; 
	standRight[ 3 ].h = 200;

	standRight[ 4 ].x = 325; 
	standRight[ 4 ].y = 0; 
	standRight[ 4 ].w = 85; 
	standRight[ 4 ].h = 200;

	standRight[ 5 ].x = 410; 
	standRight[ 5 ].y = 0; 
	standRight[ 5 ].w = 78; 
	standRight[ 5 ].h = 200;

	standRight[ 6 ].x = 488; 
	standRight[ 6 ].y = 0; 
	standRight[ 6 ].w = 75; 
	standRight[ 6 ].h = 200;

	standRight[ 7 ].x = 563; 
	standRight[ 7 ].y = 0; 
	standRight[ 7 ].w = 74; 
	standRight[ 7 ].h = 200;

	standRight[ 8 ].x = 638; 
	standRight[ 8 ].y = 0; 
	standRight[ 8 ].w = 70; 
	standRight[ 8 ].h = 200;

	standLeft[ 0 ].x = 0; 
	standLeft[ 0 ].y = 3133; 
	standLeft[ 0 ].w = 75; 
	standLeft[ 0 ].h = 185;

	standLeft[ 1 ].x = 75; 
	standLeft[ 1 ].y = 3133; 
	standLeft[ 1 ].w = 79; 
	standLeft[ 1 ].h = 185;

	standLeft[ 2 ].x = 154; 
	standLeft[ 2 ].y = 3133; 
	standLeft[ 2 ].w = 83; 
	standLeft[ 2 ].h = 185;

	standLeft[ 3 ].x = 237; 
	standLeft[ 3 ].y = 3133; 
	standLeft[ 3 ].w = 88; 
	standLeft[ 3 ].h = 185;

	standLeft[ 4 ].x = 325; 
	standLeft[ 4 ].y = 3133; 
	standLeft[ 4 ].w = 85; 
	standLeft[ 4 ].h = 185;

	standLeft[ 5 ].x = 410; 
	standLeft[ 5 ].y = 3133; 
	standLeft[ 5 ].w = 78; 
	standLeft[ 5 ].h = 185;

	standLeft[ 6 ].x = 488; 
	standLeft[ 6 ].y = 3133; 
	standLeft[ 6 ].w = 75; 
	standLeft[ 6 ].h = 185;

	standLeft[ 7 ].x = 563; 
	standLeft[ 7 ].y = 3133; 
	standLeft[ 7 ].w = 74; 
	standLeft[ 7 ].h = 185;

	standLeft[ 8 ].x = 638; 
	standLeft[ 8 ].y = 3133; 
	standLeft[ 8 ].w = 70; 
	standLeft[ 8 ].h = 185;


}

//Clip the sprites for the character to walk, facing either right or left
void Leprechaun::clipWalk(){
	walkRight[ 0 ].x = 0; 
	walkRight[ 0 ].y = 200; 
	walkRight[ 0 ].w = 77; 
	walkRight[ 0 ].h = 200;

	walkRight[ 1 ].x = 77; 
	walkRight[ 1 ].y = 200; 
	walkRight[ 1 ].w = 84; 
	walkRight[ 1 ].h = 200;

	walkRight[ 2 ].x = 161; 
	walkRight[ 2 ].y = 200; 
	walkRight[ 2 ].w = 80; 
	walkRight[ 2 ].h = 200;

	walkRight[ 3 ].x = 241; 
	walkRight[ 3 ].y = 200; 
	walkRight[ 3 ].w = 82; 
	walkRight[ 3 ].h = 200;

	walkRight[ 4 ].x = 323; 
	walkRight[ 4 ].y = 200; 
	walkRight[ 4 ].w = 78; 
	walkRight[ 4 ].h = 200;

	walkRight[ 5 ].x = 401; 
	walkRight[ 5 ].y = 200; 
	walkRight[ 5 ].w = 81; 
	walkRight[ 5 ].h = 200;

	walkRight[ 6 ].x = 482; 
	walkRight[ 6 ].y = 200; 
	walkRight[ 6 ].w = 79; 
	walkRight[ 6 ].h = 200;

	walkRight[ 7 ].x = 561; 
	walkRight[ 7 ].y = 200; 
	walkRight[ 7 ].w = 80; 
	walkRight[ 7 ].h = 200;

	walkRight[ 8 ].x = 641; 
	walkRight[ 8 ].y = 200; 
	walkRight[ 8 ].w = 86; 
	walkRight[ 8 ].h = 200;

	walkLeft[ 0 ].x = 0; 
	walkLeft[ 0 ].y = 3333; 
	walkLeft[ 0 ].w = 77; 
	walkLeft[ 0 ].h = 200;

	walkLeft[ 1 ].x = 77; 
	walkLeft[ 1 ].y = 3333; 
	walkLeft[ 1 ].w = 84; 
	walkLeft[ 1 ].h = 200;

	walkLeft[ 2 ].x = 161; 
	walkLeft[ 2 ].y = 3333; 
	walkLeft[ 2 ].w = 80; 
	walkLeft[ 2 ].h = 200;

	walkLeft[ 3 ].x = 241; 
	walkLeft[ 3 ].y = 3333; 
	walkLeft[ 3 ].w = 82; 
	walkLeft[ 3 ].h = 200;

	walkLeft[ 4 ].x = 323; 
	walkLeft[ 4 ].y = 3333; 
	walkLeft[ 4 ].w = 78; 
	walkLeft[ 4 ].h = 200;

	walkLeft[ 5 ].x = 401; 
	walkLeft[ 5 ].y = 3333; 
	walkLeft[ 5 ].w = 81; 
	walkLeft[ 5 ].h = 200;

	walkLeft[ 6 ].x = 482; 
	walkLeft[ 6 ].y = 3333; 
	walkLeft[ 6 ].w = 79; 
	walkLeft[ 6 ].h = 200;

	walkLeft[ 7 ].x = 561; 
	walkLeft[ 7 ].y = 3333; 
	walkLeft[ 7 ].w = 80; 
	walkLeft[ 7 ].h = 200;

	walkLeft[ 8 ].x = 641; 
	walkLeft[ 8 ].y = 3333; 
	walkLeft[ 8 ].w = 86; 
	walkLeft[ 8 ].h = 200;

	
}

//Clip the sprites for the character to punch, facing either right or left
void Leprechaun::clipPunch(){
	punchRight[ 0 ].x = 0; 
	punchRight[ 0 ].y = 1119; 
	punchRight[ 0 ].w = 67; 
	punchRight[ 0 ].h = 200;

	punchRight[ 1 ].x = 67; 
	punchRight[ 1 ].y = 1119; 
	punchRight[ 1 ].w = 92; 
	punchRight[ 1 ].h = 200;

	punchRight[ 2 ].x = 159; 
	punchRight[ 2 ].y = 1119; 
	punchRight[ 2 ].w = 122; 
	punchRight[ 2 ].h = 200;

	punchRight[ 3 ].x = 281; 
	punchRight[ 3 ].y = 1119; 
	punchRight[ 3 ].w = 110; 
	punchRight[ 3 ].h = 200;

	punchRight[ 4 ].x = 391; 
	punchRight[ 4 ].y = 1119; 
	punchRight[ 4 ].w = 104; 
	punchRight[ 4 ].h = 200;

	punchLeft[ 0 ].x = 0; 
	punchLeft[ 0 ].y = 4237; 
	punchLeft[ 0 ].w = 67; 
	punchLeft[ 0 ].h = 200;

	punchLeft[ 1 ].x = 67; 
	punchLeft[ 1 ].y = 4237; 
	punchLeft[ 1 ].w = 92; 
	punchLeft[ 1 ].h = 200;

	punchLeft[ 2 ].x = 159; 
	punchLeft[ 2 ].y = 4237; 
	punchLeft[ 2 ].w = 122; 
	punchLeft[ 2 ].h = 200;

	punchLeft[ 3 ].x = 281; 
	punchLeft[ 3 ].y = 4237; 
	punchLeft[ 3 ].w = 110; 
	punchLeft[ 3 ].h = 200;

	punchLeft[ 4 ].x = 391; 
	punchLeft[ 4 ].y = 4237; 
	punchLeft[ 4 ].w = 104; 
	punchLeft[ 4 ].h = 200;
}

//Clip the sprites for the character to kick, facing either right or left
void Leprechaun::clipKick(){
	kickRight[ 0 ].x = 0; 
	kickRight[ 0 ].y = 1805; 
	kickRight[ 0 ].w = 87; 
	kickRight[ 0 ].h = 197;	

	kickRight[ 1 ].x = 87; 
	kickRight[ 1 ].y = 1805; 
	kickRight[ 1 ].w = 94; 
	kickRight[ 1 ].h = 197;	

	kickRight[ 2 ].x = 181; 
	kickRight[ 2 ].y = 1805; 
	kickRight[ 2 ].w = 96; 
	kickRight[ 2 ].h = 197;	

	kickRight[ 3 ].x = 277; 
	kickRight[ 3 ].y = 1805; 
	kickRight[ 3 ].w = 122; 
	kickRight[ 3 ].h = 197;	

	kickRight[ 4 ].x = 399; 
	kickRight[ 4 ].y = 1805; 
	kickRight[ 4 ].w = 150; 
	kickRight[ 4 ].h = 197;	

	kickRight[ 5 ].x = 549; 
	kickRight[ 5 ].y = 1805; 
	kickRight[ 5 ].w = 99; 
	kickRight[ 5 ].h = 197;	

	kickRight[ 6 ].x = 648; 
	kickRight[ 6 ].y = 1805; 
	kickRight[ 6 ].w = 72; 
	kickRight[ 6 ].h = 197;	

	kickRight[ 7 ].x = 720; 
	kickRight[ 7 ].y = 1805; 
	kickRight[ 7 ].w = 81; 
	kickRight[ 7 ].h = 197;	

	kickLeft[ 0 ].x = 0; 
	kickLeft[ 0 ].y = 4923; 
	kickLeft[ 0 ].w = 87; 
	kickLeft[ 0 ].h = 197;	

	kickLeft[ 1 ].x = 87; 
	kickLeft[ 1 ].y = 4923; 
	kickLeft[ 1 ].w = 94; 
	kickLeft[ 1 ].h = 197;	

	kickLeft[ 2 ].x = 181; 
	kickLeft[ 2 ].y = 4923; 
	kickLeft[ 2 ].w = 96; 
	kickLeft[ 2 ].h = 197;	

	kickLeft[ 3 ].x = 277; 
	kickLeft[ 3 ].y = 4923; 
	kickLeft[ 3 ].w = 122; 
	kickLeft[ 3 ].h = 197;	

	kickLeft[ 4 ].x = 399; 
	kickLeft[ 4 ].y = 4923; 
	kickLeft[ 4 ].w = 150; 
	kickLeft[ 4 ].h = 197;	

	kickLeft[ 5 ].x = 549; 
	kickLeft[ 5 ].y = 4923; 
	kickLeft[ 5 ].w = 99; 
	kickLeft[ 5 ].h = 197;	

	kickLeft[ 6 ].x = 648; 
	kickLeft[ 6 ].y = 4923; 
	kickLeft[ 6 ].w = 72; 
	kickLeft[ 6 ].h = 197;	

	kickLeft[ 7 ].x = 720; 
	kickLeft[ 7 ].y = 4923; 
	kickLeft[ 7 ].w = 81; 
	kickLeft[ 7 ].h = 197;
}

//Clip the sprites for the character to block, facing either right or left
void Leprechaun::clipBlock(){
	blockRight[ 0 ].x = 0; 
	blockRight[ 0 ].y = 2629; 
	blockRight[ 0 ].w = 74; 
	blockRight[ 0 ].h = 184;

	blockRight[ 1 ].x = 74; 
	blockRight[ 1 ].y = 2629; 
	blockRight[ 1 ].w = 67; 
	blockRight[ 1 ].h = 184;

	blockRight[ 2 ].x = 141; 
	blockRight[ 2 ].y = 2629; 
	blockRight[ 2 ].w = 68; 
	blockRight[ 2 ].h = 184;

	blockLeft[ 0 ].x = 0; 
	blockLeft[ 0 ].y = 5747; 
	blockLeft[ 0 ].w = 74; 
	blockLeft[ 0 ].h = 184;

	blockLeft[ 1 ].x = 74; 
	blockLeft[ 1 ].y = 5747; 
	blockLeft[ 1 ].w = 67; 
	blockLeft[ 1 ].h = 184;

	blockLeft[ 2 ].x = 141; 
	blockLeft[ 2 ].y = 5747; 
	blockLeft[ 2 ].w = 68; 
	blockLeft[ 2 ].h = 184;
}

//Clip the sprites for the character to die, facing either right or left
void Leprechaun::clipDeath(){
	deadRight[ 0 ].x = 0; 
	deadRight[ 0 ].y = 2951; 
	deadRight[ 0 ].w = 41; 
	deadRight[ 0 ].h = 182;

	deadRight[ 1 ].x = 41; 
	deadRight[ 1 ].y = 2951; 
	deadRight[ 1 ].w = 73; 
	deadRight[ 1 ].h = 182;

	deadRight[ 2 ].x = 114; 
	deadRight[ 2 ].y = 2951; 
	deadRight[ 2 ].w = 107; 
	deadRight[ 2 ].h = 182;

	deadRight[ 3 ].x = 221; 
	deadRight[ 3 ].y = 2951; 
	deadRight[ 3 ].w = 141; 
	deadRight[ 3 ].h = 182;

	deadRight[ 4 ].x = 362; 
	deadRight[ 4 ].y = 2951; 
	deadRight[ 4 ].w = 174; 
	deadRight[ 4 ].h = 182;

	deadRight[ 5 ].x = 536; 
	deadRight[ 5 ].y = 2951; 
	deadRight[ 5 ].w = 182; 
	deadRight[ 5 ].h = 182;

	deadLeft[ 0 ].x = 0; 
	deadLeft[ 0 ].y = 6069; 
	deadLeft[ 0 ].w = 41; 
	deadLeft[ 0 ].h = 182;

	deadLeft[ 1 ].x = 41; 
	deadLeft[ 1 ].y = 6069; 
	deadLeft[ 1 ].w = 73; 
	deadLeft[ 1 ].h = 182;

	deadLeft[ 2 ].x = 114; 
	deadLeft[ 2 ].y = 6069; 
	deadLeft[ 2 ].w = 107; 
	deadLeft[ 2 ].h = 182;

	deadLeft[ 3 ].x = 221; 
	deadLeft[ 3 ].y = 6069; 
	deadLeft[ 3 ].w = 141; 
	deadLeft[ 3 ].h = 182;

	deadLeft[ 4 ].x = 362; 
	deadLeft[ 4 ].y = 6069; 
	deadLeft[ 4 ].w = 174; 
	deadLeft[ 4 ].h = 182;

	deadLeft[ 5 ].x = 536; 
	deadLeft[ 5 ].y = 6069; 
	deadLeft[ 5 ].w = 182; 
	deadLeft[ 5 ].h = 182;
}

//Display the dot
void Leprechaun::show(SDL_Surface* destination){
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
