#include "Snake.hpp"
#include "drawing.hpp"

//This function is used to move the Snake on the screen and it is overriden from the Unit class
//additionally it inherits animation variable from the Unit class to animate the Snake based on the srcRect values.
void Snake::move(){
    switch (animation){
        case 0:                         
        srcRect = {184, 226, 38, 10};     
        animation = 1;                 
        break;
    case 1:                             
        srcRect = {185, 251,37,13};        
        animation = 2;                         
        break;  
    case 2:                                 
        srcRect = {184, 276, 38, 16};          
        animation = 3;                     
    case 3:
        srcRect = {185, 304, 37, 13};
        animation = 0;
    default:
        animation = 0;             
        break;
    }
    moverRect.x -= 7;
    if (moverRect.x < -50){
        moverRect.x = 550;
    }
}

//This is the default constructor for the Snake class
Snake::Snake(){
   
    srcRect = {184, 226, 38, 10};
    moverRect = {7, 115, 40, 20};
}

//This is the overloaded constructor for the Snake class which takes in the x and y coordinates of the Snake
//and dynamically creates the Snake on the screen at the specified co-ordinates from the factory class
Snake::Snake(int x, int y){      
    srcRect = {184, 226, 38, 10};      
    moverRect = {x , y, 40, 20};      
}

//This is the destructor for the Snake class
Snake::~Snake(){

}
