#ifndef HANGAR_H
#define HANGAR_H
#include "vector"
#include "string"
#include "configs.h"
#include "builder.h"

using namespace std;

//класс отвечает за изменение кораблей вне битвы через shipBuilder

class Game;
class Hangar {
    ShipBuilder *ShB;

    void repairShip(Ship *ship); //вернуть корабль к изначальному состоянию
    void startNewGame(vector<Ship> &ships); //создать игру и добавить туда корабли
    void addToGame(vector<Ship> &ships,Game *game); //добавить нужные корабли в игру и перейти к игре
};

#endif // HANGAR_H
