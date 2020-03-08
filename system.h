#ifndef SYSTEM_H
#define SYSTEM_H
#include "vector"
#include "string"
#include "globalfunctions.h"
//#include "ship.h"


//здесь вроде всё работает пока

using namespace std;

class Ship;

class System {
public :
    System(Ship* PTR) : pship(PTR) {}
    virtual ~System();
    long long cost = 0;

    vector<string> system_status  = {"Undamaged","Disabled","Destroyed"};
    unsigned int systemStatus = 0;

    Ship* pship;

    unsigned int minimumTL = 7;
    bool requireSC = false;
    unsigned workspacesRequired;

    virtual string returnSystemType();


};

#endif // SYSTEM_H
