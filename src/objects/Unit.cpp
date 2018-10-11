#include "All-include.h"
#include "Unit.h"

Unit::Unit():MovingObject(), AttackingObject(), DestroyingObject(),SimpleObject() {
    id_ = std::make_pair(0,0);
    require_.clear();
}

Unit::Unit(const Unit& unit):MovingObject(unit), AttackingObject(unit), DestroyingObject(unit) {
    this->id_ = unit.getId();
    this->require_ = unit.getRequire();
}

Unit& Unit::operator= ( const Unit& unit) {
    this->id_ = unit.getId();
    this->require_ = unit.getRequire();
    return *this;
}

std::list < Building* > const Unit::getRequire() const {
    return require_;
}

std::pair<int,int> Unit::getId() const {
    return id_;
}

void Unit::setRequire( std::list< Building* > require ) {
    require_ = require;
}

void Unit::setId( std::pair<int,int> id ) {
    id_ = id;
}

void Unit::addRequire( Building* add) {
    require_.push_back( add );
}

void Unit::rmRequire( int idRm ) {
    auto it = require_.begin();
    std::advance( it ,idRm);
    require_.erase(it);
}

bool Unit::hasRequire() {
    return require_.size();
}
