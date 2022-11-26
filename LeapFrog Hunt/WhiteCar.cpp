#include "WhiteCar.hpp"
#include "drawing.hpp"

void WhiteCar::move(){
    // you have to do flying animations here
    moverRect.x += 6;
    if (moverRect.x > 550){
        moverRect.x = -50;
    }
}

WhiteCar::WhiteCar(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {46,265,28,24};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {12, 320, 30, 30};
}

WhiteCar::WhiteCar(int x, int y){       //This function is an example of function overloading
    srcRect = {46,265,28,24};        // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {x , y, 30, 30};        //The moverrect value constantly changes as the pigeon moves to the right hence the value here keeps changing.
}

WhiteCar::~WhiteCar(){

}
