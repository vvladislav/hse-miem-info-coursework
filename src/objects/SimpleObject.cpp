#include "All-include.h"
#include "SimpleObject.h"

SimpleObject::SimpleObject() {
    id_         = std::make_pair(-1,-1);
    place_.resize(0);
    name_       = "No name";
}

SimpleObject::SimpleObject( std::vector< std::vector< Place* > > place) {
    id_    = std::make_pair(-1,-1);
    place_ = place;
    name_  = "No name";
}

SimpleObject::SimpleObject(const SimpleObject& simpleObject) {
    this->id_         = simpleObject.id_;
    this->place_      = simpleObject.place_;
    this->name_  = simpleObject.name_;
}

SimpleObject& SimpleObject::operator= ( const SimpleObject& simpleObject) {
    this->id_    = simpleObject.id_;
    this->place_      = simpleObject.place_;
    this->name_  = simpleObject.name_;
    return *this;
}

bool SimpleObject::operator== ( const SimpleObject& simpleObject) const {
    return (this->id_      == simpleObject.id_);
}

void SimpleObject::setSize(int x, int y) {
    place_.resize(y);
    for ( int i = 0; i < y; ++i ) {
        place_[i].resize(x);
    }
}

std::vector<std::vector<Place*>> SimpleObject::getPlaces() const {
    return place_;
}

std::string const SimpleObject::getName() const {
    return name_;
}

std::pair<int,int> SimpleObject::getId() const {
    return id_;
}

void SimpleObject::setPlaces( std::vector<std::vector<Place*>> place) { }

void SimpleObject::setPlace( Place* place, Map& map) { }

void SimpleObject::setName( std::string name) {
    name_ = name;
}

void SimpleObject::setId( std::pair<int,int> id ) {
    id_ = id;
}

SimpleObject::~SimpleObject() {
    for ( int i = 0; i < place_.size(); ++i ) {
        for ( int j = 0; j < place_[i].size(); ++j ) {
            place_[i][j]->setObject(std::make_pair(std::make_pair(-1,-1),-1));
        }
    }
}
