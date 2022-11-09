#include "drawing.hpp"
#include "Unit.hpp"
#pragma once

class YellowCar : public Unit{

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
