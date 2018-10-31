#include "All-include.h"
#include "Unit.h"

Unit::Unit():MovingObject(), AttackingObject(), DestroyableObject(), SimpleObject() {
    requirements_.clear();
}

Unit::Unit(const Unit& unit):MovingObject(unit), AttackingObject(unit), DestroyableObject(unit), SimpleObject() {
    this->requirements_ = unit.getRequirements();
}

Unit& Unit::operator= ( const Unit& unit) {
    MovingObject::operator= (unit);
    DestroyableObject::operator= (unit);
    AttackingObject::operator= (unit);
    SimpleObject::operator= (unit);
    this->requirements_ = unit.getRequirements();
    return *this;
}

bool Unit::operator== ( const Unit& unit) const {
    if ((this->requirements_ == unit.getRequirements()) &&
        (static_cast< MovingObject & >(const_cast< Unit & >(*this)) ==
             static_cast< MovingObject & >(const_cast< Unit & >(unit))) &&
        (static_cast< AttackingObject & >(const_cast< Unit & >(*this)) ==
             static_cast< AttackingObject & >(const_cast< Unit & >(unit))) &&
        (static_cast< DestroyableObject & >(const_cast< Unit & >(*this)) ==
             static_cast< DestroyableObject & >(const_cast< Unit & >(unit))))
        return true;
    return false;
}

std::list < Building* > const Unit::getRequirements() const {
    return requirements_;
}

void Unit::setRequirements( std::list< Building* > requirements ) {
    requirements_ = requirements;
}

void Unit::addRequirements( Building* add) {
    requirements_.push_back( add );
}

void Unit::rmRequirements( int idRm ) {
    auto it = requirements_.begin();
    std::advance( it ,idRm);
    requirements_.erase(it);
}

bool Unit::hasRequirements() {
    return requirements_.size();
}
