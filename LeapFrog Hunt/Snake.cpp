#include "Snake.hpp"
#include "drawing.hpp"


void Snake::move(){
    // you have to do flying animations here
    switch (animation){
        case 0:                         //This case will become true at first since animation = 0 has been assigned.
        srcRect = {184, 226, 38, 10};     //Generate the pigeon image having wings up
        animation = 1;                  //Changes value of animation 1 to make the second case true for animation
        break;
    case 1:                             //After case 0 this will become true
        srcRect = {185, 251,37,13};        //Generate the pigeon image having wings at center
        animation = 2;                          //Changes value of animation 2 to make the third case true for animation
        break;  
    case 2:                                 //After case 1 this will become true
        srcRect = {184, 276, 38, 16};          //Generate the pigeon image having wings down
        animation = 3;                      //Changes value of animation 0 to make the first case true for animation to reset the animation of pigeon
    case 3:
        srcRect = {185, 304, 37, 13};
        animation = 0;
    default:
        animation = 0;              //default case will have the image of pigeon having wings up
        break;
    }
    moverRect.x -= 6;
    if (moverRect.x < -50){
        moverRect.x = 550;
    }
}

Snake::Snake(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {184, 226, 38, 10};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {7, 115, 40, 20};
}

Snake::Snake(int x, int y){       //This function is an example of function overloading
    srcRect = {184, 226, 38, 10};       // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {x , y, 40, 20};        //The moverrect value constantly changes as the pigeon moves to the right hence the value here keeps changing.
}

Snake::~Snake(){

}
