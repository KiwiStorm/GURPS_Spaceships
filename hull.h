#ifndef HULL_H
#define HULL_H
#include "vector"
#include "string"
#include "system.h"
#include "cargohold.h"
#include "ship.h"


using namespace std;


class Ship;

class Hull  {
public :
    Hull(unsigned  int SM,unsigned int HULLTYPE) :  sm(SM), hullType(HULLTYPE) {
        for(int i = 0;i < 7;i++) {
            if(hullType == 3 && i == 0) {
                systems[i] = nullptr;
            }
            else {
                systems[i] = new CargoHold(sm,1);
            }
        }
}
    System* systems[7];
    Ship* pship;
    unsigned int sm;
protected :

    unsigned int dr = 0;
    vector<string> hull_type = {"Front","Central","Rear"};
    unsigned int hullType;

};
#endif // HULL_H
