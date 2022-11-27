#include "WhiteCar.hpp"
#include "drawing.hpp"

//This function is used to move the WhiteCar on the screen and it is overriden from the Unit class
void WhiteCar::move(){
    moverRect.x += 7;
    if (moverRect.x > 550){
        moverRect.x = -50;
    }
}

//This is the default constructor for the WhiteCar class
WhiteCar::WhiteCar(){
    srcRect = {46,265,28,24};
    moverRect = {12, 320, 30, 30};
}

//This is the overloaded constructor for the WhiteCar class which takes in the x and y coordinates of the WhiteCar
//and dynamically creates the WhiteCar on the screen at the specified co-ordinates from the factory class
WhiteCar::WhiteCar(int x, int y){       
    srcRect = {46,265,28,24};        
    moverRect = {x , y, 30, 30};       
}

//This is the destructor for the WhiteCar class
WhiteCar::~WhiteCar(){

}
