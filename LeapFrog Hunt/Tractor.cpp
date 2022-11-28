#include "Tractor.hpp"
#include "drawing.hpp"

//This function is used to move the Tractors on the screen and it is overriden from the Unit class
//additionally it inherits animation variable from the Unit class to animate the Tractors based on the srcRect values.
void Tractor::move(){
    switch (animation){
        case 0:                         
        srcRect = {70,305,25,21};       
        animation = 1;                  
        break;
    case 1:                             
        srcRect = {36, 305, 24, 21};        
        animation = 2;                          
        break;  
    case 2:                                 
        srcRect = {1,305,24,21};         
        animation = 0;                     
    default:
        animation = 0;             
        break;
    }
    moverRect.x += 7;
    if (moverRect.x > 550){
        moverRect.x = -50;
    }
}

//This is the default constructor for the Tractor class
Tractor::Tractor(){
    srcRect = {70,305,25,21};
    moverRect = {7, 330, 30, 30};
}

//This is the overloaded constructor for the Tractor class which takes in the x and y coordinates of the Tractor
//and dynamically creates the Tractor on the screen at the specified co-ordinates from the factory class
Tractor::Tractor(int x, int y){      
    srcRect = {70,305,25,21};          
    moverRect = {x , y, 30, 30};
}

//This is the destructor for the Tractor class
Tractor::~Tractor(){

}