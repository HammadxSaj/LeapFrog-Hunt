#include "game.hpp"
#include "LeapFrog.hpp"
#include "drawing.hpp"

SDL_Renderer* Drawing::gRenderer = NULL;
SDL_Texture* Drawing::assets = NULL;
int static screentype;
bool Game::init()
{
	//Initialization flag
	bool success = true;


	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
			printf("Unable to open audio: %s\n", Mix_GetError());
			success = false;
		}

		//Create window
		gWindow = SDL_CreateWindow( "LeapFrog Hunt", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
			if( Drawing::gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

			}
		}
	}

	return success;
}

//This function loads the Splash Screen of the game.
bool Game::loadMedia()
{
	//Loading success flag
	bool success = true;
	music = Mix_LoadMUS("Frogger_Theme.wav");
	Mix_PlayMusic(music, -1);
    gTexture = loadTexture("FRONT.png");
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success = false;
    }
	return success;

	if (music = NULL){
		printf("failed to load the theme music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
}

//This function loads the assets and the background screen of the game where the assets appear.
bool Game::loadGame()
{
	//Loading success flag
	bool success = true;
	
	Drawing::assets = loadTexture("Frogger.png");
    gTexture = loadTexture("Background.png");
	if(Drawing::assets==NULL || gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

//This function loads the game won screen of the game.
bool Game::loadwonscreen()
{
	//Loading success flag
	bool success = true;
	music = Mix_LoadMUS("Frogger_Stage.wav");
	Mix_PlayMusic(music, -1);
    gTexture = loadTexture("GameWon.png");
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

//This function loads the game lost screen of the game.
bool Game::loadendscreen()
{
	//Loading success flag
	bool success = true;
	music = Mix_LoadMUS("frogger-time.wav");
	Mix_PlayMusic(music, -1);
    gTexture = loadTexture("GameOver.png");
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

//This function loads the game Instructions screen of the game.
bool Game::loadInstructions()
{
	//Loading success flag
	bool success = true;
    gTexture = loadTexture("Instructions.png");
	if(gTexture==NULL)
    {
        printf("Unable to run due to error: %s\n",SDL_GetError());
        success =false;
    }
	return success;
}

void Game::close()
{
	//Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets=NULL;
	SDL_DestroyTexture(gTexture);
	
	//Destroy window
	SDL_DestroyRenderer( Drawing::gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* Game::loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( Drawing::gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

//This function is responsible for the game logic and it creates the Leapfrog object responsible for the running of game.
void Game::run( )
{
	bool quit = false;
	SDL_Event e;
	LeapFrog leapfrog;

	while( !quit )
	{
		//Once all three healths are lost the game lost screen is loaded.
		if (leapfrog.objects.size()==43 && state == 1){
			state = 3;
			leapfrog.objectcheck = false;
			loadendscreen();
			}
		//Once the frog fills all the 5 holes the game won screen is loaded.
		else if (leapfrog.scores.size()==5 && state == 1){
			state = 4;
			loadwonscreen();
			}
		//Handle events on queue
		while( SDL_PollEvent( &e ) != 0 )
		{
			//User requests quit
			if( e.type == SDL_QUIT )
			{
				quit = true;
			}
			if(e.type == SDL_MOUSEBUTTONDOWN){
				int xMouse, yMouse;
				SDL_GetMouseState(&xMouse,&yMouse);
				leapfrog.createObject(xMouse, yMouse);
                //Upon tapping the Play button the game starts.
				if (state == 0 && xMouse > 368 && xMouse < 469 && yMouse > 386 && yMouse < 416){
					state = 1;
					loadGame();
				}
				//Upon tapping the instructions button the instructions screen is loaded.
				if (state == 0 && xMouse > 298 && xMouse < 469 && yMouse > 423 && yMouse < 475){
					state = 2;
					loadInstructions();
				}
				//It returns the game back to home screen and when the user taps play the game starts.
				if (state == 2 && xMouse > 165 && xMouse < 335 && yMouse > 411 && yMouse < 461){
					state = 0;
					loadMedia();
				}
				//It returns the user from the game lost screen to the home screen.
				if (state == 3 && xMouse >= 175 && xMouse<= 326 && yMouse >= 338 && yMouse <= 407){
					state = 0;
					loadMedia();
				}
				//It returns the user from the game won screen to the home screen.
				if (state == 4 && xMouse >= 300 && xMouse<= 450 && yMouse >= 380 && yMouse <= 447){
					state = 0;
					loadMedia();
				}
			}
			//These are the keyboard events.
			const Uint8* state = SDL_GetKeyboardState(NULL);
			if (state[SDL_SCANCODE_UP]){
				leapfrog.checkup = true;
				music = Mix_LoadMUS("JUMP.mp3");
				Mix_PlayMusic(music, 1);
			}
			if (state[SDL_SCANCODE_DOWN]){
				leapfrog.checkdown = true;
				music = Mix_LoadMUS("JUMP.mp3");
				Mix_PlayMusic(music, 1);
			}
			if (state[SDL_SCANCODE_RIGHT]){
				leapfrog.checkright = true;
				music = Mix_LoadMUS("JUMP.mp3");
				Mix_PlayMusic(music, 1);
			}
			if (state[SDL_SCANCODE_LEFT]){
				leapfrog.checkleft = true;
				music = Mix_LoadMUS("JUMP.mp3");
				Mix_PlayMusic(music, 1);
			}
		}
		//These are the conditions to reset the game.
		if (state == 4){
			for(auto&& i : leapfrog.scores) {
					delete i;
				}
			leapfrog.scores.clear();
		}
		if (state == 3){
			for(auto&& i : leapfrog.scores) {
					delete i;
				}
			leapfrog.scores.clear();
			leapfrog.objects.clear();
		}
		SDL_RenderClear(Drawing::gRenderer); //removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL);//Draws background to renderer

		if (state == 1){
			leapfrog.createObject();
			leapfrog.drawObjects();
			leapfrog.CheckCollision();
			leapfrog.updatescore();
		}
		//**********************
    	SDL_RenderPresent(Drawing::gRenderer); //displays the updated renderer

	    SDL_Delay(100);	//causes sdl engine to delay for specified miliseconds
	}
			
}