#include<SDL.h>
#include "Frog.hpp"
#include "ScoreFrog.hpp"
#include "Health.hpp"
#include "FactoryClass.hpp"
#include<vector>
#include<list>
#include<SDL_mixer.h>
using namespace std;

//The LeapFrog class is the main class that contains all the game logic.
//This class is responsible for the collision detection, score calculation, drawing of assets etc.
//It creates the required objects like Frog that moves on the screen ased on the key that has been selected by the user.
//It also creates the required objects like ScoreFrog that is created when the frog fills one of the 5 holes.
//It is also creates the most vital Unit type list that contains the pointers to SrcRect and MoverRect of all the assets like cars, logs, snakes, etc.
class LeapFrog{ 
    Frog frog;
    FactoryClass factory;
    vector<ScoreFrog*> scores;
    list<Unit*> objects;       
    Mix_Music* music = NULL;
    int pause = 0;
    int animation = 0;

    public:
    bool checkup=false;
    bool checkdown=false;
    bool checkright=false;
    bool checkleft=false;
    bool objectcheck = false;
    void drawObjects(); 
    void createObject(int, int);
    void createObject();
    void CheckCollision();
    void updatescore();
    bool checklost();
    friend class Game; //Game class has been made the friend class of LeapFrog class so that it can access the members of LeapFrog class such
                       //as the Unit type list and ScoreFrog pointer vector which is responsible for the game reset logic.
    ~LeapFrog();
};  