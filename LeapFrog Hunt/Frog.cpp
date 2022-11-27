#include "Frog.hpp"

//This function is responsible for drawing the frog on the screen
void Frog::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

//This is the default constructor for the Frog class
Frog::Frog(){
    
    srcRect = {0,365,23,17};
    moverRect = {232, 475, 20, 20};
}

void Frog :: operator++(){
    moverRect.x += 40;
}

void Frog :: operator--(){
    moverRect.x -= 40;
}

void Frog :: operator+(){
    moverRect.y += 40;
}

Frog Frog :: operator-(){
    moverRect.y -= 40;
}

//This is the destructor for the Frog class
Frog::~Frog(){

}

