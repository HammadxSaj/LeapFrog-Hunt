#include "drawing.hpp"
#include "Unit.hpp"

//Snake class inherting from Unit class and drawing the Snake on the screen and moving it through its move function
//The move function is overriden from the Unit class
class Snake : public Unit{

public:
    void move();
    Snake(); 
    Snake(int x, int y);
    ~Snake();
};
