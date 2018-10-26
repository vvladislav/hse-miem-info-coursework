#include "All-include.h" 
#include "AttackingObject.h" 

AttackingObject::AttackingObject():SimpleObject() {
    attack_ = 0;
    range_ = 0;
}

AttackingObject::AttackingObject(const AttackingObject& attackingObject): SimpleObject(attackingObject) {
    this->attack_ = attackingObject.getAttack(); 
    this->range_ = attackingObject.getRange();
}

AttackingObject& AttackingObject::operator= ( const AttackingObject& attackingObject) {
    SimpleObject::operator= (attackingObject);
    this->attack_ = attackingObject.getAttack(); 
    this->range_ = attackingObject.getRange();
    return *this;
}

bool AttackingObject::operator== ( const AttackingObject& attackingObject) const {
    if ((this->attack_      == attackingObject.getAttack()) &&
        (this->range_   == attackingObject.getRange()) &&
        (static_cast< SimpleObject & >(const_cast< AttackingObject & >(*this)) ==
             static_cast< SimpleObject & >(const_cast< AttackingObject & >(attackingObject))))
        return true;
    return false;
}

int AttackingObject::getAttack() const {
    return attack_;
}

int AttackingObject::getRange() const {
    return range_;
}

void AttackingObject::setAttack( int const attack ) {
    attack_ = attack;
}

void AttackingObject::setRange( int const range ) {
    range_ = range;
}
