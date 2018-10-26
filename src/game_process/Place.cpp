#include "All-include.h"
#include "Place.h"

Place::Place() {
    coors_ = std::make_pair(0,0);
    attack_.resize(0);
}

Place::Place(const Place& place) {
    this->coors_ = place.getCoors();
    this->attack_ = place.getAttack();
}

Place& Place::operator = ( const Place& place) {
    this->coors_ = place.getCoors();
    this->attack_ = place.getAttack();
    return *this;
}

Place::Place( int x, int y ) {
    coors_ = std::make_pair(x,y);
    attack_.clear();
}

Place::Place( std::pair<int,int> coors) {
    coors_ = coors;
    attack_.clear();
}

Place::Place( int x, int y, Terrain ter ) {
    coors_ = std::make_pair(x,y);
    attack_.clear();
    ter_ = ter;
}

std::pair< int , int > const Place::getCoors() const {
    return coors_;
}

std::list<AttackingObject*> Place::getAttack() const {
    return attack_;
}

const Terrain& Place::getTerrain() const {
    return ter_;
}

const SimpleObject* Place::getObject() const {
    return object_;
}

void Place::setAttack(std::list<AttackingObject*> object) {
    attack_ = object;
}

void Place::setAttack( AttackingObject &object) {
    attack_.push_back(&object);
}

void Place::setTerrain( Terrain& ter) {
    ter_ = ter;
}

void Place::setObject(SimpleObject* newObject) {
    object_ =  newObject;
}
