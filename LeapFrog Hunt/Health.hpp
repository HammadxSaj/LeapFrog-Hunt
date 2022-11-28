#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
#pragma once;

//Health class inherting from Unit class and drawing the Health on the screen. The Health is a static object and does not move.
class Health : public Unit{

public:
    Health(); 
    Health(int x, int y);
    ~Health();
};
