#include "YellowCar.hpp"
#include "drawing.hpp"

void YellowCar::move(){
    // you have to do flying animations here
    moverRect.x -= 6;
    if (moverRect.x < -50){
        moverRect.x = 550;
    }
}

YellowCar::YellowCar(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {82,264,24,26};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {7, 390, 30, 30};
}

YellowCar::YellowCar(int x, int y){       //This function is an example of function overloading
    srcRect = {82,264,24,26};        // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {x , y, 30, 30};        //The moverrect value constantly changes as the pigeon moves to the right hence the value here keeps changing.
}
