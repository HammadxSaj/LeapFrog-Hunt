#include <iostream>
#include "LeapFrog.hpp"
#include<typeinfo.h>
using namespace std;

//This function loops through the Unit type list and calls the draw function from Unit class and virtual move function of each class of the asset.
//This function also draws the Frog on the screen, additionally it is also responsible for the movement of the frog based on the key pressed by the user.
//This function also contains the condtions necessary to make sure that the frog does not cross the boundary of the screen
//It is also loops through the pointer vector to Scorefrog draws the scorefrog on the screen when the frog fills one of the 5 holes.
void LeapFrog::drawObjects()
{
    for(Unit* x: objects){
        x->draw();
        x->move();
    }
    frog.draw();
    if (checkup == true){
            frog.srcRect = {0,365,23,17};
            if (frog.moverRect.y<=475 && frog.moverRect.y == 75 && frog.moverRect.x == 232){
                frog.moverRect.y -= 40;
            }
            else if (frog.moverRect.y<=475 && frog.moverRect.y == 75 && frog.moverRect.x == 112){
                frog.moverRect.y -= 40;
            }
            else if (frog.moverRect.y<=475 && frog.moverRect.y == 75 && frog.moverRect.x == 352){
                frog.moverRect.y -= 40;
            }
            else if (frog.moverRect.y<=475 && frog.moverRect.y == 75 && frog.moverRect.x == 472){
                frog.moverRect.y -= 40;
            }
            else if (frog.moverRect.y<=475 && frog.moverRect.y == 75 && frog.moverRect.x == 32){
                frog.moverRect.y -= 40;
            }
            else if (frog.moverRect.y<=475 && frog.moverRect.y != 75){
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
    for (int i = 0 ; i < scores.size() ; i++){
        scores[i]->draw();
    }
}

//This function loops through the Unit type list and compares the x and y coordinates of the frog with the x and y coordinates of each asset to check collision.
//Upon collision the frog moves back to it's original position and the health is reduced by 1 by popping the last element of the Unit type list
//The last three index of the Unit type list contains the health objects.
void LeapFrog::CheckCollision(){
    for(Unit* x: objects){
        /*if (((frog.moverRect.x-(x->moverRect.x))<40) && (abs(frog.moverRect.y-(x->moverRect.y))<12) && objects.size()>43 && string(typeid(*x).name())=="4Wood"){
            cout<<frog.moverRect.x-(x->moverRect.x)<<endl;
            music = Mix_LoadMUS("frogger-squash.wav");
	        Mix_PlayMusic(music, 1);
            objects.pop_back();
            while (pause != 2000){
                cout<<pause<<endl;
                pause++;
            }
            frog.moverRect = {232, 475, 20, 20};
            frog.srcRect = {0,365,23,17};
            pause = 0;
        }*/
        if ((abs(frog.moverRect.x-(x->moverRect.x))<12) && (abs(frog.moverRect.y-(x->moverRect.y))<12) && objects.size()>43){
            //cout<<typeid(*x).name()<<endl;
            frog.moverRect = {frog.moverRect.x-abs(frog.moverRect.x-(x->moverRect.x)),frog.moverRect.y-abs(frog.moverRect.y-(x->moverRect.y)), 20, 20};
            /*switch (animation){
                case 0:                         
                    frog.srcRect = {183,426,19,16};     
                    animation = 1;                 
                case 1:                            
                    frog.srcRect = {220, 426, 16, 16};        
                    animation = 2;                          
                default:
                    animation =  0;            
                    break;
            }*/
            music = Mix_LoadMUS("frogger-squash.wav");
	        Mix_PlayMusic(music, 1);
            objects.pop_back();
            while (pause != 2000){
                cout<<pause<<endl;
                pause++;
            }
            frog.moverRect = {232, 475, 20, 20};
            frog.srcRect = {0,365,23,17};
            pause = 0;
        }
    }
}

//This function creates a new ScoreFrog object and pushes it to the pointer vector as soon as the frog reaches the top of the screen along the 5 holes.
//It contains condition to check the moverRect.x of the frog to create the scorefrog dynamically at that particular location.
//Once the hole is filled the frog is moved back to it's original position.
void LeapFrog::updatescore(){
    if (frog.moverRect.x==232 && frog.moverRect.y==35){
        music = Mix_LoadMUS("Score.wav");
		Mix_PlayMusic(music, 1);
        ScoreFrog* score = new ScoreFrog(232, 20);
        scores.push_back(score);
        frog.moverRect = {232, 475, 20, 20};
        frog.srcRect = {0,365,23,17};
    }
    if (frog.moverRect.x==112 && frog.moverRect.y==35){
        music = Mix_LoadMUS("Score.wav");
		Mix_PlayMusic(music, 1);
        ScoreFrog* score1 = new ScoreFrog(125, 20);
        scores.push_back(score1);
        frog.moverRect = {232, 475, 20, 20};
        frog.srcRect = {0,365,23,17};
    }
    if (frog.moverRect.x==352 && frog.moverRect.y==35){
        music = Mix_LoadMUS("Score.wav");
		Mix_PlayMusic(music, 1);
        ScoreFrog* score2 = new ScoreFrog(342, 20);
        scores.push_back(score2);
        frog.moverRect = {232, 475, 20, 20};
        frog.srcRect = {0,365,23,17};
    }
    if (frog.moverRect.x==32 && frog.moverRect.y==35){
        music = Mix_LoadMUS("Score.wav");
		Mix_PlayMusic(music, 1);
        ScoreFrog* score3 = new ScoreFrog(18, 20);
        scores.push_back(score3);
        frog.moverRect = {232, 475, 20, 20};
        frog.srcRect = {0,365,23,17};
    }
    if (frog.moverRect.x==472 && frog.moverRect.y==35){
        music = Mix_LoadMUS("Score.wav");
		Mix_PlayMusic(music, 1);
        ScoreFrog* score4 = new ScoreFrog(450, 20);
        scores.push_back(score4);
        frog.moverRect = {232, 475, 20, 20};
        frog.srcRect = {0,365,23,17};
    }
}

//This function calls the factory function to return a Unit type list to create the assets dynamically and push them to the Unit type list.
//This function and factory class fulfills the Factory Design requirement.
//A check is also made to make sure that the objects are created only once or else the factory class will continue
//to return a Unit type list with the same assets as the game is being played.
void LeapFrog::createObject(){
    if (objectcheck == false){
        objects = factory.CreateObjects();
        objectcheck = true;
    }
}

//isko hatana hai yeh Homework wala function hai
void LeapFrog::createObject(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

//Deconcstructor to free the memory allocated to the Unit type list and the pointer vector scores.
LeapFrog :: ~LeapFrog(){
    for(auto&& i : objects) {
		delete i;
	}
    objects.clear();
    for(auto&& i : scores) {
		delete i;
	}
    scores.clear();
}
