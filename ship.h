#ifndef SHIP_H
#define SHIP_H
#include "vector"
#include "string"
#include "hull.h"


using namespace std;




class Ship  {
public :
    Ship(string NAME,unsigned int SM,unsigned int SHIPFORM) :  name(NAME), sm(SM), shipForm(SHIPFORM) {
        frontHull = new Hull(sm,1);
        centralHull =  new Hull(sm,2);
        rearHull = new Hull(sm,3);



}

    unsigned int shipId;
    int currentHP;

protected :
    unsigned int sm;

    string name = "Steel";
    unsigned int mass; //тонны
    unsigned int lenght; //метры

    vector<string> ship_form = {"sphere","cylinder","streamlined"};
    unsigned int shipForm;



    unsigned int strenght;
    unsigned int health;

    unsigned int cost; //в $

    bool infiniteDeltaV = 0;
    unsigned int deltaV = 0; //метры в секунду

    Hull* frontHull;
    Hull* centralHull;
    Hull* rearHull;


};




#endif // SHIP_H
