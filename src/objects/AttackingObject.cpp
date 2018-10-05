#include "All-include.h" 
#include "AttackingObject.h" 

int AttackingObject::getAttack() const {
    return attack_;
}

int SimpleObject::getRange() const {
    return range_
}

void SimpleObject::setAttack( int const attack ) {
    attack_ = attack;
}

void SimpleObject::setRange( int const range ) {
    range_ = range;
}
