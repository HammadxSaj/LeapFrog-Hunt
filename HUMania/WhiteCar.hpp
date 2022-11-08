#include "drawing.hpp"

class WhiteCar{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void move();
    WhiteCar(); 
    WhiteCar(int x, int y);
    int animation = 0;
    friend class Game;
    friend class LeapFrog;
    // you may add other overloaded constructors here... 
};