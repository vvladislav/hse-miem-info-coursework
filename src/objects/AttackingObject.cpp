#include "All-include.h" 
#include "AttackingObject.h" 

AttackingObject::AttackingObject():SimpleObject() {
    damage_ = 0;
    range_ = 0;
}

AttackingObject::AttackingObject(const AttackingObject& attackingObject): SimpleObject(attackingObject) {
    this->damage_ = attackingObject.getDamage(); 
    this->range_ = attackingObject.getRange();
}

AttackingObject& AttackingObject::operator= ( const AttackingObject& attackingObject) {
    SimpleObject::operator= (attackingObject);
    this->damage_ = attackingObject.getDamage(); 
    this->range_ = attackingObject.getRange();
    return *this;
}

bool AttackingObject::operator== ( const AttackingObject& attackingObject) const {
    if ((this->damage_      == attackingObject.getDamage()) &&
        (this->range_   == attackingObject.getRange()) &&
        (static_cast< SimpleObject & >(const_cast< AttackingObject & >(*this)) ==
             static_cast< SimpleObject & >(const_cast< AttackingObject & >(attackingObject))))
        return true;
    return false;
}

int AttackingObject::getDamage() const {
    return damage_;
}

int AttackingObject::getRange() const {
    return range_;
}

void AttackingObject::setDamage( int const damage ) {
    damage_ = damage;
}

void AttackingObject::setRange( int const range ) {
    range_ = range;
}
