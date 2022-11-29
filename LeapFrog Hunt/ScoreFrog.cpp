#include "ScoreFrog.hpp"
#include "drawing.hpp"

//This function draws the ScoreFrog on the screen
void ScoreFrog::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

//This is the default constructor for the ScoreFrog class
ScoreFrog::ScoreFrog(){
    srcRect = {108,235,16,16};
}

//This is the overloaded constructor for the ScoreFrog class which takes in the x and y coordinates of the ScoreFrog
//and dynamically creates the ScoreFrog on the screen at the specified co-ordinates from the leapfrog class.
ScoreFrog::ScoreFrog(int x, int y){      
    srcRect = {108,235,16,16};       
    moverRect = {x , y, 30, 30};  
}

//This is the destructor for the ScoreFrog class
ScoreFrog::~ScoreFrog(){

}