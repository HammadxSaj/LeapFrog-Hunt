#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

//Turtle class inherting from Unit class and drawing the Turtle on the screen and moving it through its move function 
//The move function is overriden from the Unit class
class Turtles : public Unit{

public:
    void move();
    Turtles(); 
    Turtles(int x, int y);
    ~Turtles();
};
