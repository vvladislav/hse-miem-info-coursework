#ifndef DESTROYING_OBJECT_H
#define DESTROYING_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class DestroyingObject : virtual public SimpleObject
{
    protected:
        int health_ = 0;
    public:
        //DestroyingObject(): SimpleObject(){};
        //DestroyingObject(std::pair<int,int> place): SimpleObject(place){};

        virtual int const getHealth() const ;

        virtual void setHealth( int health );

        virtual void addHealth( int add );
        virtual void rmHealth( int rm );

        virtual bool isAlive();

};

#endif // DESTROYING_OBJECT_H
