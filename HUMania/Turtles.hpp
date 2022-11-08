#include "drawing.hpp"

class Turtles{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void move();
    Turtles(); 
    Turtles(int x, int y);
    int animation = 0;
    friend class Game;
    friend class LeapFrog;
    // you may add other overloaded constructors here... 
};
