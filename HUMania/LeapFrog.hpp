#include<SDL.h>
#include "Frog.hpp"
#include "YellowCar.hpp"
#include "Tractor.hpp"
#include "WhiteCar.hpp"
#include "Truck.hpp"
#include "Turtles.hpp"
#include "Wood.hpp"
#include "Crocodiles.hpp"
#include "Snake.hpp"
#include "Unit.hpp"
#include<vector>
#include<list>
using namespace std;

class LeapFrog{

    //Right now we're creating one pigeon, 
    Frog frog;
    list<Unit*> objects;
    // In the solution you have to create vectors of pigeons, eggs, and nests    

    public:
    bool checkup=false;
    bool checkdown=false;
    bool checkright=false;
    bool checkleft=false;
    void drawObjects(); 
    void createObject(int, int);
    void createObject();
};  