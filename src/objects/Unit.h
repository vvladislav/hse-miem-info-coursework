#ifndef MOVEING_OBJECT_H
#define MOVEING_OBJECT_H

#include "All-include.h"

class Unit : MovingObject, DestroyingObject
{
    private:
        Weapon weapon;
        // add id
    protected:
        int speed;
    public:
        Unit:: MovingObject(){};
        Unit(std::pair<int,int> place):: MovingObject(std::pair<int,int> place){};


};

#endif // MOVEING_OBJECT_H
