#include "Frog.hpp"
// pigeon implementation will go here.

void Frog::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

void Frog::move(){
        srcRect = {0,365,23,17};
    // you have to do flying animations here
}

Frog::Frog(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {0,365,23,17};

    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {232, 475, 20, 20};
}

Frog::~Frog(){

}

