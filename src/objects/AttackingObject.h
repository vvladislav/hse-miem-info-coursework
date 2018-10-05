#ifndef ATTACKING_OBJECT_H
#define ATTACKING_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class AttackingObject : virtual public SimpleObject
{
    protected:
        int attack_;
        int range_;
    public:
        AttackingObject();
        AttackingObject(const AttackingObject& attackingObject);
        AttackingObject& operator= ( const AttackingObject& attackingObject);

        int getAttack() const;
        int getRange() const;

        void setAttack( int const power );
        void setRange( int const range );

};

#endif // ATTACKING_OBJECT_H
