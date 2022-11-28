#include "Turtles.hpp"
#include "drawing.hpp"

//This function is used to move the Turtles on the screen and it is overriden from the Unit class
//additionally it inherits animation variable from the Unit class to animate the turtles based on the srcRect values.
void Turtles::move(){
    
    switch (animation){
        case 0:                         
        srcRect = {1,395,31,22};     
        animation = 1;                  
        break;
    case 1:                             
        srcRect = {35, 394, 31, 22};        
        animation = 2;                          
        break;  
    case 2:                                
        srcRect = {71,396,29,18};          
        animation = 3;                     
    case 3:
        srcRect = {106,394,29,21};
        animation = 4;
    case 4:
        srcRect = {145,398,17,13};
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

//This is the default constructor for the Turtles class
Turtles::Turtles(){
   
    srcRect = {1,395,31,22};

    moverRect = {7, 195, 30, 30};
}

//This is the overloaded constructor for the Turtles class which takes in the x and y coordinates of the Turtles
//and dynamically creates the Turtles on the screen at the specified co-ordinates from the factory class
Turtles::Turtles(int x, int y){      
    srcRect = {1,395,31,22};        
    moverRect = {x , y, 30, 30};       
}

//This is the destructor for the Turtles class
Turtles::~Turtles(){

}