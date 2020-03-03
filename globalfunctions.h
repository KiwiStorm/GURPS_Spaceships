#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H
#include "vector"
#include "string"
#include "random"


using namespace std;

int roll3d6() {
    return rand() % 6 + rand() % 6 + rand() % 6 + 3;
}

int skillCheck(int bonus, int skill) { //0 - крит провал, 1 - провал, 2 - успех, 3 - крит успех
    int rollResult = roll3d6();
    int effectiveSkill = skill + bonus;
    if(rollResult == 3 && effectiveSkill >= 3)  {return 3;}  //куча строк, зато красиво и понятно
    if(rollResult == 4 && effectiveSkill >= 4)  {return 3;}
    if(rollResult == 5 && effectiveSkill >= 15) {return 3;}
    if(rollResult == 6 && effectiveSkill >= 16) {return 3;}
    if(rollResult == 18) {return 0;}
    if(rollResult == 17 && effectiveSkill <  16) {return 0;}
    if(rollResult == 17 && effectiveSkill >= 16) {return 1;}
    if(rollResult >= effectiveSkill + 10) {return 0;}
    if(rollResult <= effectiveSkill) {return 2;}
    if(rollResult > effectiveSkill) {return 1;}
}

static long double gurpsScaling1(const long double baseValue,const  int cycles) { //для увеличения стоимости и большинства характеристик
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

static long double gurpsScaling2(const long double baseValue,const  int cycles) {//для увеличения размера, пока пробный вариант, там сложнее всё
    long double ans = baseValue;
    for(int i = 0;i < cycles;i++) {
            ans*=1.5;
    }
    return ans;
}



#endif // GLOBALFUNCTIONS_H
