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
		Lebron(int = 400, int = 600, int = 1);
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

Lebron::Lebron(int xcoord, int ycoord, int walk) : Character(xcoord, ycoord, walk){}

//Clip the sprites for the character to stand, facing either right or left
void Lebron::clipStand(){
	standRight[ 0 ].x = 0; 
	standRight[ 0 ].y = 0; 
	standRight[ 0 ].w = 81; 
	standRight[ 0 ].h = 200;

	standRight[ 1 ].x = 81; 
	standRight[ 1 ].y = 0; 
	standRight[ 1 ].w = 83; 
	standRight[ 1 ].h = 200;

	standRight[ 2 ].x = 164; 
	standRight[ 2 ].y = 0; 
	standRight[ 2 ].w = 80; 
	standRight[ 2 ].h = 200;

	standRight[ 3 ].x = 244; 
	standRight[ 3 ].y = 0; 
	standRight[ 3 ].w = 83; 
	standRight[ 3 ].h = 200;

	standRight[ 4 ].x = 327; 
	standRight[ 4 ].y = 0; 
	standRight[ 4 ].w = 84; 
	standRight[ 4 ].h = 200;

	standRight[ 5 ].x = 411; 
	standRight[ 5 ].y = 0; 
	standRight[ 5 ].w = 84; 
	standRight[ 5 ].h = 200;

	standRight[ 6 ].x = 495; 
	standRight[ 6 ].y = 0; 
	standRight[ 6 ].w = 84; 
	standRight[ 6 ].h = 200;

	standRight[ 7 ].x = 579; 
	standRight[ 7 ].y = 0; 
	standRight[ 7 ].w = 81; 
	standRight[ 7 ].h = 200;

	standRight[ 8 ].x = 660; 
	standRight[ 8 ].y = 0; 
	standRight[ 8 ].w = 82; 
	standRight[ 8 ].h = 200;

	standLeft[ 0 ].x = 0; 
	standLeft[ 0 ].y = 3053; 
	standLeft[ 0 ].w = 81; 
	standLeft[ 0 ].h = 185;

	standLeft[ 1 ].x = 81; 
	standLeft[ 1 ].y = 3053; 
	standLeft[ 1 ].w = 83; 
	standLeft[ 1 ].h = 185;

	standLeft[ 2 ].x = 164; 
	standLeft[ 2 ].y = 3053; 
	standLeft[ 2 ].w = 80; 
	standLeft[ 2 ].h = 185;

	standLeft[ 3 ].x = 244; 
	standLeft[ 3 ].y = 3053; 
	standLeft[ 3 ].w = 83; 
	standLeft[ 3 ].h = 185;

	standLeft[ 4 ].x = 327; 
	standLeft[ 4 ].y = 3053; 
	standLeft[ 4 ].w = 84; 
	standLeft[ 4 ].h = 185;

	standLeft[ 5 ].x = 411; 
	standLeft[ 5 ].y = 3053; 
	standLeft[ 5 ].w = 84; 
	standLeft[ 5 ].h = 185;

	standLeft[ 6 ].x = 495; 
	standLeft[ 6 ].y = 3053; 
	standLeft[ 6 ].w = 84; 
	standLeft[ 6 ].h = 185;

	standLeft[ 7 ].x = 579; 
	standLeft[ 7 ].y = 3053; 
	standLeft[ 7 ].w = 81; 
	standLeft[ 7 ].h = 185;

	standLeft[ 8 ].x = 660; 
	standLeft[ 8 ].y = 3053; 
	standLeft[ 8 ].w = 82; 
	standLeft[ 8 ].h = 185;


}

//Clip the sprites for the character to walk, facing either right or left
void Lebron::clipWalk(){
	walkRight[ 0 ].x = 0; 
	walkRight[ 0 ].y = 200; 
	walkRight[ 0 ].w = 83; 
	walkRight[ 0 ].h = 200;

	walkRight[ 1 ].x = 83; 
	walkRight[ 1 ].y = 200; 
	walkRight[ 1 ].w = 83; 
	walkRight[ 1 ].h = 200;

	walkRight[ 2 ].x = 166; 
	walkRight[ 2 ].y = 200; 
	walkRight[ 2 ].w = 80; 
	walkRight[ 2 ].h = 200;

	walkRight[ 3 ].x = 246; 
	walkRight[ 3 ].y = 200; 
	walkRight[ 3 ].w = 82; 
	walkRight[ 3 ].h = 200;

	walkRight[ 4 ].x = 328; 
	walkRight[ 4 ].y = 200; 
	walkRight[ 4 ].w = 83; 
	walkRight[ 4 ].h = 200;

	walkRight[ 5 ].x = 411; 
	walkRight[ 5 ].y = 200; 
	walkRight[ 5 ].w = 82; 
	walkRight[ 5 ].h = 200;

	walkRight[ 6 ].x = 493; 
	walkRight[ 6 ].y = 200; 
	walkRight[ 6 ].w = 82; 
	walkRight[ 6 ].h = 200;

	walkRight[ 7 ].x = 575; 
	walkRight[ 7 ].y = 200; 
	walkRight[ 7 ].w = 82; 
	walkRight[ 7 ].h = 200;

	walkRight[ 8 ].x = 657; 
	walkRight[ 8 ].y = 200; 
	walkRight[ 8 ].w = 89; 
	walkRight[ 8 ].h = 200;

	walkLeft[ 0 ].x = 0; 
	walkLeft[ 0 ].y = 3253; 
	walkLeft[ 0 ].w = 83; 
	walkLeft[ 0 ].h = 200;

	walkLeft[ 1 ].x = 83; 
	walkLeft[ 1 ].y = 3253; 
	walkLeft[ 1 ].w = 83; 
	walkLeft[ 1 ].h = 200;

	walkLeft[ 2 ].x = 166; 
	walkLeft[ 2 ].y = 3253; 
	walkLeft[ 2 ].w = 80; 
	walkLeft[ 2 ].h = 200;

	walkLeft[ 3 ].x = 246; 
	walkLeft[ 3 ].y = 3253; 
	walkLeft[ 3 ].w = 82; 
	walkLeft[ 3 ].h = 200;

	walkLeft[ 4 ].x = 328; 
	walkLeft[ 4 ].y = 3253; 
	walkLeft[ 4 ].w = 83; 
	walkLeft[ 4 ].h = 200;

	walkLeft[ 5 ].x = 411; 
	walkLeft[ 5 ].y = 3253; 
	walkLeft[ 5 ].w = 82; 
	walkLeft[ 5 ].h = 200;

	walkLeft[ 6 ].x = 493; 
	walkLeft[ 6 ].y = 3253; 
	walkLeft[ 6 ].w = 82; 
	walkLeft[ 6 ].h = 200;

	walkLeft[ 7 ].x = 575; 
	walkLeft[ 7 ].y = 3253; 
	walkLeft[ 7 ].w = 82; 
	walkLeft[ 7 ].h = 200;

	walkLeft[ 8 ].x = 657; 
	walkLeft[ 8 ].y = 3253; 
	walkLeft[ 8 ].w = 89; 
	walkLeft[ 8 ].h = 200;

	
}

//Clip the sprites for the character to punch, facing either right or left
void Lebron::clipPunch(){
	punchRight[ 0 ].x = 0; 
	punchRight[ 0 ].y = 1103; 
	punchRight[ 0 ].w = 68; 
	punchRight[ 0 ].h = 194;

	punchRight[ 1 ].x = 68; 
	punchRight[ 1 ].y = 1103; 
	punchRight[ 1 ].w = 88; 
	punchRight[ 1 ].h = 194;

	punchRight[ 2 ].x = 156; 
	punchRight[ 2 ].y = 1103; 
	punchRight[ 2 ].w = 126; 
	punchRight[ 2 ].h = 194;

	punchRight[ 3 ].x = 282; 
	punchRight[ 3 ].y = 1103; 
	punchRight[ 3 ].w = 107; 
	punchRight[ 3 ].h = 194;

	punchRight[ 4 ].x = 389; 
	punchRight[ 4 ].y = 1103; 
	punchRight[ 4 ].w = 102; 
	punchRight[ 4 ].h = 194;

	punchLeft[ 0 ].x = 0; 
	punchLeft[ 0 ].y = 4141; 
	punchLeft[ 0 ].w = 68; 
	punchLeft[ 0 ].h = 194;

	punchLeft[ 1 ].x = 68; 
	punchLeft[ 1 ].y = 4141; 
	punchLeft[ 1 ].w = 88; 
	punchLeft[ 1 ].h = 194;

	punchLeft[ 2 ].x = 156; 
	punchLeft[ 2 ].y = 4141; 
	punchLeft[ 2 ].w = 126; 
	punchLeft[ 2 ].h = 194;

	punchLeft[ 3 ].x = 282; 
	punchLeft[ 3 ].y = 4141; 
	punchLeft[ 3 ].w = 107; 
	punchLeft[ 3 ].h = 194;

	punchLeft[ 4 ].x = 389; 
	punchLeft[ 4 ].y = 4141; 
	punchLeft[ 4 ].w = 102; 
	punchLeft[ 4 ].h = 194;
}

//Clip the sprites for the character to kick, facing either right or left
void Lebron::clipKick(){
	kickRight[ 0 ].x = 0; 
	kickRight[ 0 ].y = 1763; 
	kickRight[ 0 ].w = 87; 
	kickRight[ 0 ].h = 183;	

	kickRight[ 1 ].x = 87; 
	kickRight[ 1 ].y = 1763; 
	kickRight[ 1 ].w = 91; 
	kickRight[ 1 ].h = 183;	

	kickRight[ 2 ].x = 178; 
	kickRight[ 2 ].y = 1763; 
	kickRight[ 2 ].w = 95; 
	kickRight[ 2 ].h = 183;	

	kickRight[ 3 ].x = 273; 
	kickRight[ 3 ].y = 1763; 
	kickRight[ 3 ].w = 103; 
	kickRight[ 3 ].h = 183;	

	kickRight[ 4 ].x = 376; 
	kickRight[ 4 ].y = 1763; 
	kickRight[ 4 ].w = 127; 
	kickRight[ 4 ].h = 183;	

	kickRight[ 5 ].x = 503; 
	kickRight[ 5 ].y = 1763; 
	kickRight[ 5 ].w = 93; 
	kickRight[ 5 ].h = 183;	

	kickRight[ 6 ].x = 596; 
	kickRight[ 6 ].y = 1763; 
	kickRight[ 6 ].w = 61; 
	kickRight[ 6 ].h = 183;	

	kickRight[ 7 ].x = 657; 
	kickRight[ 7 ].y = 1763; 
	kickRight[ 7 ].w = 74; 
	kickRight[ 7 ].h = 183;	

	kickLeft[ 0 ].x = 0; 
	kickLeft[ 0 ].y = 4801; 
	kickLeft[ 0 ].w = 87; 
	kickLeft[ 0 ].h = 183;	

	kickLeft[ 1 ].x = 87; 
	kickLeft[ 1 ].y = 4801; 
	kickLeft[ 1 ].w = 91; 
	kickLeft[ 1 ].h = 183;	

	kickLeft[ 2 ].x = 178; 
	kickLeft[ 2 ].y = 4801; 
	kickLeft[ 2 ].w = 95; 
	kickLeft[ 2 ].h = 183;	

	kickLeft[ 3 ].x = 273; 
	kickLeft[ 3 ].y = 4801; 
	kickLeft[ 3 ].w = 103; 
	kickLeft[ 3 ].h = 183;	

	kickLeft[ 4 ].x = 376; 
	kickLeft[ 4 ].y = 4801; 
	kickLeft[ 4 ].w = 127; 
	kickLeft[ 4 ].h = 183;	

	kickLeft[ 5 ].x = 503; 
	kickLeft[ 5 ].y = 4801; 
	kickLeft[ 5 ].w = 93; 
	kickLeft[ 5 ].h = 183;	

	kickLeft[ 6 ].x = 596; 
	kickLeft[ 6 ].y = 4801; 
	kickLeft[ 6 ].w = 61; 
	kickLeft[ 6 ].h = 183;	

	kickLeft[ 7 ].x = 657; 
	kickLeft[ 7 ].y = 4801; 
	kickLeft[ 7 ].w = 74; 
	kickLeft[ 7 ].h = 183;	
}

//Clip the sprites for the character to block, facing either right or left
void Lebron::clipBlock(){
	blockRight[ 0 ].x = 0; 
	blockRight[ 0 ].y = 2550; 
	blockRight[ 0 ].w = 73; 
	blockRight[ 0 ].h = 179;

	blockRight[ 1 ].x = 73; 
	blockRight[ 1 ].y = 2550; 
	blockRight[ 1 ].w = 72; 
	blockRight[ 1 ].h = 179;

	blockRight[ 2 ].x = 145; 
	blockRight[ 2 ].y = 2550; 
	blockRight[ 2 ].w = 69; 
	blockRight[ 2 ].h = 179;

	blockLeft[ 0 ].x = 0; 
	blockLeft[ 0 ].y = 5588; 
	blockLeft[ 0 ].w = 73; 
	blockLeft[ 0 ].h = 179;

	blockLeft[ 1 ].x = 73; 
	blockLeft[ 1 ].y = 5588; 
	blockLeft[ 1 ].w = 72; 
	blockLeft[ 1 ].h = 179;

	blockLeft[ 2 ].x = 145; 
	blockLeft[ 2 ].y = 5588; 
	blockLeft[ 2 ].w = 69; 
	blockLeft[ 2 ].h = 179;
}

//Clip the sprites for the character to die, facing either right or left
void Lebron::clipDeath(){
	deadRight[ 0 ].x = 0; 
	deadRight[ 0 ].y = 2866; 
	deadRight[ 0 ].w = 39; 
	deadRight[ 0 ].h = 187;

	deadRight[ 1 ].x = 39; 
	deadRight[ 1 ].y = 2866; 
	deadRight[ 1 ].w = 69; 
	deadRight[ 1 ].h = 187;

	deadRight[ 2 ].x = 108; 
	deadRight[ 2 ].y = 2866; 
	deadRight[ 2 ].w = 40; 
	deadRight[ 2 ].h = 187;

	deadRight[ 3 ].x = 148; 
	deadRight[ 3 ].y = 2866; 
	deadRight[ 3 ].w = 66; 
	deadRight[ 3 ].h = 187;

	deadRight[ 4 ].x = 214; 
	deadRight[ 4 ].y = 2866; 
	deadRight[ 4 ].w = 136; 
	deadRight[ 4 ].h = 187;

	deadRight[ 5 ].x = 350; 
	deadRight[ 5 ].y = 2866; 
	deadRight[ 5 ].w = 169; 
	deadRight[ 5 ].h = 187;

	deadLeft[ 0 ].x = 0; 
	deadLeft[ 0 ].y = 5904; 
	deadLeft[ 0 ].w = 39; 
	deadLeft[ 0 ].h = 187;

	deadLeft[ 1 ].x = 39; 
	deadLeft[ 1 ].y = 5904; 
	deadLeft[ 1 ].w = 69; 
	deadLeft[ 1 ].h = 187;

	deadLeft[ 2 ].x = 108; 
	deadLeft[ 2 ].y = 5904; 
	deadLeft[ 2 ].w = 40; 
	deadLeft[ 2 ].h = 187;

	deadLeft[ 3 ].x = 148; 
	deadLeft[ 3 ].y = 5904; 
	deadLeft[ 3 ].w = 66; 
	deadLeft[ 3 ].h = 187;

	deadLeft[ 4 ].x = 214; 
	deadLeft[ 4 ].y = 5904; 
	deadLeft[ 4 ].w = 136; 
	deadLeft[ 4 ].h = 187;

	deadLeft[ 5 ].x = 350; 
	deadLeft[ 5 ].y = 5904; 
	deadLeft[ 5 ].w = 169; 
	deadLeft[ 5 ].h = 187;
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
