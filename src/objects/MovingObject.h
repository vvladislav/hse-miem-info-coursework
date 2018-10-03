#ifndef MOVEING_OBJECT_H
#define MOVEING_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class MovingObject : virtual public SimpleObject
{
    protected:
        int speed_ = 0;
        std::pair<int,int> endPoint_;
    public:
        //MovingObject(): SimpleObject(){};
        //MovingObject(std::pair<int,int> place): SimpleObject(place){};

        virtual int const getSpeed() const ;

        virtual void setSpeed( int speed );

        virtual void addSpeed( int add );
        virtual void rmSpeed( int rm );
        virtual void move( int x , int y );
        virtual void move( std::pair<int,int> endPoint );
        virtual bool isMove();

};

#endif // MOVEING_OBJECT_H
