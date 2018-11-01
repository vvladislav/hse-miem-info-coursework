#ifndef ATTACKING_OBJECT_H
#define ATTACKING_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class AttackingObject : virtual public SimpleObject
{
    protected:
        int damage_;
        int range_;
    public:
        AttackingObject();
        AttackingObject(const AttackingObject& attackingObject);
        AttackingObject& operator= ( const AttackingObject& attackingObject);
        bool operator== ( const AttackingObject& attackingObject) const;

        int getDamage() const;
        int getRange() const;

        void setDamage( int const power );
        void setRange( int const range );

};

#endif // ATTACKING_OBJECT_H
