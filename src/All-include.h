#ifndef ALL_INCLUDE_H
#define ALL_INCLUDE_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <QPixmap>


#ifdef _WIN32

#endif

#ifdef __unix__ 
#include <unistd.h>

#endif


class Terrain;
class Player;
class Place;
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

enum objectType {
    buildingType = 0,
    unitType = 1,
    resourceType = 2
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

// crossplatform absolute path
std::string givePath() {
    std::string path;
#ifdef __unix__ 
    char result[256];
    ssize_t count = readlink("/proc/self/exe", result, 256);
    path = std::string(result , (count > 0) ? count : 0);
    for (int i = path.size() - 1 ; path[i] != '/' ; --i) 
        path.pop_back();
#endif

// also for windows
    return path;
}

#endif // ALL_INCLUDE_H
