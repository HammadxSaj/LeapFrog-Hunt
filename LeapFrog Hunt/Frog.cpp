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

//This is the overloaded ++ operator to move the frog to the right.
void Frog :: operator++(){
    moverRect.x += 40;
}

//This is the overloaded -- operator to move the frog to the left.
void Frog :: operator--(){
    moverRect.x -= 40;
}

//This is the overloaded + operator to move the frog up.
void Frog :: operator+(){
    moverRect.y += 40;
}

//This is the overloaded - operator to move the frog down.
void Frog :: operator-(){
    moverRect.y -= 40;
}

//This is the destructor for the Frog class
Frog::~Frog(){

}

