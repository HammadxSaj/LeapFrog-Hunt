#include "Wood.hpp"
#include "drawing.hpp"

//This function is used to move the Wood on the screen and it is overriden from the Unit class
void Wood::move(){
    moverRect.x += 7;
    if (moverRect.x > 550){
        moverRect.x = -50;
    }
}

//This is the default constructor for the Wood class
Wood::Wood(){
    srcRect = {7,197,117,22};
}

//This is the overloaded constructor for the Wood class which takes in the x and y coordinates of the Wood
//and dynamically creates the Wood on the screen at the specified co-ordinates from the factory class
Wood::Wood(int x, int y){       
    srcRect = {7,197,117,22};        
    moverRect = {x , y, 80, 30};       
}

//This is the destructor for the Wood class
Wood :: ~Wood(){

}