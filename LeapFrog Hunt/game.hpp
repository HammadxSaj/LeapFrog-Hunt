#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <SDL_mixer.h>

class Game{
    //Screen dimension constants
    const int SCREEN_WIDTH = 500;
    const int SCREEN_HEIGHT = 500;

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //Current displayed texture
    SDL_Texture* gTexture = NULL;
    
    Mix_Music* music = NULL;

    int state = 0;
    int i = 0;
public:
    
    bool init();
    bool loadMedia();
    bool loadGame();
    bool loadInstructions();
    void close();
    bool loadwonscreen();
    bool loadendscreen();
    bool SplashScreen();
    void remove_all();
    SDL_Texture* loadTexture( std::string path );
    void run();
    friend class LeapFrog;
};