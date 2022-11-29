#include <SDL.h>
#include "drawing.hpp"
#include <iostream>
using namespace std;
#pragma once

//Parent Class for all the assets in the game
class Unit{             //defining a class named unit as required that is to be inherited by all the assets like cars, logs, snakes, etc.
    protected:
        SDL_Rect srcRect, moverRect;            //These values will be inherited by all the assets like cars, logs, snakes, etc. This would contain initial srcRect, moverRect values.
        int animation = 0;                  //An animation variable that will be inherited by all the assets like cars, logs, snakes, etc.
    public:
        void draw();                           //A predefined draw function that will be inherited by all the assets like cars, logs, snakes, etc to draw objects.
        virtual void move();     //A virtual move function since each object have different srcRect values for animation, this function cannot be predefined but would be defined individually in each class.
        friend class LeapFrog;  //making LeapFrog as a friend class since we need the access of the moveRect values in the Unit type list to check collision in LeapFrog class.
        virtual ~Unit();                    //A virtual destructor for the Unit class.
};