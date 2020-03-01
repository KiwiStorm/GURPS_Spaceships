#include <QCoreApplication>
#include "string.h"
#include "map"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}

struct Coordinate {
    //Coordinate(long double X, long double Y, long double Z) : x(X), y(Y), z(Z) {}
    long double x = 0;
    long double y = 0;
    long double z = 0;
};



struct spaceMovementValues {
    Coordinate position;
    Coordinate speedVector;
    double currentSpeed = 0;
    Coordinate gVector;
    double currentG = 0;

};

static long double gurpsScaling1(const long double baseValue,const  int cycles) {
    long double ans = baseValue;
    for(int i = 0;i < cycles;i++) {
        if(i % 2 == 0) {
            ans*= 10;
            ans/= 3;
        }
        else {
            ans*= 3;
        }
    }
    return ans;
}

static long double gurpsScaling2(const long double baseValue,const  int cycles) {
    long double ans = baseValue;
    for(int i = 0;i < cycles;i++) {
            ans*=1.5;
    }
    return ans;
}

class GameSettings {
protected :
    int TL = 7;
    bool superscience = false;
    map <int,string> combat_scale =  {{1,"small"},{2,"medium"},{3,"large"}};
    int combatScale =1;

};

class System {
public :
    System( unsigned int SM) : sm(SM) {}
    long double  costM = 0;
    map<int,string> system_status  = {{1,"Undamaged"},{2,"Disabled"},{3,"Destroyed"}};
    unsigned int systemStatus = 1;
    unsigned int sm;

};



class CargoHold :  public System{
public  :
    CargoHold(unsigned int SM,unsigned int CARGOHOLDTYPE) : System(SM), cargoHoldType(CARGOHOLDTYPE) {
        stdCapacityT = gurpsScaling1(1.5,System::sm - 5);
        switch(cargoHoldType) {
        case 1  : {
           System::costM = 0;
           break;
        }
        case 2  : {
           refCapacityT = stdCapacityT;
           stdCapacityT = 0;
           System::costM = 0.0005 * refCapacityT;
           break;
        }
        case 3  : {
           shlCapacityT = 0.5 * stdCapacityT;
           stdCapacityT = 0;
           System::costM = shlCapacityT * 0.008;
           break;
        }


        }
    }
protected :
    long double stdCapacityT = 0;
    long double refCapacityT = 0;
    long double shlCapacityT = 0;
    map<int,string>  cargoHold_type = {{1,"Standart"},{2,"Refrigerated"},{3,"Shielded"}};
    unsigned int cargoHoldType = 1;
};

class Habitat :  public System {
public :
    unsigned int cabins = 1;
};

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
    unsigned int sm;
protected :
    unsigned int hullType;
    unsigned int dr = 0;
    map<int,string> hull_type = {{1,"Front"},{2,"Central"},{3,"Rear"}};




};

class Ship {
public :
    Ship(string NAME,unsigned int SM,unsigned int SHIPFORM) :  name(NAME), sm(SM), shipForm(SHIPFORM) {
        frontHull = new Hull(sm,1);
        centralHull =  new Hull(sm,2);
        rearHull = new Hull(sm,3);



}
    unsigned int shipId;
    int currentHP;
    spaceMovementValues currentSMV;

protected :
    map<int,string> ship_form = {{1,"sphere"},{2,"cylinder"},{3,"streamlined"}};
    string name = "Steel";    
    unsigned int sm;

    unsigned int strenght;
    unsigned int hp;

    unsigned int shipForm;
    unsigned int mass;
    unsigned int lenght;

    unsigned int costM;

    Hull* frontHull;
    Hull* centralHull;
    Hull* rearHull;


};

void buildShip( string name,unsigned int sm,unsigned int shipForm) {
    if(sm < 5 || shipForm > 3 || shipForm < 1) {
        cout << "Error : incorrect value";
    }
    Ship(name,sm,shipForm);

};


