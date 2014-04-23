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

#include "Timer.h"

using namespace std;

//BLOB CLASS DEFINITION

#ifndef CHARACTER_H
#define CHARACTER_H

class Character{
	public:
		Character(int = 400, int = 450, int = 1); //Constructor
		void input1(Character &); //Make the desired move according to key pressed (Character 1)
		void input2(Character &); //Make the desired move according to key pressed (Character 2)
		void move1(Character &); //Move the character
		void move2(Character &); //Move the character	
		virtual void show(SDL_Surface*) = 0; //Show the character on desired surface
		void free(); //Free the character's space in memory
		void show_health(int, int); //Display the current character's health bar using FillRect
		void punch(Character &); //Punch the opposing character, if close enough
		void kick(Character &); //Kick the opposing character, if close enough
		int isDone(); //Check to see if the game is over
		virtual void clipStand() = 0; //Clip the sprite sheet for the character to stand
		virtual void clipWalk() = 0; //Clip the sprite sheet for the character to walk
		virtual void clipPunch() = 0; //Clip the sprite sheet for the character to punch
		virtual void clipKick() = 0; //Clip the sprite sheet for the character to kick
		virtual void clipBlock() = 0; //Clip the sprite sheet for the character to block
		virtual void clipDeath() = 0; //Clip the sprite sheet for the character to die
		void setStatus(int); //Set the status of the character
		void setFrame(int); //Set the current frame for animation

	protected:
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
Character::Character(int xcoord, int ycoord, int walk){
	x = xcoord; //x-coordinate
	y = ycoord; //y-coordinate
	walkWay = walk; //Which way character is facing, 1 for right and 0 for left
	xVel = 0; //x velocity
	yVel = 0; //y velocity
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

//Make a desired move for Character 1
void Character::input1(Character &otherDot){
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
void Character::input2(Character &otherDot){
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
void Character::move1(Character &otherDot){
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
void Character::move2(Character &otherDot){
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
void Character::show_health(int x, int y){
	//Draw a rectangle whose length is 4 times the character's health (for better visability)
	//and width is 30 at (x,y) with a light green color (HEX: 1FEB11)
	FillRect(x, y, health*4, 30, 0x1FEB11); 
	
	if(health < 100){ //If character is not at full health

		//Draw the remainder of the rectangle with a dark red color (HEX: 660000)
		FillRect(x + health*4, y, (400 - (health*4)), 30, 0x660000);
	}
}

//Punch the other character and deplete their health if no more than 100 pixels away
void Character::punch(Character &otherDot){
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
void Character::kick(Character &otherDot){
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

//Set the character's status
void Character::setStatus(int userStatus){
	status = userStatus;
}

//Set the current frame for animation
void Character::setFrame(int userFrame){
	frame = userFrame;
}

//Free the dot in memory
void Character::free(){
	SDL_FreeSurface(image);
}

//Check if game is over (i.e someone has run out of health)
int Character::isDone(){
	if(health <= 0){ //If character's health is depleted
		return 1; //Game is over
	}
	return 0; //Otherwise, game is not over
}


#endif
