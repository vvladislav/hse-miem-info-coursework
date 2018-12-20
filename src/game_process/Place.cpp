#include "All-include.h"
#include "Unit.h"
#include "Building.h"
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

std::list< std::pair< std::pair<int,int> , int > > Place::getAttackedBy() const {
    return attackedBy_;
}

const Terrain& Place::getTerrain() const {
    return ter_;
}

std::pair< std::pair <int,int> , int > Place::getObject() const {
    return object_;
}

void Place::setAttackedBy(std::list< std::pair< std::pair<int,int> , int > > object) {
    attackedBy_ = object;
}

void Place::addAttackedBy( Unit &object) {
    attackedBy_.push_back(std::make_pair(object.getId(),1));
}

void Place::addAttackedBy( Building &object) {
    attackedBy_.push_back(std::make_pair(object.getId(),0));
}

void Place::setTerrain( Terrain& ter) {
    ter_ = ter;
}

void Place::setObject(std::pair< std::pair <int,int> , int > newObject) {
    object_ =  newObject;
}

void Place::setObject( const Unit* newObject) {
    object_ =  std::make_pair(newObject->getId(),1);
}

void Place::setObject( const Building* newObject) {
    object_ =  std::make_pair(newObject->getId(),0);
}

void Place::setObject( Unit* newObject) {
    object_ =  std::make_pair(newObject->getId(),1);
}

void Place::setObject( Building* newObject) {
    object_ =  std::make_pair(newObject->getId(),0);
}
