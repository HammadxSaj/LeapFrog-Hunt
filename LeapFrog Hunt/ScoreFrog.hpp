#include<SDL.h>
#include "drawing.hpp"

//The scorefrog class draws a frog on the screen as soon as the frog fills one of the 5 holes
//Since this is created randomly and is responsible for the game reset logic, it is not being inherited by the Unit class.
class ScoreFrog{

    SDL_Rect srcRect, moverRect;

public:
    ScoreFrog(); 
    ScoreFrog(int x, int y);
    void draw();
    ~ScoreFrog();
};
