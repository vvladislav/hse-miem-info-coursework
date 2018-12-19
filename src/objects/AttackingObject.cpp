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
    return (this->id_ == attackingObject.id_);
}

int AttackingObject::getDamage() const {
    return damage_;
}

int AttackingObject::getRange() const {
    return range_;
}

Place* getTarget() const {
    return target_;
}

void AttackingObject::setDamage( int damage ) {
    damage_ = damage;
}

void AttackingObject::setRange( int range ) {
    range_ = range;
}

void setTarget( Place* target ) {
    target_ = target;
}
