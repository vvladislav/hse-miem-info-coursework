#include "All-include.h"
#include "SimpleObject.h"

SimpleObject::SimpleObject() {
    id_ = std::make_pair(-1,-1);
    place_ = nullptr;
    name_ = "No name";
}

SimpleObject::SimpleObject(Place* place) {
    place_ = place;
    name_ = "No name";
}

SimpleObject::SimpleObject(const SimpleObject& simpleObject) {
    this->id_ = simpleObject.getId();
    this->place_ = simpleObject.getPlace();
    this->name_ = simpleObject.getName();
}

SimpleObject& SimpleObject::operator= ( const SimpleObject& simpleObject) {
    this->id_ = simpleObject.getId();
    this->place_ = simpleObject.getPlace();
    this->name_ = simpleObject.getName();
    return *this;
}

bool SimpleObject::operator== ( const SimpleObject& simpleObject) const {
    if ((this->id_      == simpleObject.getId()) &&
        (this->place_      == simpleObject.getPlace()) &&
        (this->name_   == simpleObject.getName()))
        return true;
    return false;
}

Place* const SimpleObject::getPlace() const {
    return place_;
}

std::string const SimpleObject::getName() const {
    return name_;
}

std::pair<int,int> SimpleObject::getId() const {
    return id_;
}

void SimpleObject::setPlace( Place* place) {
    place_ = place;
}

void SimpleObject::setName( std::string name) {
    name_ = name;
}

void SimpleObject::setId( std::pair<int,int> id ) {
    id_ = id;
}

SimpleObject::~SimpleObject() {
    place_->setObject(nullptr);
}
