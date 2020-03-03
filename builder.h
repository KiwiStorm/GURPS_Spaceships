
#ifndef BUILDER_H
#define BUILDER_H
#include "vector"
#include "string"
#include "cargohold.h"
#include "ship.h"
#include "hull.h"
#include "system.h"
#include "configs.h"

using namespace std;


//    vector<string> systemCodes = {"CargoHold","Habitat"}; - сейчас не нужно, но может пригодиться
class ShipBuilder {
protected :

Configs currentSettings;

System* createCargoHold(Ship* PTR, unsigned int chType);
Hull*   createHull(Ship* PTR, unsigned int hullType);
Ship*   createShip(string NAME,unsigned int SM,unsigned int SHIPFORM);


};

System* ShipBuilder::createCargoHold(Ship* PTR, unsigned int chType) {
    if(!(chType == 0 || chType == 1 || chType == 2)) {
        //кинуть исключение
    }
    return new CargoHold(PTR,PTR->getSM(),chType);
}

Hull*   ShipBuilder::createHull(Ship* PTR, unsigned int hullType) {
    if(!(hullType == 0 || hullType == 1 || hullType == 2)) {
        //кинуть исключение или придумать что-то получше
    }
    return new Hull(PTR, PTR->getSM(),hullType);
}

Ship*  ShipBuilder::createShip(string NAME,unsigned int SM, unsigned int SHIPFORM){
    Ship* ship = new Ship(NAME,SM,SHIPFORM);
    for(unsigned int i = 0;i <3;i++) {
        ship->hulls[i] = this->createHull(ship, i);
    }
    //реализвать индивидуальаное создание систем
    return ship;
}

#endif // BUILDER_H
