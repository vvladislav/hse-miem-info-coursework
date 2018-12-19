#include "All-include.h"
#include "DestroyableObject.h"

DestroyableObject::DestroyableObject():SimpleObject() {
    health_ = 1;
}

DestroyableObject::DestroyableObject(const DestroyableObject& destroyableObject): SimpleObject(destroyableObject) {
    this->health_ = destroyableObject.getHealth(); 
}

DestroyableObject& DestroyableObject::operator= ( const DestroyableObject& destroyableObject) {
    SimpleObject::operator= (destroyableObject);
    this->health_ = destroyableObject.health_; 
    return *this;
}

bool DestroyableObject::operator== ( const DestroyableObject& destroyableObject) const {
    return (this->id_      == destroyableObject.id_);
}

DestroyableObject& DestroyableObject::operator- ( int rm ) {
    health_ -= rm;
    return *this;
}

DestroyableObject& DestroyableObject::operator+ ( int add ) {
    health_ += add;
    return *this;
}

int const DestroyableObject::getHealth() const {
    return health_;
}

void DestroyableObject::setHealth( int health ) {
    health_ = health;
}

void DestroyableObject::addHealth( int add ) {
    health_  += add;
}

void DestroyableObject::rmHealth( int rm ) {
    health_ -= rm;
}

DestroyableObject::~DestroyableObject() {
    // death animation
    this->~SimpleObject();
}
