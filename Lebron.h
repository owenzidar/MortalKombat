#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <sstream>

#include "Character.h"

using namespace std;

#ifndef LEBRON_H
#define LEBRON_H

class Lebron : public Character{
	public:
		Lebron(int, int, int);
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

Lebron::Lebron(int xcoord, int ycoord, int walk) : Character(xcoord, ycoord, walk){
	image = load_image("LebronJames.png"); //Load image of the dot
}

//Clip the sprites for the character to stand, facing either right or left
void Lebron::clipStand(){
	standRight[ 0 ].x = 0; 
	standRight[ 0 ].y = 0; 
	standRight[ 0 ].w = 78; 
	standRight[ 0 ].h = 196;

	standRight[ 1 ].x = 78; 
	standRight[ 1 ].y = 0; 
	standRight[ 1 ].w = 79; 
	standRight[ 1 ].h = 196;

	standRight[ 2 ].x = 157; 
	standRight[ 2 ].y = 0; 
	standRight[ 2 ].w = 79; 
	standRight[ 2 ].h = 196;

	standRight[ 3 ].x = 236; 
	standRight[ 3 ].y = 0; 
	standRight[ 3 ].w = 80; 
	standRight[ 3 ].h = 196;

	standRight[ 4 ].x = 316; 
	standRight[ 4 ].y = 0; 
	standRight[ 4 ].w = 86; 
	standRight[ 4 ].h = 196;

	standRight[ 5 ].x = 402; 
	standRight[ 5 ].y = 0; 
	standRight[ 5 ].w = 90; 
	standRight[ 5 ].h = 196;

	standRight[ 6 ].x = 492; 
	standRight[ 6 ].y = 0; 
	standRight[ 6 ].w = 89; 
	standRight[ 6 ].h = 196;

	standRight[ 7 ].x = 581; 
	standRight[ 7 ].y = 0; 
	standRight[ 7 ].w = 83; 
	standRight[ 7 ].h = 196;

	standRight[ 8 ].x = 664; 
	standRight[ 8 ].y = 0; 
	standRight[ 8 ].w = 76; 
	standRight[ 8 ].h = 196;

	standLeft[ 0 ].x = 0; 
	standLeft[ 0 ].y = 3209; 
	standLeft[ 0 ].w = 78; 
	standLeft[ 0 ].h = 196;

	standLeft[ 1 ].x = 78; 
	standLeft[ 1 ].y = 3209; 
	standLeft[ 1 ].w = 79; 
	standLeft[ 1 ].h = 196;

	standLeft[ 2 ].x = 157; 
	standLeft[ 2 ].y = 3209; 
	standLeft[ 2 ].w = 79; 
	standLeft[ 2 ].h = 196;

	standLeft[ 3 ].x = 236; 
	standLeft[ 3 ].y = 3209; 
	standLeft[ 3 ].w = 80; 
	standLeft[ 3 ].h = 196;

	standLeft[ 4 ].x = 316; 
	standLeft[ 4 ].y = 3209; 
	standLeft[ 4 ].w = 86; 
	standLeft[ 4 ].h = 196;

	standLeft[ 5 ].x = 402; 
	standLeft[ 5 ].y = 3209; 
	standLeft[ 5 ].w = 90; 
	standLeft[ 5 ].h = 196;

	standLeft[ 6 ].x = 492; 
	standLeft[ 6 ].y = 3209; 
	standLeft[ 6 ].w = 89; 
	standLeft[ 6 ].h = 196;

	standLeft[ 7 ].x = 581; 
	standLeft[ 7 ].y = 3209; 
	standLeft[ 7 ].w = 83; 
	standLeft[ 7 ].h = 196;

	standLeft[ 8 ].x = 664; 
	standLeft[ 8 ].y = 3209; 
	standLeft[ 8 ].w = 76; 
	standLeft[ 8 ].h = 196;

	standLeft[ 9 ].x = 740; 
	standLeft[ 9 ].y = 3209; 
	standLeft[ 9 ].w = 78; 
	standLeft[ 9 ].h = 196;
}

//Clip the sprites for the character to walk, facing either right or left
void Lebron::clipWalk(){
	walkRight[ 0 ].x = 0; 
	walkRight[ 0 ].y = 196; 
	walkRight[ 0 ].w = 83; 
	walkRight[ 0 ].h = 196;

	walkRight[ 1 ].x = 83; 
	walkRight[ 1 ].y = 196; 
	walkRight[ 1 ].w = 73; 
	walkRight[ 1 ].h = 196;

	walkRight[ 2 ].x = 156; 
	walkRight[ 2 ].y = 196; 
	walkRight[ 2 ].w = 73; 
	walkRight[ 2 ].h = 196;

	walkRight[ 3 ].x = 229; 
	walkRight[ 3 ].y = 196; 
	walkRight[ 3 ].w = 72; 
	walkRight[ 3 ].h = 196;

	walkRight[ 4 ].x = 301; 
	walkRight[ 4 ].y = 196; 
	walkRight[ 4 ].w = 73; 
	walkRight[ 4 ].h = 196;

	walkRight[ 5 ].x = 374; 
	walkRight[ 5 ].y = 196; 
	walkRight[ 5 ].w = 73; 
	walkRight[ 5 ].h = 196;

	walkRight[ 6 ].x = 447; 
	walkRight[ 6 ].y = 196; 
	walkRight[ 6 ].w = 73; 
	walkRight[ 6 ].h = 196;

	walkRight[ 7 ].x = 520; 
	walkRight[ 7 ].y = 196; 
	walkRight[ 7 ].w = 87; 
	walkRight[ 7 ].h = 196;

	walkRight[ 8 ].x = 607; 
	walkRight[ 8 ].y = 196; 
	walkRight[ 8 ].w = 87; 
	walkRight[ 8 ].h = 196;

	walkLeft[ 0 ].x = 0; 
	walkLeft[ 0 ].y = 3405; 
	walkLeft[ 0 ].w = 83; 
	walkLeft[ 0 ].h = 196;

	walkLeft[ 1 ].x = 83; 
	walkLeft[ 1 ].y = 3405; 
	walkLeft[ 1 ].w = 73; 
	walkLeft[ 1 ].h = 196;

	walkLeft[ 2 ].x = 156; 
	walkLeft[ 2 ].y = 3405; 
	walkLeft[ 2 ].w = 73; 
	walkLeft[ 2 ].h = 196;

	walkLeft[ 3 ].x = 229; 
	walkLeft[ 3 ].y = 3405; 
	walkLeft[ 3 ].w = 72; 
	walkLeft[ 3 ].h = 196;

	walkLeft[ 4 ].x = 301; 
	walkLeft[ 4 ].y = 3405; 
	walkLeft[ 4 ].w = 73; 
	walkLeft[ 4 ].h = 196;

	walkLeft[ 5 ].x = 374; 
	walkLeft[ 5 ].y = 3405; 
	walkLeft[ 5 ].w = 73; 
	walkLeft[ 5 ].h = 196;

	walkLeft[ 6 ].x = 447; 
	walkLeft[ 6 ].y = 3405; 
	walkLeft[ 6 ].w = 73; 
	walkLeft[ 6 ].h = 196;

	walkLeft[ 7 ].x = 520; 
	walkLeft[ 7 ].y = 3405; 
	walkLeft[ 7 ].w = 87; 
	walkLeft[ 7 ].h = 196;

	walkLeft[ 8 ].x = 607; 
	walkLeft[ 8 ].y = 3405; 
	walkLeft[ 8 ].w = 87; 
	walkLeft[ 8 ].h = 196;

	
}

//Clip the sprites for the character to punch, facing either right or left
void Lebron::clipPunch(){
	punchRight[ 0 ].x = 0; 
	punchRight[ 0 ].y = 1127; 
	punchRight[ 0 ].w = 81; 
	punchRight[ 0 ].h = 206;

	punchRight[ 1 ].x = 81; 
	punchRight[ 1 ].y = 1127; 
	punchRight[ 1 ].w = 104; 
	punchRight[ 1 ].h = 206;

	punchRight[ 2 ].x = 185; 
	punchRight[ 2 ].y = 1127; 
	punchRight[ 2 ].w = 142; 
	punchRight[ 2 ].h = 206;

	punchRight[ 3 ].x = 327; 
	punchRight[ 3 ].y = 1127; 
	punchRight[ 3 ].w = 126; 
	punchRight[ 3 ].h = 206;

	punchRight[ 4 ].x = 453; 
	punchRight[ 4 ].y = 1127; 
	punchRight[ 4 ].w = 122; 
	punchRight[ 4 ].h = 206;

	punchLeft[ 0 ].x = 0; 
	punchLeft[ 0 ].y = 4336; 
	punchLeft[ 0 ].w = 81; 
	punchLeft[ 0 ].h = 206;

	punchLeft[ 1 ].x = 81; 
	punchLeft[ 1 ].y = 4336; 
	punchLeft[ 1 ].w = 104; 
	punchLeft[ 1 ].h = 206;

	punchLeft[ 2 ].x = 185; 
	punchLeft[ 2 ].y = 4336; 
	punchLeft[ 2 ].w = 142; 
	punchLeft[ 2 ].h = 206;

	punchLeft[ 3 ].x = 327; 
	punchLeft[ 3 ].y = 4336; 
	punchLeft[ 3 ].w = 126; 
	punchLeft[ 3 ].h = 206;

	punchLeft[ 4 ].x = 453; 
	punchLeft[ 4 ].y = 4336; 
	punchLeft[ 4 ].w = 122; 
	punchLeft[ 4 ].h = 206;
}

//Clip the sprites for the character to kick, facing either right or left
void Lebron::clipKick(){
	kickRight[ 0 ].x = 0; 
	kickRight[ 0 ].y = 1850; 
	kickRight[ 0 ].w = 88; 
	kickRight[ 0 ].h = 210;	

	kickRight[ 1 ].x = 88; 
	kickRight[ 1 ].y = 1850; 
	kickRight[ 1 ].w = 97; 
	kickRight[ 1 ].h = 210;	

	kickRight[ 2 ].x = 185; 
	kickRight[ 2 ].y = 1850; 
	kickRight[ 2 ].w = 83; 
	kickRight[ 2 ].h = 210;	

	kickRight[ 3 ].x = 268; 
	kickRight[ 3 ].y = 1850; 
	kickRight[ 3 ].w = 107; 
	kickRight[ 3 ].h = 210;	

	kickRight[ 4 ].x = 375; 
	kickRight[ 4 ].y = 1850; 
	kickRight[ 4 ].w = 153; 
	kickRight[ 4 ].h = 210;	

	kickRight[ 5 ].x = 528; 
	kickRight[ 5 ].y = 1850; 
	kickRight[ 5 ].w = 133; 
	kickRight[ 5 ].h = 210;	

	kickRight[ 6 ].x = 661; 
	kickRight[ 6 ].y = 1850; 
	kickRight[ 6 ].w = 76; 
	kickRight[ 6 ].h = 210;	

	kickRight[ 7 ].x = 737; 
	kickRight[ 7 ].y = 1850; 
	kickRight[ 7 ].w = 103; 
	kickRight[ 7 ].h = 210;	

	kickLeft[ 0 ].x = 0; 
	kickLeft[ 0 ].y = 5059; 
	kickLeft[ 0 ].w = 88; 
	kickLeft[ 0 ].h = 210;	

	kickLeft[ 1 ].x = 88; 
	kickLeft[ 1 ].y = 5059; 
	kickLeft[ 1 ].w = 97; 
	kickLeft[ 1 ].h = 210;	

	kickLeft[ 2 ].x = 185; 
	kickLeft[ 2 ].y = 5059; 
	kickLeft[ 2 ].w = 83; 
	kickLeft[ 2 ].h = 210;	

	kickLeft[ 3 ].x = 268; 
	kickLeft[ 3 ].y = 5059; 
	kickLeft[ 3 ].w = 107; 
	kickLeft[ 3 ].h = 210;	

	kickLeft[ 4 ].x = 375; 
	kickLeft[ 4 ].y = 5059; 
	kickLeft[ 4 ].w = 153; 
	kickLeft[ 4 ].h = 210;	

	kickLeft[ 5 ].x = 528; 
	kickLeft[ 5 ].y = 5059; 
	kickLeft[ 5 ].w = 133; 
	kickLeft[ 5 ].h = 210;	

	kickLeft[ 6 ].x = 661; 
	kickLeft[ 6 ].y = 5059; 
	kickLeft[ 6 ].w = 76; 
	kickLeft[ 6 ].h = 210;	

	kickLeft[ 7 ].x = 737; 
	kickLeft[ 7 ].y = 5059; 
	kickLeft[ 7 ].w = 103; 
	kickLeft[ 7 ].h = 210;
}

//Clip the sprites for the character to block, facing either right or left
void Lebron::clipBlock(){
	blockRight[ 0 ].x = 0; 
	blockRight[ 0 ].y = 2691; 
	blockRight[ 0 ].w = 76; 
	blockRight[ 0 ].h = 195;

	blockRight[ 1 ].x = 76; 
	blockRight[ 1 ].y = 2691; 
	blockRight[ 1 ].w = 74; 
	blockRight[ 1 ].h = 195;

	blockRight[ 2 ].x = 150; 
	blockRight[ 2 ].y = 2691; 
	blockRight[ 2 ].w = 86; 
	blockRight[ 2 ].h = 195;

	blockLeft[ 0 ].x = 0; 
	blockLeft[ 0 ].y = 5900; 
	blockLeft[ 0 ].w = 76; 
	blockLeft[ 0 ].h = 195;

	blockLeft[ 1 ].x = 76; 
	blockLeft[ 1 ].y = 5900; 
	blockLeft[ 1 ].w = 74; 
	blockLeft[ 1 ].h = 195;

	blockLeft[ 2 ].x = 150; 
	blockLeft[ 2 ].y = 5900; 
	blockLeft[ 2 ].w = 86; 
	blockLeft[ 2 ].h = 195;
}

//Clip the sprites for the character to die, facing either right or left
void Lebron::clipDeath(){
	deadRight[ 0 ].x = 0; 
	deadRight[ 0 ].y = 3028; 
	deadRight[ 0 ].w = 46; 
	deadRight[ 0 ].h = 181;

	deadRight[ 1 ].x = 46; 
	deadRight[ 1 ].y = 3028; 
	deadRight[ 1 ].w = 43; 
	deadRight[ 1 ].h = 181;

	deadRight[ 2 ].x = 89; 
	deadRight[ 2 ].y = 3028; 
	deadRight[ 2 ].w = 59; 
	deadRight[ 2 ].h = 181;

	deadRight[ 3 ].x = 148; 
	deadRight[ 3 ].y = 3028; 
	deadRight[ 3 ].w = 92; 
	deadRight[ 3 ].h = 181;

	deadRight[ 4 ].x = 240; 
	deadRight[ 4 ].y = 3028; 
	deadRight[ 4 ].w = 136; 
	deadRight[ 4 ].h = 181;

	deadRight[ 5 ].x = 376; 
	deadRight[ 5 ].y = 3028; 
	deadRight[ 5 ].w = 164; 
	deadRight[ 5 ].h = 181;

	deadRight[ 6 ].x = 540; 
	deadRight[ 6 ].y = 3028; 
	deadRight[ 6 ].w = 171; 
	deadRight[ 6 ].h = 181;

	deadRight[ 7 ].x = 711; 
	deadRight[ 7 ].y = 3028; 
	deadRight[ 7 ].w = 180; 
	deadRight[ 7 ].h = 181;

	deadLeft[ 0 ].x = 0; 
	deadLeft[ 0 ].y = 6237; 
	deadLeft[ 0 ].w = 46; 
	deadLeft[ 0 ].h = 181;

	deadLeft[ 1 ].x = 46; 
	deadLeft[ 1 ].y = 6237; 
	deadLeft[ 1 ].w = 43; 
	deadLeft[ 1 ].h = 181;

	deadLeft[ 2 ].x = 89; 
	deadLeft[ 2 ].y = 6237; 
	deadLeft[ 2 ].w = 59; 
	deadLeft[ 2 ].h = 181;

	deadLeft[ 3 ].x = 148; 
	deadLeft[ 3 ].y = 6237; 
	deadLeft[ 3 ].w = 92; 
	deadLeft[ 3 ].h = 181;

	deadLeft[ 4 ].x = 240; 
	deadLeft[ 4 ].y = 6237; 
	deadLeft[ 4 ].w = 136; 
	deadLeft[ 4 ].h = 181;

	deadLeft[ 5 ].x = 376; 
	deadLeft[ 5 ].y = 6237; 
	deadLeft[ 5 ].w = 164; 
	deadLeft[ 5 ].h = 181;

	deadLeft[ 6 ].x = 540; 
	deadLeft[ 6 ].y = 6237; 
	deadLeft[ 6 ].w = 171; 
	deadLeft[ 6 ].h = 181;

	deadLeft[ 7 ].x = 711; 
	deadLeft[ 7 ].y = 6237; 
	deadLeft[ 7 ].w = 180; 
	deadLeft[ 7 ].h = 181;
}

//Display the dot
void Lebron::show(SDL_Surface* destination){
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
		if(status == 0 && frame >= 10){
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
