#include "ScoreFrog.hpp"
#include "drawing.hpp"

void ScoreFrog::draw(){
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

ScoreFrog::ScoreFrog(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {108,235,16,16};
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
}

ScoreFrog::ScoreFrog(int x, int y){       //This function is an example of function overloading
    srcRect = {108,235,16,16};        // src coorinates from assets.png file, they have been found using spritecow.com
    moverRect = {x , y, 30, 30};        //The moverrect value constantly changes as the pigeon moves to the right hence the value here keeps changing.
}

ScoreFrog::~ScoreFrog(){

}