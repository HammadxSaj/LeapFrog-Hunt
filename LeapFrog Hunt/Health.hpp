#include<SDL.h>
#include "drawing.hpp"
#include "Unit.hpp"
#pragma once;

class Health : public Unit{

public:
    Health(); 
    // you may add other overloaded constructors here... 
    Health(int x, int y);
    ~Health();
};
