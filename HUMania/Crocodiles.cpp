#include "Crocodiles.hpp"
#include "drawing.hpp"

void Crocodiles::move(){
    // you have to do flying animations here
    switch (animation){
        case 0:                         //This case will become true at first since animation = 0 has been assigned.
        srcRect = {156,368,89,21};     //Generate the pigeon image having wings up
        animation = 1;                  //Changes value of animation 1 to make the second case true for animation
        break;
    case 1:                             //After case 0 this will become true
        srcRect = {156, 332, 89, 30};        //Generate the pigeon image having wings at center
        animation = 0;                          //Changes value of animation 2 to make the third case true for animation
    default:
        animation = 0;              //default case will have the image of pigeon having wings up
        break;
    }
    moverRect.x += 7;
    if (moverRect.x > 550){
        moverRect.x = -50;
    }
}

Crocodiles::Crocodiles(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {156,368,89,21};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {7, 70, 60, 30};
}

Crocodiles::Crocodiles(int x, int y){       //This function is an example of function overloading
    srcRect = {156,368,89,21};     // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {x , y, 80, 30};        //The moverrect value constantly changes as the pigeon moves to the right hence the value here keeps changing.
}