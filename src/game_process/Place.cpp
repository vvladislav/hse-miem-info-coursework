#include "All-include.h"
#include "Place.h"

Place::Place() {
    coors_ = std::make_pair(0,0);
    attackedBy_.resize(0);
}

Place::Place(const Place& place) {
    this->coors_ = place.getCoors();
    this->attackedBy_ = place.getAttackedBy();
}

Place& Place::operator = ( const Place& place) {
    this->coors_ = place.getCoors();
    this->attackedBy_ = place.getAttackedBy();
    return *this;
}

Place::Place( int x, int y ) {
    coors_ = std::make_pair(x,y);
    attackedBy_.clear();
}

Place::Place( std::pair<int,int> coors) {
    coors_ = coors;
    attackedBy_.clear();
}

Place::Place( int x, int y, Terrain ter ) {
    coors_ = std::make_pair(x,y);
    attackedBy_.clear();
    ter_ = ter;
}

std::pair< int , int > const Place::getCoors() const {
    return coors_;
}

std::list<AttackingObject*> Place::getAttackedBy() const {
    return attackedBy_;
}

const Terrain& Place::getTerrain() const {
    return ter_;
}

const SimpleObject* Place::getObject() const {
    return object_;
}

void Place::setAttackedBy(std::list<AttackingObject*> object) {
    attackedBy_ = object;
}

void Place::setAttackedBy( AttackingObject &object) {
    attackedBy_.push_back(&object);
}

void Place::setTerrain( Terrain& ter) {
    ter_ = ter;
}

void Place::setObject(SimpleObject* newObject) {
    object_ =  newObject;
}
