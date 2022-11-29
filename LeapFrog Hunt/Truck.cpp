#include "Truck.hpp"
#include "drawing.hpp"

//This function is used to move the Truck on the screen and it is overriden from the Unit class
//The move function is overriden from the Unit class
void Truck::move(){
    moverRect.x -= 7;
    if (moverRect.x < -50){
        moverRect.x = 550;
    }
}

//This is the default constructor for the Truck class
Truck::Truck(){
    srcRect = {110,306, 30 ,30};
    moverRect = {70, 285, 40, 40};
}

//This is the overloaded constructor for the Truck class which takes in the x and y coordinates of the Truck
//and dynamically creates the Truck on the screen at the specified co-ordinates from the factory class
Truck::Truck(int x, int y){       
    srcRect = {110,306,30,30};       
    moverRect = {x , y, 40, 40};      
}

//This is the destructor for the Truck class
Truck::~Truck(){

}
