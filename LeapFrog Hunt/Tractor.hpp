#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

//Tractor class inherting from Unit class and drawing the Tractor on the screen and moving it through its move function
//The move function is overriden from the Unit class
class Tractor : public Unit{

public:
    void move();
    Tractor(); 
    Tractor(int x, int y); 
    ~Tractor();
};
