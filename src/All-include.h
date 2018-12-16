#ifndef ALL_INCLUDE_H
#define ALL_INCLUDE_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>


#ifdef _WIN32

#endif

#ifdef __unix__ 
#include <unistd.h>

#endif


class Terrain;
class Place;
class Player;
class Map;
class SimpleObject;
class AttackingObject;
class DestroyingObject;
class MovingObject;
class Building;
class Unit;
class ResourceObject;

// enum for colors

enum resources {
    gold = 0,
    stone = 1

};

enum mainwindow {
    mainMenu=0,
    gameGui=1,
    gameMenu=2,
    editorMenu=3,
    editorUnitMenu=4,
    editorBuildingMenu=5,
    settingsMenu=6,
    editorMapMenu=7,
    chooseCardMenu=8
};

#endif // ALL_INCLUDE_H
