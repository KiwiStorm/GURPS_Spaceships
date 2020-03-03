#ifndef CARGOHOLD_H
#define CARGOHOLD_H
#include "vector"
#include "string"
#include "system.h"
#include "globalfunctions.h"

//что-то сделать с типами данных, но пока всё работает

//надо реализовать частичное использование отсеков

using namespace std;


class Ship;

class CargoHold :  public System{
public  :
    CargoHold(Ship* PTR) : System (PTR) {}
    CargoHold(Ship* PTR,unsigned int sm, unsigned int CARGOHOLDTYPE) : System(PTR), SM(sm), cargoHoldType(CARGOHOLDTYPE) {
        stdCapacityT = gurpsScaling1(1.5,SM - 5);
        switch(cargoHoldType) {
        case 1  : {
           System::cost = 0;
           break;
        }
        case 2  : {
           refCapacityT = stdCapacityT;
           stdCapacityT = 0;
           System::cost = 500 * refCapacityT;
           break;
        }
        case 3  : {
           shlCapacityT =  stdCapacityT / 2;
           stdCapacityT = 0;
           System::cost = shlCapacityT * 8000;
           break;
        }
        }
    }
protected :
    static const unsigned int systemID = 0; //- сейчас не нужно, но может пригодиться
    unsigned int SM = 5;
    long double stdCapacityT = 0;
    long double refCapacityT = 0;
    long double shlCapacityT = 0;
    vector<string>  cargoHold_type = {"Standart","Refrigerated","Shielded"};
    unsigned int cargoHoldType = 0;
};


#endif // CARGOHOLD_H
