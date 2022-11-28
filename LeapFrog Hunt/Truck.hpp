#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

//Truck class inherting from Unit class and drawing the Truck on the screen and moving it through its move function
//The move function is overriden from the Unit class
class Truck : public Unit{

public:
    void move();
    Truck(); 
    Truck(int x, int y);
    ~Truck();
};

