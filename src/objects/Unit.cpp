#include "All-include.h"
#include "Unit.h"

Unit::Unit():MovingObject(), AttackingObject(), DestroyableObject(), SimpleObject() {
    requirements_.clear();
}

Unit::Unit( const Unit& unit):MovingObject(unit), AttackingObject(unit), DestroyableObject(unit), SimpleObject() {
    this->requirements_ = unit.getRequirements();
}

Unit::Unit(std::string name, int adress , int placeWidth, int placeHight, QPixmap* image
    , int damage, int range, int health, int speed, std::list<Building*>& requirements) {
    id_           = std::make_pair(-1,adress);
    image_        = image;
    damage_       = damage;
    range_        = range;
    health_       = health;
    speed_        = speed;
    requirements_ = requirements;
}

Unit& Unit::operator= ( const Unit& unit) {
    damage_         = unit.damage_;
    range_          = unit.range_;
    target_         = unit.target_;
    typeTarget_     = unit.typeTarget_;
    health_         = unit.health_;
    speed_          = unit.speed_;
    destination_    = unit.destination_;
    path_           = unit.path_;
    place_          = unit.place_;
    id_             = unit.id_;
    name_           = unit.name_;
    image_          = unit.image_;
    requirements_   = unit.getRequirements();
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

void Unit::setPlaces( std::vector<std::vector<Place*>> place) {
    place_ = place;
    for ( int i = 0; i < place_.size(); ++i ) {
        for ( int j = 0; j < place_[i].size(); ++j ) {
            place_[i][j]->setObject(this);
        }
    }
}

void Unit::setPlace( Place* place, Map& map) {
    int k1 = place->getCoors().first;
    int k2 = place->getCoors().second;
    for ( int i = 0; i < place_.size(); ++i ) {
        for ( int j = 0; j < place_[i].size(); ++j ) {
            map[k1+i][k2+j].setObject(this);
            *(place_[i][j]) = map[k1+i][k2+j];
        }
    }
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
