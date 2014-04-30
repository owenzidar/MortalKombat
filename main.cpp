/*
Kevin Epp, Mitch Patin, Owen Zidar  CSE 20212
Final Project  main.cpp
Main function that implements and plays a mock Mortal Kombat game
The two characters can move independently and punch and kick each other to deplete health, as well as block attacks
*/

//Libraries, including appropriate SDL libraries
#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include <string>
#include <sstream>

//Include Timer class, Character base class, and all classes inheriting from Character
#include "Timer.h"
#include "Character.h"
#include "CharlesBarkley.h"
#include "Conan.h"
#include "Lebron.h"
#include "Leprechaun.h"
#include "LadyGaga.h"
#include "Miley.h"

//Include Menu class
#include "Menu.h"

using namespace std;

int main(int argc, char* args[]){
	int choice; //Which background the users choose to play on
	int choice1, choice2; //Which player each user chooses to play as
	string backChoice; //String that contains the image location of the desired background
	bool quit = false; //Checks if user quit
	int count = 0; //Used to display the animation of the character dying
	int winner = 0; //1 if player 1 wins, 2 if player 2 wins
	int Wins; //If a player has won (i.e. game is not quit), free the screen displaying winner
	int* a; //Pointer to an array of ints, used to obtain level and character choices from Menu object

	Menu test; //Instantiate Menu object
	a = test.go(); //Display Menu to get user input, 3 numbers are outputted to a
	choice = a[0]; //Background choice (0-2)
	choice1 = a[1]; //Player 1 Character choice (0-5)
	choice2 = a[2]; //Player 2 Character choice (0-5)

	//Assign appropriate image location to backChoice depending on user input
	switch(choice){
		case 0: //Golden Dome background
			backChoice = "dome.bmp";
			break;
		case 1: //Notre Dame Stadium background
			backChoice = "stadium.bmp";
			break;
		case 2: //Mortal Kombat background
			backChoice = "images.bmp"; 
			break;
		default: //Invalid input assumes Mortal Kombat background
			cout << "Wrong input. Assuming you want to play on MK ground." << endl;
			backChoice = "images.bmp";
			sleep(2);
			break;
	}

	Character *myDot1; //Base class pointer for Player 1
	Character *myDot2; //Base class pointer for Player 2

	//Assign appropriate character to Player 1 based on user input
	switch(choice1){
		case 0: //Instantiate Charles Barkley
			myDot1 = new CharlesBarkley(400,600,1);
			myDot1->setImage("CharlesBarkley.png"); //Sprite sheet
			myDot1->setWinImage("images/charles.png"); //Image to use if character wins
			break;
		case 1: //Instantiate Lebron James
			myDot1 = new Lebron(400,600,1);
			myDot1->setImage("LebronJames.png"); 
			myDot1->setWinImage("images/lebron.png");
			break;
		case 2: //Instantiate Conan O'Brien
			myDot1 = new Conan(400,600,1);
			myDot1->setImage("Conan.png");
			myDot1->setWinImage("images/conan.png");
			break;
		case 3: //Instantiate Lady Gaga
			myDot1 = new LadyGaga(400,600,1);
			myDot1->setImage("LadyGaga.png");
			myDot1->setWinImage("images/gaga.png");
			break;
		case 4: //Instantiate the ND Leprechaun
			myDot1 = new Leprechaun(400,600,1);
			myDot1->setImage("Leprechaun.png");
			myDot1->setWinImage("images/leprechaun.png");
			break;
		case 5: //Instantiate Miley Cyrus
			myDot1 = new Miley(400,600,1);
			myDot1->setImage("MileyCyrus.png");
			myDot1->setWinImage("images/miley.png");
			break;
		default:
			cout << "Invalid input. Quitting." << endl;
			quit = true;
			break; 
	}

	//Assign appropriate character to Player 2 based on user input
	switch(choice2){
		case 0: //Instantiate Charles Barkley
			myDot2 = new CharlesBarkley(800, 600, 0);
			myDot2->setImage("CharlesBarkley.png"); //Sprite sheet
			myDot2->setWinImage("images/charles.png"); //Image to use if character wins
			break;
		case 1: //Instantiate Lebron James
			myDot2 = new Lebron(800, 600, 0);
			myDot2->setImage("LebronJames.png");
			myDot2->setWinImage("images/lebron.png");
			break;
		case 2: //Instantiate Conan O'Brien
			myDot2 = new Conan(800, 600, 0);
			myDot2->setImage("Conan.png");
			myDot2->setWinImage("images/conan.png");
			break;
		case 3: //Instantiate Lady Gaga
			myDot2 = new LadyGaga(800, 600, 0);
			myDot2->setImage("LadyGaga.png");
			myDot2->setWinImage("images/gaga.png");
			break;
		case 4: //Instantiate the ND Leprechaun
			myDot2 = new Leprechaun(800, 600, 0);
			myDot2->setImage("Leprechaun.png");
			myDot2->setWinImage("images/leprechaun.png");
			break;
		case 5: //Instantiate Miley Cyrus
			myDot2 = new Miley(800, 600, 0);
			myDot2->setImage("MileyCyrus.png");
			myDot2->setWinImage("images/miley.png");
			break;
		default:
			cout << "Invalid input. Quitting." << endl;
			quit = true;
			break;
	}

	//If SDL couldn't intialize, quit
	if(init() == false){
		return 1;
	}

	Timer fps; //Instantiate a timer to help slow down movements of characters for easier gameplay	

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
				winner = 2; //Player 2 is winner
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
			if(count >= 7 && count != 10){
				quit = true; //Exit while loop next time through
				sleep(1);
				winner = 1; //Player 1 is winner
			}
		}

		//Delay the loop so the animation runs at a normal speed
		if( fps.get_ticks() < 1000 / fps.getFRAMES_PER_SECOND() ){
            		SDL_Delay( ( 1000 / fps.getFRAMES_PER_SECOND() ) - fps.get_ticks() );
        	}	
	}

	SDL_Quit(); //Free screen and quit SDL

	if(winner == 1){ //If Player 1 won
		Wins = myDot1->wins(winner); //Display win screen for Player 1 (Wins now equals 1)
	}else if (winner == 2){ //If Player 2 won
		Wins = myDot2->wins(winner); //Display win screen for Player 2 (Wins now equals 1)
	}
	if(Wins == 1) //If Wins = 1
		SDL_Quit(); //Free screen and quit SDL

	myDot1->free(); //Free character 1
	myDot2->free(); //Free character 2
	
	return 0;
}
