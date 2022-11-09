#include "drawing.hpp"
#include "Unit.hpp"

class Snake : public Unit{

public:
    void draw();
    void move();
    Snake(); 
    Snake(int x, int y);
    int animation = 0;
    friend class Game;
    friend class LeapFrog;
    // you may add other overloaded constructors here... 
};
