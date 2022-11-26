#include<SDL.h>
#include "Frog.hpp"
#include "ScoreFrog.hpp"
#include "Health.hpp"
#include "FactoryClass.hpp"
#include<vector>
#include<list>
#include<SDL_mixer.h>
using namespace std;

class LeapFrog{

    //Right now we're creating one pigeon, 
    Frog frog;
    //ScoreFrog score, score1, score2;
    FactoryClass factory;
    vector<ScoreFrog*> scores;
    list<Unit*> objects;
    // In the solution you have to create vectors of pigeons, eggs, and nests         
    int animation = 0;
    Mix_Music* music = NULL;
    int pause = 0;

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
    friend class Game;
    ~LeapFrog();
};  