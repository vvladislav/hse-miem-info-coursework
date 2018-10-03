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
    attack_.resize(0);
}

Place::Place( std::pair<int,int> coors) {
    coors_ = coors;
    attack_.resize(0);
}

Place::Place( int x, int y, Terrain ter ) {
    coors_ = std::make_pair(x,y);
    attack_.resize(0);
    ter_ = ter;
}

std::pair< int , int > const Place::getCoors() const {
    return coors_;
}

std::vector<AttackingObject*> Place::getAttack() const {
    return attack_;
}

const Terrain& Place::getTerrain() const {
    return ter_;
}

void Place::setAttack(std::vector<AttackingObject*> object) {
    attack_ = object;
}

void Place::setAttack( AttackingObject &object) {
    attack_.push_back(&object);
}

void Place::setTerrain( Terrain& ter) {
    ter_ = ter;
}

void Place::addObject(SimpleObject* newObject) {
    stand_ =  newObject;
}

void Place::removeObject() {
    stand_ = nullptr;
}
