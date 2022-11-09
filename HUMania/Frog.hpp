#include<SDL.h>
#include "drawing.hpp"

class Frog{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void move();
    Frog(); 
    bool initialstate = false;
    friend class Game;
    friend class LeapFrog;
    // you may add other overloaded constructors here... 
};
