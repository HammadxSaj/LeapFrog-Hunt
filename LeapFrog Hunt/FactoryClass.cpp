#include "FactoryClass.hpp"

//This function dynamically creates all assets on the screen on the specified co ordinates through the overloaded constructors
//of the assets nad pushes them into Unit* type list which is then returned in the leap frog class.
list<Unit*> FactoryClass::CreateObjects(){
    if (objects.size()<=0){
                Tractor* t1 = new Tractor();
                Tractor* t2 = new Tractor(300, 430);
                Tractor* t3 = new Tractor(450, 430);
                Tractor* t4 = new Tractor(0, 430);

                objects.push_back(t1), objects.push_back(t2), objects.push_back(t3), objects.push_back(t4);
        }
        if (objects.size()<=4){
                YellowCar* y1 = new YellowCar();
                YellowCar* y2 = new YellowCar(300, 390);
                YellowCar* y3 = new YellowCar(450, 390);
                YellowCar* y4 = new YellowCar(0, 390);
                objects.push_back(y1), objects.push_back(y2), objects.push_back(y3), objects.push_back(y4);
        }
        if (objects.size()<=8){
                WhiteCar* w1 = new WhiteCar();
                WhiteCar* w2 = new WhiteCar(200, 320);
                WhiteCar* w3 = new WhiteCar(300, 320);
                WhiteCar* w4 = new WhiteCar(0, 320);
                WhiteCar* w5 = new WhiteCar(400, 320);
                objects.push_back(w1), objects.push_back(w2), objects.push_back(w3), objects.push_back(w4), objects.push_back(w5);
                cout<<"WhiteCar "<<objects.size()<<endl;
        }
        if (objects.size()<=13){
                Truck* tr1 = new Truck();
                Truck* tr2 = new Truck(200, 285);
                Truck* tr3 = new Truck(320, 285);
                Truck* tr4 = new Truck(460, 285);
                objects.push_back(tr1), objects.push_back(tr2), objects.push_back(tr3), objects.push_back(tr4);
                //cout<<"Truck "<<objects.size()<<endl;
        }
        if (objects.size()<=17){
                Turtles* tu1 = new Turtles();
                Turtles* tu2 = new Turtles(40, 190);
                Turtles* tu3 = new Turtles(5, 190);
                Turtles* tu4 = new Turtles(250, 190);
                Turtles* tu5 = new Turtles(220, 190);
                Turtles* tu6 = new Turtles(185, 190);
                Turtles* tu7 = new Turtles(450, 190);
                Turtles* tu8 = new Turtles(420, 190);
                Turtles* tu9 = new Turtles(385, 190);
                objects.push_back(tu1), objects.push_back(tu2), objects.push_back(tu3), objects.push_back(tu4), objects.push_back(tu5);
                objects.push_back(tu6), objects.push_back(tu7), objects.push_back(tu8), objects.push_back(tu9);
        }
        if (objects.size()<=26){
                Wood* wo1 = new Wood();
                Wood* wo2 = new Wood(200, 150);
                Wood* wo3 = new Wood(350, 150);
                Wood* wo4 = new Wood(470, 150);
                objects.push_back(wo1), objects.push_back(wo2), objects.push_back(wo3), objects.push_back(wo4);
        }
        if (objects.size()<=30){
                Crocodiles* c1 = new Crocodiles(0, 70);
                Crocodiles* c2 = new Crocodiles(150, 70);
                Crocodiles* c3 = new Crocodiles(300, 70);
                Crocodiles* c4 = new Crocodiles(450, 70);
                objects.push_back(c1), objects.push_back(c2), objects.push_back(c3), objects.push_back(c4);
        }
        if (objects.size()<=34){
                Snake* s1 = new Snake();
                Snake* s2 = new Snake(40, 115);
                Snake* s3 = new Snake(5, 115);
                Snake* s4 = new Snake(250, 115);
                Snake* s5 = new Snake(220, 115);
                Snake* s6 = new Snake(185, 115);
                Snake* s7 = new Snake(450, 115);
                Snake* s8 = new Snake(420, 115);
                Snake* s9 = new Snake(385, 115);
                objects.push_back(s1), objects.push_back(s2), objects.push_back(s3), objects.push_back(s4), objects.push_back(s5);
                objects.push_back(s6), objects.push_back(s7), objects.push_back(s8), objects.push_back(s9);
        }
        if (objects.size()<=43){
            Health* h1 = new Health();
            Health* h2 = new Health(250,230);
            Health* h3 = new Health(450,230);
            objects.push_back(h1), objects.push_back(h2), objects.push_back(h3);
        }
    return objects;
}

//This is the destructor which deletes all the assets on the screen.
FactoryClass :: ~FactoryClass(){
    for(auto&& i : objects) {
	delete i;
        }
    objects.clear();
}