#ifndef SYSTEM_H
#define SYSTEM_H
#include "vector"
#include "string"
//#include "ship.h"


//здесь вроде всё работает пока

using namespace std;

class Ship;

class System {
public :
    System(Ship* PTR) : pship(PTR) {}

    long long cost = 0;

    vector<string> system_status  = {"Undamaged","Disabled","Destroyed"};
    unsigned int systemStatus = 0;

    Ship* pship;

    unsigned int minimumTL = 7;
    bool requireSC = false;

};

#endif // SYSTEM_H
