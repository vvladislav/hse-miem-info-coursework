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
        MovingObject();
        MovingObject(const MovingObject& movingObject);
        MovingObject& operator= ( const MovingObject& movingObject);

        int const getSpeed() const ;

        void setSpeed( int speed );

        void addSpeed( int add );
        void rmSpeed( int rm );
        void move( int x , int y );
        void move( std::pair<int,int> endPoint );
        bool isMove();

};

#endif // MOVEING_OBJECT_H
