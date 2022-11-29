#include "drawing.hpp"
#include "Unit.hpp"
#include<iostream>
using namespace std;
#pragma once

//Yellow Car class inherting from Unit class and drawing the yellow car on the screen and moving it through its move function
//The move function is overriden from the Unit class
class YellowCar : public Unit{

public:
    void move();
    YellowCar(); 
    YellowCar(int x, int y);
    ~YellowCar();
};
