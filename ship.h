#ifndef SHIP_H
#define SHIP_H
#include "vector"
#include "string"
#include "hull.h"
#include "Space_movement_state.h"

//#include "globalfunctions.h"

using namespace std;

//добавлены не все функции и методы

class ShipBuilder;
class Player;

class Ship  {
public :
    Ship(string NAME,unsigned int SM,unsigned int SHIPFORM) :   SM(SM), name(NAME), shipForm(SHIPFORM), sms() {
        strenght = gurpsScaling2(200, SM-5);
        hitPoins = strenght;
        currentHP = hitPoins;

        handlingRating = (SM - 4) / (-3);
        if(SM >= 7) {stabilityRating++;}

        baseMass = gurpsScaling1(30,SM - 5);
        switch(shipForm){
        case 0 : {
            lenght = gurpsScaling2(15, SM - 5) / 2;
            isStreamlined = false;
            break;
        }
        case 1 : {
            lenght = gurpsScaling2(15, SM - 5);
            isStreamlined = true;
            break;
        }
        case 2 : {
            lenght = gurpsScaling2(15, SM - 5) * 15 / 10;
            isStreamlined = true;
            break;
        }
        case 3 : {
            lenght = gurpsScaling2(15, SM - 5) / 7 * 10;
            isStreamlined = false;
            break;
        }
        }

}
    Player *controledBy;
    int getSM() {return this->SM;}
    void calculateCost();
    void addDeltaV(unsigned int amount) {deltaV+=amount;}
    void decreaseDeltaV(unsigned int amount) {deltaV-=amount;}
    Space_movement_state sms;
    Hull* hulls[3] = {nullptr,nullptr,nullptr};

protected :
    int SM;

    int currentHP;

    string name = "Steel";
    unsigned int baseMass; //тонны
    unsigned int lenght; //метры

    vector<string> ship_form = {"sphere","cylinder","streamlined","undefined"};
    unsigned int shipForm;
    bool isStreamlined;

    unsigned int htalth = 13;
    unsigned int strenght;
    unsigned int hitPoins;
    int handlingRating = 0;
    int stabilityRating = 4;

    unsigned int cost; //в $

    bool infiniteDeltaV = false;
    unsigned int deltaV = 0; //метры в секунду

    friend ShipBuilder;
};

void Ship::calculateCost() {
    this->cost = 0;
    for(int h;h <3;h++){
        for(int i;i < 7;i++) {
            if(this->hulls[h]->systems[i] == nullptr) {continue;}
            this->cost+= this->hulls[h]->systems[i]->cost;
    }
    }
}


#endif // SHIP_H
