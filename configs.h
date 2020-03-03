
#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H
#include "vector"
#include "string"

//сыроватая штука, надо доделать

using namespace std;
class Configs {
public :
    Configs(unsigned int tl,bool SUPERSCIENCE) : TL(tl), superScience(SUPERSCIENCE) {
        if(tl < 7 || tl > 12) {
            //some funny error message
        }
    }

protected  :
    unsigned long maxSpeed = 300000000 / 5;//макс скорость - 20 процентов от световой (метры в секунду)
    unsigned int TL = 7;
    bool superScience = false;
    vector<string> vcombatScale = {"small","medium","large"};
    int combatScale = 0;
    static void createShip(string name,unsigned int sm,unsigned int shipForm);

};

#endif // GAMESETTINGS_H
