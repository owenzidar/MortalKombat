#include "Menu.h"

using namespace std;

// constructor
Menu :: Menu(){
	//cout << "constructor" << endl;

		levelNum = 0;
		player1Num = 0;
		player2Num = 2;

	//The event structure
	SDL_Event event;
}


SDL_Surface * Menu :: load_image( std::string filename )
{
	//cout << "load_image" << endl;

    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized surface
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old surface
        SDL_FreeSurface( loadedImage );

        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }

    //Return the optimized surface
    return optimizedImage;
}

void Menu :: apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
	//cout << "apply_surface" << endl;
	
    //Holds offsets
    SDL_Rect offset;

    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

bool Menu :: init()
{
	//cout << "init" << endl;

    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Mortal Kombat - Celebrity", NULL );

    //If everything initialized fine
    return true;
}

bool Menu :: load_files()
{
	//cout << "load_files" << endl;

	//fill the level vector
	levels.push_back(load_image("images/dome_preview.png"));
	levels.push_back(load_image("images/stadium_preview.png"));
	levels.push_back(load_image("images/mk_preview.png"));

	//fill the players vector
	players.push_back(load_image("images/charles.png"));
	players.push_back(load_image("images/lebron.png"));
	players.push_back(load_image("images/conan.png"));		
	players.push_back(load_image("images/gaga.png"));
	players.push_back(load_image("images/leprechaun.png"));
	players.push_back(load_image("images/miley.png"));

	//Load the image
    menuScreen = load_image( "images/MenuScreen.png" );
    controlsScreen = load_image( "images/ControlsScreen.png" );

    //If everything loaded fine
    return true;
}

void Menu :: clean_up()
{
	//cout << "clean_up" << endl;
    //Free the surfaces
	SDL_FreeSurface( controlsScreen );
    SDL_FreeSurface( menuScreen );

    //Quit SDL
    SDL_Quit();
}

int* Menu :: go()
{
	//cout << "go" << endl;
	

    //Quit flag
    bool quit = false;

	//Bool controls screen (don't allow other keys to operate)
	bool control_screen = false;
	bool f_down = false;
	bool g_down = false;
	bool a_down = false;
	bool s_down = false;
	bool j_down = false;
	bool k_down = false;

	int a[3];
	a[0] = levelNum;
	a[1] = player1Num;
	a[2] = player2Num;

	int* array = a;
	
    //Initialize
    if( init() == false )
    {
        return array;
    }

    //Load the files
    if( load_files() == false )
    {
        return array;	
    }



    //While the user hasn't quit
    while( quit == false )
    {
		
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {
            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
				

        //Apply the background menuScreen
        apply_surface( 0, 0, menuScreen, screen );

		//Apply the levels surface
		apply_surface(450, 370,levels[levelNum], screen );

		//Apply the players surfaces
		apply_surface(97, 350,players[player1Num], screen );
		apply_surface(852, 350,players[player2Num], screen );

		
        //Get the keystates
        Uint8 *keystates = SDL_GetKeyState( NULL );


		//If space is pressed, display controls screen
        if( keystates[ SDLK_SPACE ] ) {
          	apply_surface( 0, 0, controlsScreen, screen);
			control_screen = true;
        }
		else
			control_screen=false;


		//
		if(control_screen==false){
			if(event.type == SDL_KEYDOWN){
				switch(event.key.keysym.sym){
					case SDLK_f:
						f_down = true;
						break;
					case SDLK_g:
						g_down = true;
						break;
					case SDLK_a:
						a_down = true;
						break;
					case SDLK_s:
						s_down = true;
						break;
					case SDLK_j:
						j_down = true;
						break;
					case SDLK_k:
						k_down = true;
						break;
					case SDLK_RETURN:
						a[0] = levelNum;
						a[1] = player1Num;
						a[2] = player2Num;
						array = a;
						quit = true;				
						break;
				}
			}
			else if(event.type == SDL_KEYUP){
				switch(event.key.keysym.sym){
					case SDLK_f:
						if (f_down == true)
							if(levelNum==0)
								levelNum=2;
							else
								levelNum--;
						f_down=false;
						break;
					case SDLK_g:
						if (g_down == true)
							if(levelNum==2)
								levelNum=0;
							else
								levelNum++;
						g_down=false;
						break;
					case SDLK_a:
						if (a_down == true)
							if(player1Num==0)
								player1Num=5;
							else
								player1Num--;
						a_down=false;
						break;
					case SDLK_s:
						if (s_down == true)
							if(player1Num==5)
								player1Num=0;
							else
								player1Num++;
						s_down=false;
						break;
					case SDLK_j:
						if (j_down == true)
							if(player2Num==0)
								player2Num=5;
							else
								player2Num--;
						j_down=false;
						break;
					case SDLK_k:
						if (k_down == true)
							if(player2Num==5)
								player2Num=0;
							else
								player2Num++;
						k_down=false;
						break;					
				}
			}
		}

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return array;
        }
    }

    //Clean up
    clean_up();

	return array;
}
