#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

//Wood class inherting from Unit class and drawing the Wood on the screen and moving it through its move function
//The move function is overriden from the Unit class
class Wood : public Unit{

public:
    void move();
    Wood(); 
    Wood(int x, int y);
    ~Wood();
};
