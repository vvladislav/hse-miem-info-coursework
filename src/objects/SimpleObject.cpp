#include "All-include.h"
#include "SimpleObject.h"

SimpleObject::SimpleObject() {
    place_ = std::make_pair(0,0);
    name_ = "";
}

SimpleObject::SimpleObject(std::pair<int,int> place) {
    place_ = place;
    name_ = "";
}

SimpleObject& SimpleObject::operator= ( const SimpleObject& simpleObject) {
    this->place_ = simpleObject.getPlace();
    this->name_ = simpleObject.getName();
    return *this;
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
