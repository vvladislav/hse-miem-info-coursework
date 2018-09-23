#ifndef MOVEING_OBJECT_H
#define MOVEING_OBJECT_H

#include "All-include.h"

class MovingObject : SimpleObject
{
    protected:
        int speed;
    public:
        MovingObject(): SimpleObject(){};
        MovingObject(std::pair<int,int> place): SimpleObject(std::pair<int,int> place){};

        int const getSpeed() const ;

        void setSpeed( int Speed );

        void addSpeed( int add );
        void rmSpeed( int rm );
        void move( int x , int y );

};

#endif // MOVEING_OBJECT_H
