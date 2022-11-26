#include<SDL.h>
#include "drawing.hpp"

class ScoreFrog{

    SDL_Rect srcRect, moverRect;

public:
    ScoreFrog(); 
    ScoreFrog(int x, int y);
    void draw();
    friend class Game;
    friend class LeapFrog;
    ~ScoreFrog();
    // you may add other overloaded constructors here... 
};
