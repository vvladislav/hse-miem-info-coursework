#ifndef ATTACKING_OBJECT_H
#define ATTACKING_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class AttackingObject : virtual public SimpleObject
{
    protected:
        int damage_;
        int range_;
        Place* target_ = nullptr;
        int typeTarget_ = 0;
    public:
        AttackingObject();
        AttackingObject(const AttackingObject& attackingObject);
        AttackingObject& operator= ( const AttackingObject& attackingObject);
        bool operator== ( const AttackingObject& attackingObject) const;

        int getDamage() const;
        int getRange() const;
        Place* getTarget() const;

        void setDamage( int power );
        void setRange( int range );
        void setTarget( Place* target );

};

#endif // ATTACKING_OBJECT_H
