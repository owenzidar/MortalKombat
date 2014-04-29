#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <sstream>

#include "Character.h"

using namespace std;

#ifndef MILEY_H
#define MILEY_H

class Miley : public Character{
	public:
		Miley(int = 800, int = 600, int = 0);
		virtual void clipStand(); //Clip the sprite sheet for the character to stand
		virtual void clipWalk(); //Clip the sprite sheet for the character to walk
		virtual void clipPunch(); //Clip the sprite sheet for the character to punch
		virtual void clipKick(); //Clip the sprite sheet for the character to kick
		virtual void clipBlock(); //Clip the sprite sheet for the character to block
		virtual void clipDeath(); //Clip the sprite sheet for the character to die
		virtual void show(SDL_Surface*); //Show the character on desired surface

	private:
		SDL_Rect standRight[8]; //Sprite clippings for standing facing right
		SDL_Rect standLeft[8]; //Sprite clippings for standing facing left
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

Miley::Miley(int xcoord, int ycoord, int walk) : Character(xcoord, ycoord, walk){}

//Clip the sprites for the character to stand, facing either right or left
void Miley::clipStand(){
	standRight[ 0 ].x = 0; 
	standRight[ 0 ].y = 0; 
	standRight[ 0 ].w = 101; 
	standRight[ 0 ].h = 200;

	standRight[ 1 ].x = 101; 
	standRight[ 1 ].y = 0; 
	standRight[ 1 ].w = 94; 
	standRight[ 1 ].h = 200;

	standRight[ 2 ].x = 195; 
	standRight[ 2 ].y = 0; 
	standRight[ 2 ].w = 90; 
	standRight[ 2 ].h = 200;

	standRight[ 3 ].x = 285; 
	standRight[ 3 ].y = 0; 
	standRight[ 3 ].w = 92; 
	standRight[ 3 ].h = 200;

	standRight[ 4 ].x = 377; 
	standRight[ 4 ].y = 0; 
	standRight[ 4 ].w = 92; 
	standRight[ 4 ].h = 200;

	standRight[ 5 ].x = 469; 
	standRight[ 5 ].y = 0; 
	standRight[ 5 ].w = 103; 
	standRight[ 5 ].h = 200;

	standRight[ 6 ].x = 572; 
	standRight[ 6 ].y = 0; 
	standRight[ 6 ].w = 109; 
	standRight[ 6 ].h = 200;

	standRight[ 7 ].x = 681; 
	standRight[ 7 ].y = 0; 
	standRight[ 7 ].w = 109; 
	standRight[ 7 ].h = 200;

	standLeft[ 0 ].x = 0; 
	standLeft[ 0 ].y = 2955; 
	standLeft[ 0 ].w = 101; 
	standLeft[ 0 ].h = 200;

	standLeft[ 1 ].x = 101; 
	standLeft[ 1 ].y = 2955; 
	standLeft[ 1 ].w = 94; 
	standLeft[ 1 ].h = 200;

	standLeft[ 2 ].x = 195; 
	standLeft[ 2 ].y = 2955; 
	standLeft[ 2 ].w = 90; 
	standLeft[ 2 ].h = 200;

	standLeft[ 3 ].x = 285; 
	standLeft[ 3 ].y = 2955; 
	standLeft[ 3 ].w = 92; 
	standLeft[ 3 ].h = 200;

	standLeft[ 4 ].x = 377; 
	standLeft[ 4 ].y = 2955; 
	standLeft[ 4 ].w = 92; 
	standLeft[ 4 ].h = 200;

	standLeft[ 5 ].x = 469; 
	standLeft[ 5 ].y = 2955; 
	standLeft[ 5 ].w = 103; 
	standLeft[ 5 ].h = 200;

	standLeft[ 6 ].x = 572; 
	standLeft[ 6 ].y = 2955; 
	standLeft[ 6 ].w = 109; 
	standLeft[ 6 ].h = 200;

	standLeft[ 7 ].x = 681; 
	standLeft[ 7 ].y = 2955; 
	standLeft[ 7 ].w = 109; 
	standLeft[ 7 ].h = 200;

}

//Clip the sprites for the character to walk, facing either Left or left
void Miley::clipWalk(){
	walkRight[ 0 ].x = 0; 
	walkRight[ 0 ].y = 200; 
	walkRight[ 0 ].w = 123; 
	walkRight[ 0 ].h = 200;

	walkRight[ 1 ].x = 123; 
	walkRight[ 1 ].y = 200; 
	walkRight[ 1 ].w = 115; 
	walkRight[ 1 ].h = 200;

	walkRight[ 2 ].x = 238; 
	walkRight[ 2 ].y = 200; 
	walkRight[ 2 ].w = 114; 
	walkRight[ 2 ].h = 200;

	walkRight[ 3 ].x = 352; 
	walkRight[ 3 ].y = 200; 
	walkRight[ 3 ].w = 114; 
	walkRight[ 3 ].h = 200;

	walkRight[ 4 ].x = 466; 
	walkRight[ 4 ].y = 200; 
	walkRight[ 4 ].w = 114; 
	walkRight[ 4 ].h = 200;

	walkRight[ 5 ].x = 580; 
	walkRight[ 5 ].y = 200; 
	walkRight[ 5 ].w = 114; 
	walkRight[ 5 ].h = 200;

	walkRight[ 6 ].x = 694; 
	walkRight[ 6 ].y = 200; 
	walkRight[ 6 ].w = 114; 
	walkRight[ 6 ].h = 200;

	walkRight[ 7 ].x = 808; 
	walkRight[ 7 ].y = 200; 
	walkRight[ 7 ].w = 114; 
	walkRight[ 7 ].h = 200;

	walkRight[ 8 ].x = 922; 
	walkRight[ 8 ].y = 200; 
	walkRight[ 8 ].w = 115; 
	walkRight[ 8 ].h = 200;

	walkLeft[ 0 ].x = 0; 
	walkLeft[ 0 ].y = 3155; 
	walkLeft[ 0 ].w = 123; 
	walkLeft[ 0 ].h = 200;

	walkLeft[ 1 ].x = 123; 
	walkLeft[ 1 ].y = 3155; 
	walkLeft[ 1 ].w = 115; 
	walkLeft[ 1 ].h = 200;

	walkLeft[ 2 ].x = 238; 
	walkLeft[ 2 ].y = 3155; 
	walkLeft[ 2 ].w = 114; 
	walkLeft[ 2 ].h = 200;

	walkLeft[ 3 ].x = 352; 
	walkLeft[ 3 ].y = 3155; 
	walkLeft[ 3 ].w = 114; 
	walkLeft[ 3 ].h = 200;

	walkLeft[ 4 ].x = 466; 
	walkLeft[ 4 ].y = 3155; 
	walkLeft[ 4 ].w = 114; 
	walkLeft[ 4 ].h = 200;

	walkLeft[ 5 ].x = 580; 
	walkLeft[ 5 ].y = 3155; 
	walkLeft[ 5 ].w = 114; 
	walkLeft[ 5 ].h = 200;

	walkLeft[ 6 ].x = 694; 
	walkLeft[ 6 ].y = 3155; 
	walkLeft[ 6 ].w = 114; 
	walkLeft[ 6 ].h = 200;

	walkLeft[ 7 ].x = 808; 
	walkLeft[ 7 ].y = 3155; 
	walkLeft[ 7 ].w = 114; 
	walkLeft[ 7 ].h = 200;

	walkLeft[ 8 ].x = 922; 
	walkLeft[ 8 ].y = 3155; 
	walkLeft[ 8 ].w = 115; 
	walkLeft[ 8 ].h = 200;

	
}

//Clip the sprites for the character to punch, facing either right or left
void Miley::clipPunch(){
	punchRight[ 0 ].x = 0; 
	punchRight[ 0 ].y = 1085; 
	punchRight[ 0 ].w = 95; 
	punchRight[ 0 ].h = 186;

	punchRight[ 1 ].x = 95; 
	punchRight[ 1 ].y = 1085; 
	punchRight[ 1 ].w = 122; 
	punchRight[ 1 ].h = 186;

	punchRight[ 2 ].x = 217; 
	punchRight[ 2 ].y = 1085; 
	punchRight[ 2 ].w = 152; 
	punchRight[ 2 ].h = 186;

	punchRight[ 3 ].x = 369; 
	punchRight[ 3 ].y = 1085; 
	punchRight[ 3 ].w = 134; 
	punchRight[ 3 ].h = 186;

	punchRight[ 4 ].x = 503; 
	punchRight[ 4 ].y = 1085; 
	punchRight[ 4 ].w = 134; 
	punchRight[ 4 ].h = 186;

	punchLeft[ 0 ].x = 0; 
	punchLeft[ 0 ].y = 4040; 
	punchLeft[ 0 ].w = 95; 
	punchLeft[ 0 ].h = 186;

	punchLeft[ 1 ].x = 95; 
	punchLeft[ 1 ].y = 4040; 
	punchLeft[ 1 ].w = 122; 
	punchLeft[ 1 ].h = 186;

	punchLeft[ 2 ].x = 217; 
	punchLeft[ 2 ].y = 4040; 
	punchLeft[ 2 ].w = 152; 
	punchLeft[ 2 ].h = 186;

	punchLeft[ 3 ].x = 369; 
	punchLeft[ 3 ].y = 4040; 
	punchLeft[ 3 ].w = 134; 
	punchLeft[ 3 ].h = 186;

	punchLeft[ 4 ].x = 503; 
	punchLeft[ 4 ].y = 4040; 
	punchLeft[ 4 ].w = 134; 
	punchLeft[ 4 ].h = 186;
}

//Clip the sprites for the character to kick, facing either right or left
void Miley::clipKick(){
	kickRight[ 0 ].x = 0; 
	kickRight[ 0 ].y = 1680; 
	kickRight[ 0 ].w = 92; 
	kickRight[ 0 ].h = 187;	

	kickRight[ 1 ].x = 92; 
	kickRight[ 1 ].y = 1680; 
	kickRight[ 1 ].w = 108; 
	kickRight[ 1 ].h = 187;	

	kickRight[ 2 ].x = 200; 
	kickRight[ 2 ].y = 1680; 
	kickRight[ 2 ].w = 148; 
	kickRight[ 2 ].h = 187;	

	kickRight[ 3 ].x = 348; 
	kickRight[ 3 ].y = 1680; 
	kickRight[ 3 ].w = 117; 
	kickRight[ 3 ].h = 187;	

	kickRight[ 4 ].x = 465; 
	kickRight[ 4 ].y = 1680; 
	kickRight[ 4 ].w = 90; 
	kickRight[ 4 ].h = 187;	

	kickRight[ 5 ].x = 555; 
	kickRight[ 5 ].y = 1680; 
	kickRight[ 5 ].w = 98; 
	kickRight[ 5 ].h = 187;	

	kickRight[ 6 ].x = 653; 
	kickRight[ 6 ].y = 1680; 
	kickRight[ 6 ].w = 112; 
	kickRight[ 6 ].h = 187;	

	kickRight[ 7 ].x = 765; 
	kickRight[ 7 ].y = 1680; 
	kickRight[ 7 ].w = 114; 
	kickRight[ 7 ].h = 187;	

	kickLeft[ 0 ].x = 0; 
	kickLeft[ 0 ].y = 4635; 
	kickLeft[ 0 ].w = 92; 
	kickLeft[ 0 ].h = 187;	

	kickLeft[ 1 ].x = 92; 
	kickLeft[ 1 ].y = 4635; 
	kickLeft[ 1 ].w = 108; 
	kickLeft[ 1 ].h = 187;	

	kickLeft[ 2 ].x = 200; 
	kickLeft[ 2 ].y = 4635; 
	kickLeft[ 2 ].w = 148; 
	kickLeft[ 2 ].h = 187;	

	kickLeft[ 3 ].x = 348; 
	kickLeft[ 3 ].y = 4635; 
	kickLeft[ 3 ].w = 117; 
	kickLeft[ 3 ].h = 187;	

	kickLeft[ 4 ].x = 465; 
	kickLeft[ 4 ].y = 4635; 
	kickLeft[ 4 ].w = 90; 
	kickLeft[ 4 ].h = 187;	

	kickLeft[ 5 ].x = 555; 
	kickLeft[ 5 ].y = 4635; 
	kickLeft[ 5 ].w = 98; 
	kickLeft[ 5 ].h = 187;	

	kickLeft[ 6 ].x = 653; 
	kickLeft[ 6 ].y = 4635; 
	kickLeft[ 6 ].w = 112; 
	kickLeft[ 6 ].h = 187;	

	kickLeft[ 7 ].x = 765; 
	kickLeft[ 7 ].y = 4635; 
	kickLeft[ 7 ].w = 114; 
	kickLeft[ 7 ].h = 187;
}

//Clip the sprites for the character to block, facing either right or left
void Miley::clipBlock(){
	blockRight[ 0 ].x = 0; 
	blockRight[ 0 ].y = 2453; 
	blockRight[ 0 ].w = 95; 
	blockRight[ 0 ].h = 183;

	blockRight[ 1 ].x = 95; 
	blockRight[ 1 ].y = 2453; 
	blockRight[ 1 ].w = 91; 
	blockRight[ 1 ].h = 183;

	blockRight[ 2 ].x = 186; 
	blockRight[ 2 ].y = 2453; 
	blockRight[ 2 ].w = 88; 
	blockRight[ 2 ].h = 183;

	blockLeft[ 0 ].x = 0; 
	blockLeft[ 0 ].y = 5408; 
	blockLeft[ 0 ].w = 95; 
	blockLeft[ 0 ].h = 183;

	blockLeft[ 1 ].x = 95; 
	blockLeft[ 1 ].y = 5408; 
	blockLeft[ 1 ].w = 91; 
	blockLeft[ 1 ].h = 183;

	blockLeft[ 2 ].x = 186; 
	blockLeft[ 2 ].y = 5408; 
	blockLeft[ 2 ].w = 88; 
	blockLeft[ 2 ].h = 183;
}

//Clip the sprites for the character to die, facing either right or left
void Miley::clipDeath(){
	deadRight[ 0 ].x = 0; 
	deadRight[ 0 ].y = 2774; 
	deadRight[ 0 ].w = 37; 
	deadRight[ 0 ].h = 181;

	deadRight[ 1 ].x = 93; 
	deadRight[ 1 ].y = 2774; 
	deadRight[ 1 ].w = 90; 
	deadRight[ 1 ].h = 181;

	deadRight[ 2 ].x = 183; 
	deadRight[ 2 ].y = 2774; 
	deadRight[ 2 ].w = 129; 
	deadRight[ 2 ].h = 181;

	deadRight[ 3 ].x = 312; 
	deadRight[ 3 ].y = 2774; 
	deadRight[ 3 ].w = 171; 
	deadRight[ 3 ].h = 181;

	deadRight[ 4 ].x = 493; 
	deadRight[ 4 ].y = 2774; 
	deadRight[ 4 ].w = 214; 
	deadRight[ 4 ].h = 181;

	deadRight[ 5 ].x = 707; 
	deadRight[ 5 ].y = 2774; 
	deadRight[ 5 ].w = 228; 
	deadRight[ 5 ].h = 181;

	deadLeft[ 0 ].x = 0; 
	deadLeft[ 0 ].y = 5729; 
	deadLeft[ 0 ].w = 37; 
	deadLeft[ 0 ].h = 181;

	deadLeft[ 1 ].x = 93; 
	deadLeft[ 1 ].y = 5729; 
	deadLeft[ 1 ].w = 90; 
	deadLeft[ 1 ].h = 181;

	deadLeft[ 2 ].x = 183; 
	deadLeft[ 2 ].y = 5729; 
	deadLeft[ 2 ].w = 129; 
	deadLeft[ 2 ].h = 181;

	deadLeft[ 3 ].x = 312; 
	deadLeft[ 3 ].y = 5729; 
	deadLeft[ 3 ].w = 171; 
	deadLeft[ 3 ].h = 181;

	deadLeft[ 4 ].x = 493; 
	deadLeft[ 4 ].y = 5729; 
	deadLeft[ 4 ].w = 214; 
	deadLeft[ 4 ].h = 181;

	deadLeft[ 5 ].x = 707; 
	deadLeft[ 5 ].y = 5729; 
	deadLeft[ 5 ].w = 228; 
	deadLeft[ 5 ].h = 181;
}

//Display the dot
void Miley::show(SDL_Surface* destination){
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
		if(status == 0 && frame >= 8){
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
