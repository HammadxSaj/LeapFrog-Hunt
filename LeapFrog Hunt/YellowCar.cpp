#include "YellowCar.hpp"
#include "drawing.hpp"
#include<iostream>
using namespace std;

//This function is used to move the yellow car on the screen and it is overriden from the Unit class
void YellowCar::move(){

    moverRect.x -= 7;
    if (moverRect.x < -50){
        moverRect.x = 550;
    }
}

//This is the default constructor for the YellowCar class
YellowCar::YellowCar(){
    srcRect = {82,264,24,26};
    moverRect = {150, 390, 30, 30};
}

//This is the overloaded constructor for the YellowCar class which takes in the x and y coordinates of the yellow car
//and dynamically creates the yellow car on the screen at the specified co-ordinates from the factory class
YellowCar::YellowCar(int x, int y){       
    srcRect = {82,264,24,26};        
    moverRect = {x , y, 30, 30};       
}

//This is the destructor for the YellowCar class
YellowCar :: ~YellowCar(){

}
