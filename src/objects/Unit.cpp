#include "All-include.h"
#include "Unit.h"

std::list < Building* > const Unit::getRequire() const {
    return require_;
}

std::pair<int,int> Unit::getId() const {
    return id_;
}

Unit& Unit::operator= ( const Unit& unit) {
    this->id_ = unit.getId();
    this->require_ = unit.getRequire();
    this->place_ = unit.MovingObject::SimpleObject::getPlace();
    return *this;
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
