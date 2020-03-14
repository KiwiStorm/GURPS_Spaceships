#ifndef HULL_H
#define HULL_H
#include "vector"
#include "string"
#include "system.h"

using namespace std;

class Ship;
class ShipBuilder;

class Hull  {
public :
    Hull(Ship* PTR, unsigned  int SM,unsigned int HULLTYPE) :  sm(SM), hullType(HULLTYPE), pship(PTR) {
        for(int i = 0;i < 7;i++) {
            systems[i] = nullptr;
        }
}
    System* systems[7];
    Ship* parentPTR() {return this->pship;}

protected :
    unsigned int sm;
    unsigned int dr = 0;
    vector<string> hull_type = {"Front","Central","Rear"};
    unsigned int hullType;
    Ship* pship;
    friend ShipBuilder;
};
#endif // HULL_H
