#ifndef CARGOHOLD_H
#define CARGOHOLD_H
#include "vector"
#include "string"


using namespace std;

class CargoHold :  public System{
public  :
    CargoHold(unsigned int SM,unsigned int CARGOHOLDTYPE) : System(SM), cargoHoldType(CARGOHOLDTYPE) {
        stdCapacityT = gurpsScaling1(1.5,System::sm - 5);
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
    long double stdCapacityT = 0;
    long double refCapacityT = 0;
    long double shlCapacityT = 0;
    vector<string>  cargoHold_type = {"Standart","Refrigerated","Shielded"};
    unsigned int cargoHoldType = 0;
};


#endif // CARGOHOLD_H
