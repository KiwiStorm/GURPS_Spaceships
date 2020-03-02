#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H
#include "vector"
#include "string"


using namespace std;

static long double gurpsScaling1(const long double baseValue,const  int cycles) { //для увеличения стоимости и большиества характеристик
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

static long double gurpsScaling2(const long double baseValue,const  int cycles) {//для увеличения размера
    long double ans = baseValue;
    for(int i = 0;i < cycles;i++) {
            ans*=1.5;
    }
    return ans;
}

#endif // GLOBALFUNCTIONS_H
