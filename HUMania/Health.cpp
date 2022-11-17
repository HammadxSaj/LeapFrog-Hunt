#include "Health.hpp"

Health :: Health(){
    srcRect = {36, 364, 22, 25};
    moverRect = {7, 330, 30, 30};
}

Health :: Health(int x, int y){
    srcRect = {36, 364, 22, 25};
    moverRect = {x, y, 30, 30};
}