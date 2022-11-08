#include "Wood.hpp"
#include "drawing.hpp"

void Wood::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Wood::move(){
    // you have to do flying animations here
    moverRect.x += 7;
    if (moverRect.x > 550){
        moverRect.x = -50;
    }
}

Wood::Wood(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {7,197,117,22};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {3, 150, 60, 30};
}

Wood::Wood(int x, int y){       //This function is an example of function overloading
    srcRect = {7,197,117,22};        // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {x , y, 60, 30};        //The moverrect value constantly changes as the pigeon moves to the right hence the value here keeps changing.
}
