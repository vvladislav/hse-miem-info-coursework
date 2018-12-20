#ifndef MOVEING_OBJECT_H
#define MOVEING_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class MovingObject : virtual public SimpleObject
{
    protected:
        int speed_ = 0;
        std::pair<int,int> destination_;
    public:
        // methods
        std::list<std::pair<int,int>> path_;
        // functions
        MovingObject();
        MovingObject( const MovingObject& movingObject);
        MovingObject& operator= ( MovingObject& movingObject);
        bool operator== ( const MovingObject& movingObject) const; 

        int const getSpeed() const ;
        const std::pair<int,int> getDestination() const ;

        void setSpeed( int speed );
        void setDestination( int x , int y );
        void setDestination( std::pair<int,int> destination );

        void addSpeed( int add );
        void rmSpeed( int rm );
        bool isMove();
        void calculatePath();

};

#endif // MOVEING_OBJECT_H
