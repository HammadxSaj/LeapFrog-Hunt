#include <iostream>
#include "LeapFrog.hpp"
using namespace std;

void LeapFrog::drawObjects()
{
    for(Unit* x: objects){
        x->draw();
        x->move();
        //cout<<x->moverRect.x<<endl; //excess x ki value like this
    }
    frog.draw();
    //cout<<frog.moverRect.x<<endl; //frog ki value like this
    //cout<<frog.moverRect.y<<endl; //frog ki value like this
    if (checkup == true){
            frog.srcRect = {0,365,23,17};
            if (frog.moverRect.y<=475 && frog.moverRect.y == 75 && frog.moverRect.x == 232){
                frog.moverRect.y -= 20;
            }
            else if (frog.moverRect.y<=475 && frog.moverRect.y == 75 && frog.moverRect.x == 112){
                frog.moverRect.y -= 20;
            }
            else if (frog.moverRect.y<=475 && frog.moverRect.y == 75 && frog.moverRect.x == 352){
                frog.moverRect.y -= 20;
            }
            else if (frog.moverRect.y<=475 && frog.moverRect.y == 75 && frog.moverRect.x == 472){
                frog.moverRect.y -= 20;
            }
            else if (frog.moverRect.y<=475 && frog.moverRect.y == 75 && frog.moverRect.x == 32){
                frog.moverRect.y -= 20;
            }
            else if (frog.moverRect.y<=475 && frog.moverRect.y != 75){
                frog.moverRect.y -= 20;
            }
            checkup = false;
    }
    else{
        checkup = false;
    }
    if (checkdown == true){
        if (frog.moverRect.y<=474){
            frog.moverRect.y += 20;
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
            frog.moverRect.x -= 20;
        }
            checkleft = false;
            frog.srcRect = {71,335,18,23};
    }
    else{
        checkleft = false;
    }
    if (checkright == true && frog.moverRect.x>0 && frog.moverRect.x<500){
        if (frog.moverRect.x<=471){
            frog.moverRect.x += 20;
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

void LeapFrog::CheckCollision(){
    for(Unit* x: objects){
        if ((abs(frog.moverRect.x-(x->moverRect.x))<12) && (abs(frog.moverRect.y-(x->moverRect.y))<12) && objects.size()>43){
            frog.moverRect = {frog.moverRect.x-abs(frog.moverRect.x-(x->moverRect.x)),frog.moverRect.y-abs(frog.moverRect.y-(x->moverRect.y)), 20, 20};
            switch (animation){
                case 0:                         //This case will become true at first since animation = 0 has been assigned.
                    frog.srcRect = {183,426,19,16};     //Generate the pigeon image having wings up
                    animation = 1;                  //Changes value of animation 1 to make the second case true for animation
                case 1:                             //After case 0 this will become true
                    frog.srcRect = {220, 426, 16, 16};        //Generate the pigeon image having wings at center
                    animation = 2;                          //Changes value of animation 2 to make the third case true for animation
                default:
                    animation =  0;             //default case will have the image of pigeon having wings up
                    break;
            }
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
    for (int i = 0 ; i < scores.size() ; i++){
        if ((abs(frog.moverRect.x-(scores[i]->moverRect.x))<12) && (abs(frog.moverRect.y-(scores[i]->moverRect.y))<12)){
        frog.moverRect = {232, 475, 20, 20};
        frog.srcRect = {0,365,23,17};
        }
    }
}

void LeapFrog::updatescore(){
    if (frog.moverRect.x==232 && frog.moverRect.y==35){
        ScoreFrog* score = new ScoreFrog(232, 20);
        scores.push_back(score);
        frog.moverRect = {232, 475, 20, 20};
        frog.srcRect = {0,365,23,17};
    }
    if (frog.moverRect.x==112 && frog.moverRect.y==35){
        ScoreFrog* score1 = new ScoreFrog(125, 20);
        scores.push_back(score1);
        frog.moverRect = {232, 475, 20, 20};
        frog.srcRect = {0,365,23,17};
    }
    if (frog.moverRect.x==352 && frog.moverRect.y==35){
        ScoreFrog* score2 = new ScoreFrog(342, 20);
        scores.push_back(score2);
        frog.moverRect = {232, 475, 20, 20};
        frog.srcRect = {0,365,23,17};
    }
    if (frog.moverRect.x==32 && frog.moverRect.y==35){
        ScoreFrog* score3 = new ScoreFrog(18, 20);
        scores.push_back(score3);
        frog.moverRect = {232, 475, 20, 20};
        frog.srcRect = {0,365,23,17};
    }
    if (frog.moverRect.x==472 && frog.moverRect.y==35){
        ScoreFrog* score4 = new ScoreFrog(450, 20);
        scores.push_back(score4);
        frog.moverRect = {232, 475, 20, 20};
        frog.srcRect = {0,365,23,17};
    }
}

void LeapFrog::createObject(){
    if (objectcheck == false){
        objects = factory.CreateObjects();
        objectcheck = true;
    }
}
void LeapFrog::createObject(int x, int y)
{
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

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
