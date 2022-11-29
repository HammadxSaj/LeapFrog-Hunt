#include "Crocodiles.hpp"
#include "drawing.hpp"

//This function is used to move the Crocodiles on the screen and it is overriden from the Unit class
//additionally it inherits animation variable from the Unit class to animate the Crocodiles based on the srcRect values.
void Crocodiles::move(){
    switch (animation){
        case 0:                         
        srcRect = {156,368,89,21};     
        animation = 1;                  
        break;
    case 1:                             
        srcRect = {156, 332, 89, 30};       
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

//This is the default constructor for the Crocodiles class
Crocodiles::Crocodiles(){
    srcRect = {156,368,89,21};
    moverRect = {0, 70, 60, 30};
}

//This is the overloaded constructor for the Crocodiles class which takes in the x and y coordinates of the Crocodiles
Crocodiles::Crocodiles(int x, int y){       
    srcRect = {156,368,89,21};     
    moverRect = {x , y, 80, 30};       
}

//This is the destructor for the Crocodiles class
Crocodiles::~Crocodiles(){

}