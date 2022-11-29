#include "drawing.hpp"
#include "Unit.hpp"
#pragma once 

//White Car class inherting from Unit class and drawing the white car on the screen and moving it through its move function
//The move function is overriden from the Unit class
class WhiteCar : public Unit{

public:
    void move();
    WhiteCar(); 
    WhiteCar(int x, int y);
    ~WhiteCar();
};