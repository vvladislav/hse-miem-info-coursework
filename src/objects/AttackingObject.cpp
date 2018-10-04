#include "All-include.h" 
#include "AttackingObject.h" 

int AttackingObject::getAttack() const {
    return attack_;
}

int AttackObject::getRange() const {
    return range_
}

void AttackObject::setAttack( int const attack ) {
    attack_ = attack;
}

void AttackObject::setRange( int const range ) {
    range_ = range;
}
