#include "All-include.h"
#include "Unit.h"

Unit::Unit():MovingObject(), AttackingObject(), DestroyableObject(), SimpleObject() {
    requirements_.clear();
}

Unit::Unit(const Unit& unit):MovingObject(unit), AttackingObject(unit), DestroyableObject(unit), SimpleObject() {
    this->requirements_ = unit.getRequirements();
}

Unit::Unit(std::string name, int adress ,placeWidth, int placeHight, QPixmap* image
    , int damage, int range, int health, int speed, std::list<Building*>& requirements) {
    id_           = std::make_pair(-1,adress);
    placeWidth_   = placeWidth;
    placeHight_   = placeHight;
    image_        = image;
    damage_       = damage;
    range_        = range;
    health_       = health;
    speed_        = speed;
    requirements_ = requirements;
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
    return (this->id_ == unit.id_);
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
