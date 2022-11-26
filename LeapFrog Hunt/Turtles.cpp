#include "Turtles.hpp"
#include "drawing.hpp"

void Turtles::move(){
    // you have to do flying animations here
    switch (animation){
        case 0:                         //This case will become true at first since animation = 0 has been assigned.
        srcRect = {1,395,31,22};     //Generate the pigeon image having wings up
        animation = 1;                  //Changes value of animation 1 to make the second case true for animation
        break;
    case 1:                             //After case 0 this will become true
        srcRect = {35, 394, 31, 22};        //Generate the pigeon image having wings at center
        animation = 2;                          //Changes value of animation 2 to make the third case true for animation
        break;  
    case 2:                                 //After case 1 this will become true
        srcRect = {71,396,29,18};          //Generate the pigeon image having wings down
        animation = 3;                      //Changes value of animation 0 to make the first case true for animation to reset the animation of pigeon
    case 3:
        srcRect = {106,394,29,21};
        animation = 4;
    case 4:
        srcRect = {145,398,17,13};
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

Turtles::Turtles(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {1,395,31,22};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {7, 195, 30, 30};
}

Turtles::Turtles(int x, int y){       //This function is an example of function overloading
    srcRect = {1,395,31,22};        // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {x , y, 30, 30};        //The moverrect value constantly changes as the pigeon moves to the right hence the value here keeps changing.
}

Turtles::~Turtles(){

}