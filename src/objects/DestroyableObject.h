#ifndef DESTROYABLE_OBJECT_H
#define DESTROYABLE_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class DestroyableObject : virtual public SimpleObject
{
    protected:
        int health_;
    public:
        DestroyableObject();
        DestroyableObject( const DestroyableObject& destroyableObject);
        DestroyableObject& operator= ( const DestroyableObject& destroyableObject );
        bool operator== ( const DestroyableObject& destroyableObject) const;
        DestroyableObject& operator- ( int rm );
        DestroyableObject& operator+ ( int add );

        int const getHealth() const ;

        void setHealth( int health );

        void addHealth( int add );
        void rmHealth( int rm );

        ~DestroyableObject();

};

#endif // DESTROYABLE_OBJECT_H
