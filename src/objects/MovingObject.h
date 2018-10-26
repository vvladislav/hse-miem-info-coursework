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
        const std::pair<int,int> getEndPoint() const ;

        void setSpeed( int speed );
        void setEndPoint( int x , int y );
        void setEndPoint( std::pair<int,int> endPoint );

        void addSpeed( int add );
        void rmSpeed( int rm );
        bool isMove();

};

#endif // MOVEING_OBJECT_H
