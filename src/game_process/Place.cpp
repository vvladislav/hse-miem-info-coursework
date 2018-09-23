#include "All-include.h"
#include "Place.h"

Place::Place() {
    coors_ = (0,0);
    attack_.resize(0);
}

Place::Place(const Place& place) {
    this->coors_ = place.getCoors();
    this->attack_ = place.getAttack();
}

Place& Place::operator = (const Place& place) {
    this->coors_ = place.getCoors();
    this->attack_ = place.getAttack();
}

Place::Place( int x, int y ) {
    coors_ = (x,y);
    attack_.resize(0);
}

Place::Place( std::pair<int,int> coors) {
    coors_ = coors;
    attack_.resize(0);
}

Place::Place( int x, int y, Terrain ter ) {
    coors_ = (x,y);
    attack_.resize(0);
    ter_ = ter;
}

std::pair< int , int > const getCoors() const {
    return coors_;
}

std::vector<attackObject*> getAttackObjects() const {
    return attack_;
}

terrain getTerrain() const {
    return ter_;
}

void setAttack(std::vector<attackObject*> object) {
    attack_ = object;
}

void setAttack( attackObject object) {
    attack_.push_back(&object);
}

void setTerrain( &terrain ter) {
    ter_ = ter;
}

void addObject(Object newObject) {
    stand_ =  newObject;
}

void removeObject() {
    stand_ = nullptr;
}

}
