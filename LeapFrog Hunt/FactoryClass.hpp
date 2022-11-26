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


class FactoryClass : public Unit{
    list<Unit*> objects;
    public:
        list<Unit*> CreateObjects();
        //friend class LeapFrog;
};