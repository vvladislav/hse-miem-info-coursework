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

#endif // ALL_INCLUDE_H
