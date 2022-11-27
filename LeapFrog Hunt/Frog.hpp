#include<SDL.h>
#include "drawing.hpp"

//This class is responsible for drawing the frog on the screen..
//Leap frog has been made a friend class of this class so that it can access the private members of this class that includes
//the SrcRect and moverect values to animate the frog by changing it's SrcRect values and also accessing it's moverRect values to check collisions and move frog.
class Frog{

    SDL_Rect srcRect, moverRect;

public:
    void draw();
    Frog(); 
    friend class LeapFrog;
    ~Frog();
    void operator++();
    void operator--();
    void operator+();
    Frog operator-();
};
