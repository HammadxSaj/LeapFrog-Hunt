#include "drawing.hpp"

class YellowCar{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    void move();
    YellowCar(); 
    YellowCar(int x, int y);
    int animation = 0;
    friend class Game;
    friend class LeapFrog;
    // you may add other overloaded constructors here... 
};
