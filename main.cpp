/*
Kevin Epp  CSE 20212
Lab 10  main.cpp
Main function that implements two instances of Charles Barkley as characters and plays a mock Mortal Kombat game
The two characters can move independently and punch and kick each other to deplete health, as well as block attacks
*/

#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include <string>
#include <sstream>

#include "Timer.h"
#include "Character.h"
#include "CharlesBarkley.h"
#include "Conan.h"
#include "Lebron.h"
#include "Leprechaun.h"
#include "LadyGaga.h"
#include "Miley.h"

#include "Menu.h"

using namespace std;

int main(int argc, char* args[]){
	int choice ,choice1, choice2; //Which background the user chooses to play on
	string backChoice; //String that contains the image location of the desired background
	bool quit = false; //Checks if user quit
	int count = 0; //Used to display the animation of the character dying
	int* a;

	string Player1Wins = "Player 1 Wins.bmp";

	Menu test;
	a = test.go();
	choice = a[0];
	choice1 = a[1];
	choice2 = a[2];

	//Assign appropriate image location to backChoice depending on user input
	switch(choice){
		case 2: //Mortal Kombat background
			backChoice = "images.bmp"; 
			break;
		case 1: //Notre Dame Stadium background
			backChoice = "stadium.bmp";
			break;
		case 0: //Golden Dome background
			backChoice = "dome.bmp";
			break;
		default: //Invalid input assumes Mortal Kombat background
			cout << "Wrong input. Assuming you want to play on MK ground." << endl;
			backChoice = "images.bmp";
			sleep(2);
			break;
	}

	Character *myDot1;
	Character *myDot2;

	switch(choice1){
		case 0:
			myDot1 = new CharlesBarkley(400,600,1);
			myDot1->setImage("CharlesBarkley.png");
			break;
		case 2:
			myDot1 = new Conan(400,600,1);
			myDot1->setImage("Conan.png");
			break;
		case 1:
			myDot1 = new Lebron(400,600,1);
			myDot1->setImage("LebronJames.png");
			break;
		case 4:
			myDot1 = new Leprechaun(400,600,1);
			myDot1->setImage("Leprechaun.png");
			break;
		case 3:
			myDot1 = new LadyGaga(400,600,1);
			myDot1->setImage("LadyGaga.png");
			break;
		case 5:
			myDot1 = new Miley(400,600,1);
			myDot1->setImage("MileyCyrus.png");
			break;
		default:
			cout << "Invalid input. Quitting." << endl;
			quit = true;
			break; 
	}

	switch(choice2){
		case 0:
			myDot2 = new CharlesBarkley(800, 600, 0);
			myDot2->setImage("CharlesBarkley.png");
			break;
		case 2:
			myDot2 = new Conan(800, 600, 0);
			myDot2->setImage("Conan.png");
			break;
		case 1:
			myDot2 = new Lebron(800, 600, 0);
			myDot2->setImage("LebronJames.png");
			break;
		case 4:
			myDot2 = new Leprechaun(800, 600, 0);
			myDot2->setImage("Leprechaun.png");
			break;
		case 3:
			myDot2 = new LadyGaga(800, 600, 0);
			myDot2->setImage("LadyGaga.png");
			break;
		case 5:
			myDot2 = new Miley(800, 600, 0);
			myDot2->setImage("MileyCyrus.png");
			break;
		default:
			cout << "Invalid input. Quitting." << endl;
			quit = true;
			break;
	}

cout << "Working!" << endl;

	//If SDL couldn't intialize, quit
	if(init() == false){
		return 1;
	}

	Timer fps; //Instantiate a timer to help slow down movements of characters for easier gameplay

	//CharlesBarkley myDot1(400,600, 1); //Initialize character 1
	//Miley myDot2(800,600, 0); //Inititalize character 2	

	//Clip the sprite sheet for each character standing
	myDot1->clipStand();
	myDot2->clipStand();

	//Clip the sprite sheet for each character walking
	myDot1->clipWalk();
	myDot2->clipWalk();

	//Clip the sprite sheet for each character punching
	myDot1->clipPunch();
	myDot2->clipPunch();

	//Clip the sprite sheet for each character kicking
	myDot1->clipKick();
	myDot2->clipKick();

	//Clip the sprite sheet for each character blocking
	myDot1->clipBlock();
	myDot2->clipBlock();

	//Clip the sprite sheet for each character dying
	myDot1->clipDeath();
	myDot2->clipDeath();

	while(quit == false){ //While user has not exited window
		fps.start(); //Start the timer
		background = load_image(backChoice); //load background image
		while(SDL_PollEvent(&event)){ //While there is an event happening
			myDot1->input1(myDot2); //Check if appropriate key was pressed and make desired move accordingly
			myDot2->input2(myDot1); //Check if appropriate key was pressed and make desired move accordingly
			if(event.type == SDL_QUIT){ //If user exited window
				quit = true; //Quit
			}
		}
		myDot1->move1(myDot2); //Move Player 1 horizontally as specified by the user
		myDot2->move2(myDot1); //Move Player 2 horizontally as specified by the user
		myDot1->show_health(50, 50); //Display health bar for character 1
		myDot2->show_health(750, 50); //Display health bar for character 2
		apply_surface(0,0,background,screen); //Display background on the screen
		myDot1->show(screen); //Display character 1 on the screen over background
		myDot2->show(screen); //Display character 2 on the screen over background

		//If screen could not be shown, quit
		if(SDL_Flip(screen) == -1){
			return 1;
		}
		SDL_FreeSurface(background); //Free the background
		//If Character 1 is out of health
		if(myDot1->isDone() == 1){
			myDot1->setStatus(5); //Set status to 5 so show() displays the animation of character dying

			//If first time through the loop, reset frame to 0 so animation starts from beginning
			if(count == 0){
				myDot1->setFrame(0);
			}

			count++; //Increase count

			//If count >= 7 (7 is number of sprite images needed to animate character dying), exit game
			if(count >= 7){
				quit = true; //Exit while loop next time through
				sleep(1);
				background = load_image(Player1Wins);
				cout << "Player 2 wins!!!" << endl; //Display Character 2 winning message
			}
		}

		//If Character 2 is out of health AND Character 1 is not out of health (Character 2 wins a tie)
		if(myDot2->isDone() == 1 && myDot1->isDone() != 1){
			myDot2->setStatus(5); //Set status to 5 so show() displays the animation of character dying

			//If first time through the loop, reset frame to 0 so animation starts from beginning
			if(count == 0){
				myDot2->setFrame(0);
			}

			count++; //Increase count

			//If count >= 7 (7 is number of sprite images needed to animate character dying), exit game
			if(count >= 7){
				quit = true; //Exit while loop next time through
				sleep(1);
				winBackground = load_image(Player1Wins);
				cout << "Player 1 wins!!!" << endl; //Display Character 1 winning message
			}
		}

		//Delay the loop so the animation runs at a normal speed
		if( fps.get_ticks() < 1000 / fps.getFRAMES_PER_SECOND() ){
            		SDL_Delay( ( 1000 / fps.getFRAMES_PER_SECOND() ) - fps.get_ticks() );
        	}	
	}
		
	

	//SDL_Quit(); //Free screen and quit SDL

	quit = false;

//myDot1->free(); //Free character 1
	//myDot2->free(); //Free character 2

	//SDL_FreeSurface(background); //Free the background
/*
	while(quit == false){
		//if(init() == false){
		//	return 1;
		//}

		
		//if(i == 0){
			//winBackground = load_image(backChoice);
			//cout << "Worked!" << endl;
			apply_surface(0,0,winBackground,screen); //Display background on the screen
			//cout << "Worked!" << endl;
			//i = 1;
		//}

		while(SDL_PollEvent(&event)){ //While there is an event happening
			if(event.type == SDL_QUIT){ //If user exited window
				SDL_FreeSurface(winBackground); //Free the background
				quit = true; //Quit
			}
		}
	}
*/

	myDot1->free(); //Free character 1
	myDot2->free(); //Free character 2

	SDL_Quit(); //Free screen and quit SDL
	
	return 0;
}
