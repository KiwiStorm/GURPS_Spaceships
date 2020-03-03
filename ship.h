#ifndef SHIP_H
#define SHIP_H
#include "vector"
#include "string"
#include "hull.h"
#include "globalfunctions.h"

using namespace std;

//добавлены не все функции и методы

class ShipBuilder;

class Ship  {
public :
    Ship(string NAME,unsigned int SM,unsigned int SHIPFORM) :   SM(SM), name(NAME), shipForm(SHIPFORM) {
        strenght = gurpsScaling2(200, SM-5);
        health = strenght;
        currentHP = health;
}

    unsigned int getSM() {return this->SM;}
    void calculateCost();
    void addDeltaV(unsigned int amount) {deltaV+=amount;}
    void decreaseDeltaV(unsigned int amount) {deltaV-=amount;}

    Hull* hulls[3] = {nullptr,nullptr,nullptr};

protected :
    unsigned int SM;

    int currentHP;

    string name = "Steel";
    unsigned int mass; //тонны
    unsigned int lenght; //метры

    vector<string> ship_form = {"sphere","cylinder","streamlined"};
    unsigned int shipForm;

    unsigned int strenght;
    unsigned int health;

    unsigned int cost; //в $

    bool infiniteDeltaV = false;
    unsigned int deltaV = 0; //метры в секунду



//    friend ShipBuilder;
};




#endif // SHIP_H
