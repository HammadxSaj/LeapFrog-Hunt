#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

class Turtles : public Unit{

public:
    void draw();
    void move();
    Turtles(); 
    Turtles(int x, int y);
    int animation = 0;
    friend class Game;
    friend class LeapFrog;
    ~Turtles();
    // you may add other overloaded constructors here... 
};
