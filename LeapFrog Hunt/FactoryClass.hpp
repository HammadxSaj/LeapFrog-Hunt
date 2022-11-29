#include<SDL.h>
#include "YellowCar.hpp"
#include "Tractor.hpp"
#include "WhiteCar.hpp"
#include "Truck.hpp"
#include "Turtles.hpp"
#include "Wood.hpp"
#include "Crocodiles.hpp"
#include "Snake.hpp"
#include "Unit.hpp"
#include "Health.hpp"
#include<vector>
#include<list>
using namespace std;

//This class is the core of our Factory design method that creates all objects dynmically and pushes them into a Unit* type list 
//which is used in the leapfrog class. With respect to the Factory design method, the client will have no access to the creation of the objects
//and only the programmer's end will be accessible to change the creation of the objects which fulfills the Factory design method.
class FactoryClass : public Unit{
    list<Unit*> objects;
    public:
        list<Unit*> CreateObjects();
        ~FactoryClass(); //This is the destructor for the FactoryClass class.
};