#include "drawing.hpp"
#include "Unit.hpp"

class Crocodiles : public Unit{
    
public:
    void draw();
    void move();
    Crocodiles(); 
    Crocodiles(int x, int y);
    int animation = 0;
    friend class Game;
    friend class LeapFrog;
    // you may add other overloaded constructors here... 
};
