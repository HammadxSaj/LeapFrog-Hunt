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
#include<vector>
#include<list>
using namespace std;

class LeapFrog{

    //Right now we're creating one pigeon, 
    Frog frog;
    Tractor Tractors;
    YellowCar YellowCars;
    WhiteCar WhiteCars;
    Truck Trucks;
    Turtles Turtle;
    Wood Woods;
    Crocodiles Crocodile;
    Snake Snakes;
    // In the solution you have to create vectors of pigeons, eggs, and nests    
    vector<Frog*> Frogs;
    vector<Tractor*> tractors;
    vector<YellowCar*> yellowcars;
    vector<WhiteCar*> whitecars;
    vector<Truck*> trucks;
    vector<Turtles*> turtle;
    vector<Wood*> woods;
    vector<Crocodiles*> crocodiles;
    vector<Snake*> snakes;

    public:
    bool checkup=false;
    bool checkdown=false;
    bool checkright=false;
    bool checkleft=false;
    void drawObjects(); 
    void createObject(int, int);
    void createObject();
};  