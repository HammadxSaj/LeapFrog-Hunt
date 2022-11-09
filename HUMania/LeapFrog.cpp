#include <iostream>
#include "LeapFrog.hpp"
using namespace std;

void LeapFrog::drawObjects()
{
    for(Unit* x: objects){
        x->draw();
        x->move();
        //cout<<x->moverRect.x<<endl; excess x ki value like this
    }
    frog.draw();
    if (checkup == true){
            frog.srcRect = {0,365,23,17};
            if (frog.moverRect.y<=475){
                frog.moverRect.y -= 40;
            }
            checkup = false;
    }
    else{
        checkup = false;
    }
    if (checkdown == true){
        if (frog.moverRect.y<=474){
            frog.moverRect.y += 40;
            cout<<frog.moverRect.y<<endl;
        }
            checkdown = false;
            frog.srcRect = {70,365,22,17};
    }
    else{
        checkdown = false;
    }
    if (checkleft == true){
        if (frog.moverRect.x>=33){
            frog.moverRect.x -= 40;
        }
            checkleft = false;
            frog.srcRect = {71,335,18,23};
    }
    else{
        checkleft = false;
    }
    if (checkright == true && frog.moverRect.x>0 && frog.moverRect.x<500){
        if (frog.moverRect.x<=471){
            frog.moverRect.x += 40;
        }
            checkright= false;
            frog.srcRect = {1,335,17,23};
    }
    else{
        checkright= false;
    }
}

void LeapFrog::createObject(){
        if (objects.size()<=0){
                Tractor* t1 = new Tractor(150, 430);
                Tractor* t2 = new Tractor(300, 430);
                Tractor* t3 = new Tractor(450, 430);
                Tractor* t4 = new Tractor(0, 430);

                objects.push_back(t1), objects.push_back(t2), objects.push_back(t3), objects.push_back(t4);
                //cout<<"Tractor "<<objects.size()<<endl;
        }
        if (objects.size()<=4){
                Wood* wo1 = new Wood(50, 150);
                Wood* wo2 = new Wood(200, 150);
                Wood* wo3 = new Wood(350, 150);
                Wood* wo4 = new Wood(470, 150);
                objects.push_back(wo1), objects.push_back(wo2), objects.push_back(wo3), objects.push_back(wo4);
                //cout<<"Wood "<<objects.size()<<endl;
        }

        if (objects.size()<=8){
                YellowCar* y1 = new YellowCar(150, 390);
                YellowCar* y2 = new YellowCar(300, 390);
                YellowCar* y3 = new YellowCar(450, 390);
                YellowCar* y4 = new YellowCar(0, 390);
                objects.push_back(y1), objects.push_back(y2), objects.push_back(y3), objects.push_back(y4);
                //cout<<"YellowCar "<<objects.size()<<endl;
        }
        if (objects.size()<=12){
                WhiteCar* w1 = new WhiteCar(100, 320);
                WhiteCar* w2 = new WhiteCar(200, 320);
                WhiteCar* w3 = new WhiteCar(300, 320);
                WhiteCar* w4 = new WhiteCar(0, 320);
                WhiteCar* w5 = new WhiteCar(400, 320);
                objects.push_back(w1), objects.push_back(w2), objects.push_back(w3), objects.push_back(w4), objects.push_back(w5);
                cout<<"WhiteCar "<<objects.size()<<endl;
                //cout<<whitecars[1]->moverRect.x;       yeh tareeqa hai moverrect se value uthane ka
        }
        if (objects.size()<=17){
                Truck* tr1 = new Truck(70, 285);
                Truck* tr2 = new Truck(200, 285);
                Truck* tr3 = new Truck(320, 285);
                Truck* tr4 = new Truck(460, 285);
                objects.push_back(tr1), objects.push_back(tr2), objects.push_back(tr3), objects.push_back(tr4);
                //cout<<"Truck "<<objects.size()<<endl;
        }
        if (objects.size()<=21){
                Turtles* tu1 = new Turtles(70, 190);
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
                //cout<<"Turtles "<<objects.size()<<endl;
        }
        if (objects.size()<=30){
                Crocodiles* c1 = new Crocodiles(0, 70);
                Crocodiles* c2 = new Crocodiles(150, 70);
                Crocodiles* c3 = new Crocodiles(300, 70);
                Crocodiles* c4 = new Crocodiles(450, 70);
                objects.push_back(c1), objects.push_back(c2), objects.push_back(c3), objects.push_back(c4);
                //cout<<"Crocodiles "<<objects.size()<<endl;
        }
        if (objects.size()<=34){
                Snake* s1 = new Snake(70, 115);
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
}
void LeapFrog::createObject(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}
