#ifndef DESTROYING_OBJECT_H
#define DESTROYING_OBJECT_H

#include "All-include.h"

class DestroyingObject : SimpleObject
{
    protected:
        int health;
    public:
        DestroyingObject(): SimpleObject(){};
        DestroyingObject(std::pair<int,int> place): SimpleObject(std::pair<int,int> place){};

        int const getHealth() const ;

        void setHealth( int Health );

        void addHealth( int add );
        void rmHealth( int rm );

};

#endif // DESTROYING_OBJECT_H
