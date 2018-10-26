#include "All-include.h"
#include "SimpleObject.h"

SimpleObject::SimpleObject() {
    place_ = std::make_pair(0,0);
    name_ = "No name";
}

SimpleObject::SimpleObject(std::pair<int,int> place) {
    place_ = place;
    name_ = "No name";
}

SimpleObject::SimpleObject(const SimpleObject& simpleObject) {
    this->place_ = simpleObject.getPlace();
    this->name_ = simpleObject.getName();
}

SimpleObject& SimpleObject::operator= ( const SimpleObject& simpleObject) {
    this->place_ = simpleObject.getPlace();
    this->name_ = simpleObject.getName();
    return *this;
}

bool SimpleObject::operator== ( const SimpleObject& simpleObject) const {
    if ((this->place_      == simpleObject.getPlace()) &&
        (this->name_   == simpleObject.getName()))
        return true;
    return false;
}

std::pair<int,int> const SimpleObject::getPlace() const {
    return place_;
}

std::string const SimpleObject::getName() const {
    return name_;
}

void SimpleObject::setPlace( std::pair<int,int> place) {
    place_ = place;
}

void SimpleObject::setName( std::string name) {
    name_ = name;
}
