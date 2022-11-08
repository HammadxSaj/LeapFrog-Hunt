#include <iostream>
#include "LeapFrog.hpp"
using namespace std;

void LeapFrog::drawObjects()
{
    // call draw functions of all the objects here
    frog.draw();
    if (checkup == true){
            frog.srcRect = {0,365,23,17};
            if (frog.moverRect.y<=475){
                frog.moverRect.y -= 30;
            }
            checkup = false;
    }
    else{
        checkup = false;
    }
    if (checkdown == true){
        if (frog.moverRect.y<=474){
            frog.moverRect.y += 30;
        }
            checkdown = false;
            frog.srcRect = {70,365,22,17};
    }
    else{
        checkdown = false;
    }
    if (checkleft == true){
        if (frog.moverRect.x>=24){
            frog.moverRect.x -= 30;
        }
            checkleft = false;
            frog.srcRect = {71,335,18,23};
    }
    else{
        checkleft = false;
    }
    if (checkright == true && frog.moverRect.x>0 && frog.moverRect.x<500){
        if (frog.moverRect.x<=472){
            frog.moverRect.x += 30;
        }
            checkright= false;
            frog.srcRect = {1,335,17,23};
    }
    else{
        checkright= false;
    }
    for (int i = 0; i < tractors.size(); i++){     //loops along the size of the butterfly vector
        tractors[i]->draw();                       //calls the draw function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
        tractors[i]->move();                //calls the fly function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
    }
    for (int i = 0; i < yellowcars.size(); i++){     //loops along the size of the butterfly vector
        yellowcars[i]->draw();                       //calls the draw function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
        yellowcars[i]->move();                //calls the fly function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
    }
    for (int i = 0; i < whitecars.size(); i++){     //loops along the size of the butterfly vector
        whitecars[i]->draw();                       //calls the draw function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
        whitecars[i]->move();                //calls the fly function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
    }
    for (int i = 0; i < trucks.size(); i++){     //loops along the size of the butterfly vector
        trucks[i]->draw();                       //calls the draw function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
        trucks[i]->move();                //calls the fly function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
    }
    for (int i = 0; i < turtle.size(); i++){     //loops along the size of the butterfly vector
        turtle[i]->draw();                       //calls the draw function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
        turtle[i]->move();                //calls the fly function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
    }
    for (int i = 0; i < woods.size(); i++){     //loops along the size of the butterfly vector
        woods[i]->draw();                       //calls the draw function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
        woods[i]->move();                //calls the fly function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
    }
    for (int i = 0; i < crocodiles.size(); i++){     //loops along the size of the butterfly vector
        crocodiles[i]->draw();                       //calls the draw function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
        crocodiles[i]->move();                //calls the fly function in butterfly.cpp for the butterfly present at ith (or the last index) of the vector
    }
}

void LeapFrog::createObject(){
        if (tractors.size()<=3){
                Tractor* t1 = new Tractor(150, 430);
                Tractor* t2 = new Tractor(300, 430);
                Tractor* t3 = new Tractor(450, 430);
                Tractor* t4 = new Tractor(0, 430);
                tractors.push_back(t1), tractors.push_back(t2), tractors.push_back(t3), tractors.push_back(t4);
        }
        if (yellowcars.size()<=3){
                YellowCar* y1 = new YellowCar(150, 390);
                YellowCar* y2 = new YellowCar(300, 390);
                YellowCar* y3 = new YellowCar(450, 390);
                YellowCar* y4 = new YellowCar(0, 390);
                yellowcars.push_back(y1), yellowcars.push_back(y2), yellowcars.push_back(y3), yellowcars.push_back(y4);
        }
        if (whitecars.size()<=4){
                WhiteCar* w1 = new WhiteCar(100, 320);
                WhiteCar* w2 = new WhiteCar(200, 320);
                WhiteCar* w3 = new WhiteCar(300, 320);
                WhiteCar* w4 = new WhiteCar(0, 320);
                WhiteCar* w5 = new WhiteCar(400, 320);
                whitecars.push_back(w1), whitecars.push_back(w2), whitecars.push_back(w3), whitecars.push_back(w4), whitecars.push_back(w5);
        }
        if (trucks.size()<=3){
                Truck* tr1 = new Truck(70, 285);
                Truck* tr2 = new Truck(200, 285);
                Truck* tr3 = new Truck(320, 285);
                Truck* tr4 = new Truck(460, 285);
                trucks.push_back(tr1), trucks.push_back(tr2), trucks.push_back(tr3), trucks.push_back(tr4);
        }
        if (turtle.size()<=3){
                Turtles* tu1 = new Turtles(70, 190);
                Turtles* tu2 = new Turtles(40, 190);
                Turtles* tu3 = new Turtles(5, 190);
                Turtles* tu4 = new Turtles(250, 190);
                Turtles* tu5 = new Turtles(220, 190);
                Turtles* tu6 = new Turtles(185, 190);
                Turtles* tu7 = new Turtles(450, 190);
                Turtles* tu8 = new Turtles(420, 190);
                Turtles* tu9 = new Turtles(385, 190);
                turtle.push_back(tu1), turtle.push_back(tu2), turtle.push_back(tu3), turtle.push_back(tu4);
                turtle.push_back(tu5), turtle.push_back(tu6), turtle.push_back(tu7), turtle.push_back(tu8), turtle.push_back(tu9);
        }
        if (woods.size()<=3){
                Wood* wo1 = new Wood(100, 150);
                Wood* wo2 = new Wood(250, 150);
                Wood* wo3 = new Wood(400, 150);
                Wood* wo5 = new Wood(0, 150);
                woods.push_back(wo1), woods.push_back(wo2), woods.push_back(wo3), woods.push_back(wo5);
        }
        if (crocodiles.size()<=3){
                Crocodiles* c1 = new Crocodiles(120, 70);
                Crocodiles* c2 = new Crocodiles(240, 70);
                Crocodiles* c3 = new Crocodiles(360, 70);
                Crocodiles* c4 = new Crocodiles(480, 70);
                crocodiles.push_back(c1), crocodiles.push_back(c2), crocodiles.push_back(c3), crocodiles.push_back(c4);
        }
}
void LeapFrog::createObject(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}
