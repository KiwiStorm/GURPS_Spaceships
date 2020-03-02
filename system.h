#ifndef SYSTEM_H
#define SYSTEM_H
#include "vector"
#include "string"


using namespace std;

class System {
public :
    System(unsigned int SM) : sm(SM) {}
    long long cost = 0;
    vector<string> system_status  = {"Undamaged","Disabled","Destroyed"};
    unsigned int systemStatus = 0;
    unsigned int sm;

};

#endif // SYSTEM_H
