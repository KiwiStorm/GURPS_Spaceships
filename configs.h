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
    const int lightSpeed  = 299792458;
    unsigned long maxSpeed = 299792458 / 5;//макс скорость - 20 процентов от световой (метры в секунду)
    unsigned int TL = 7;
    bool superScience = false;


};

#endif // GAMESETTINGS_H
