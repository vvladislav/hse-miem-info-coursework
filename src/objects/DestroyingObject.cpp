#include "All-include.h"
#include "DestroyingObject.h"

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
}

bool DestroyingObject::isAlive() {
    return ( health_ > 0 );
}
