#ifndef ATTACKING_OBJECT_H
#define ATTACKING_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class AttackingObject : virtual public SimpleObject
{
    protected:
        int power_ = 0;
        int range_ = 0;
    public:
       //AttachikgObject(): SimpleObject(){};
       //AttachikgObject(std::pair<int,int> place): SimpleObject(place){};

       int getAttack() const;
       int getRange() const;

       void setAttack( int const power );
       void setRange( int const range );

};

#endif // ATTACKING_OBJECT_H
