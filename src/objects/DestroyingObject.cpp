#include "All-include.h"
#include "DestroyingObject.h"

DestroyingObject::DestroyingObject():SimpleObject() {
    health_ = 1;
}

DestroyingObject::DestroyingObject(const DestroyingObject& destroyingObject) {
    this->health_ = destroyingObject.getHealth(); 
}

DestroyingObject& DestroyingObject::operator= ( const DestroyingObject& destroyingObject) {
    this->health_ = destroyingObject.getHealth(); 
    return *this;
}

bool DestroyingObject::operator== ( const DestroyingObject& destroyingObject) const {
    if ((this->health_      == destroyingObject.getHealth()) &&
        (static_cast< SimpleObject & >(const_cast< DestroyingObject & >(*this)) ==
             static_cast< SimpleObject & >(const_cast< DestroyingObject & >(destroyingObject))))
        return true;
    return false;
}

DestroyingObject& DestroyingObject::operator- ( int rm ) {
    health_ -= rm;
    return *this;
}

DestroyingObject& DestroyingObject::operator+ ( int add ) {
    health_ += add;
    return *this;
}

int const DestroyingObject::getHealth() const {
    return health_;
}

void DestroyingObject::setHealth( int health ) {
    health_ = health;
}

void DestroyingObject::addHealth( int add ) {
    health_  += add;
}

void DestroyingObject::rmHealth( int rm ) {
    health_ -= rm;
    if ( health_ <= 0 )
        this->~DestroyingObject();
}

DestroyingObject::~DestroyingObject() {
    // death animation
    this->~SimpleObject();
}
