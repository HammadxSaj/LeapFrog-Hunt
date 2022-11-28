#include "drawing.hpp"
#include "Unit.hpp"

//Crocodile class inherting from Unit class and drawing the Crocodile on the screen and moving it through its move function
//The move function is overriden from the Unit class
class Crocodiles : public Unit{
    
public:
    void move();
    Crocodiles(); 
    Crocodiles(int x, int y);
    ~Crocodiles(); 
};
