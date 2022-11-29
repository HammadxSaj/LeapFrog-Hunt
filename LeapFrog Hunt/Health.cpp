#include "Health.hpp"

//Constructor for the Health class
Health :: Health(){
    srcRect = {36, 364, 22, 25};
    moverRect = {20,230, 30, 30};
}

//This is the overloaded constructor for the Health class which takes in the x and y coordinates of the Health
//and dynamically creates the Health on the screen at the specified co-ordinates from the factory class
Health :: Health(int x, int y){
    srcRect = {36, 364, 22, 25};
    moverRect = {x, y, 30, 30};
}

//This is the destructor for the Health class
Health :: ~Health(){
    
}