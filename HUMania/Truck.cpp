#include "Truck.hpp"
#include "drawing.hpp"

void Truck::move(){
    // you have to do flying animations here
    moverRect.x -= 7;
    if (moverRect.x < -50){
        moverRect.x = 550;
    }
}

Truck::Truck(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {110,306, 30 ,30};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {7, 285, 40, 40};
}

Truck::Truck(int x, int y){       //This function is an example of function overloading
    srcRect = {110,306,30,30};       // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {x , y, 40, 40};        //The moverrect value constantly changes as the pigeon moves to the right hence the value here keeps changing.
}
