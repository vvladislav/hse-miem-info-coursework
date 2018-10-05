#ifndef DESTROYING_OBJECT_H
#define DESTROYING_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class DestroyingObject : virtual public SimpleObject
{
    protected:
        int health_;
    public:
        DestroyingObject();
        DestroyingObject(const DestroyingObject& destroyingObject);
        DestroyingObject& operator= ( const DestroyingObject& destroyingObject );
        DestroyingObject& operator- ( int rm );
        DestroyingObject& operator+ ( int add );

        int const getHealth() const ;

        void setHealth( int health );

        void addHealth( int add );
        void rmHealth( int rm );

        bool isAlive();

};

#endif // DESTROYING_OBJECT_H
