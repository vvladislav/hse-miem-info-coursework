#include "All-include.h"
#include "MovingObject.h"

MovingObject::MovingObject():SimpleObject() {
    destination_ = SimpleObject::getPlace()->getCoors();
}

MovingObject::MovingObject(const MovingObject& movingObject):SimpleObject(movingObject) {
    this->speed_ = movingObject.getSpeed(); 
    this->destination_ = movingObject.SimpleObject::getPlace()->getCoors();
}

MovingObject& MovingObject::operator= ( const MovingObject& movingObject) {
    SimpleObject::operator= (movingObject);
    this->speed_ = movingObject.getSpeed(); 
    this->destination_ = movingObject.SimpleObject::getPlace()->getCoors();
    return *this;
}

bool MovingObject::operator== ( const MovingObject& movingObject) const {
    if ((this->speed_      == movingObject.getSpeed()) &&
        (this->destination_   == movingObject.getDestination()) &&
        (static_cast< SimpleObject & >(const_cast< MovingObject & >(*this)) ==
             static_cast< SimpleObject & >(const_cast< MovingObject & >(movingObject))))
        return true;
    return false;
}

int const MovingObject::getSpeed() const {
    return speed_;
}

const std::pair<int,int> MovingObject::getDestination() const {
    return destination_;
}

void MovingObject::setSpeed( int speed ) {
    speed_ = speed;
}

void MovingObject::setDestination( int x , int y ) {
    destination_ = std::make_pair(x,y);
}

void MovingObject::setDestination( std::pair<int,int> destination ) {
    destination_ = destination;
}

void MovingObject::addSpeed( int add ) {
    speed_ += add;
}

void MovingObject::rmSpeed( int rm ) {
    speed_ += rm;
}

bool MovingObject::isMove() {
    return ( destination_ != place_->getCoors() );
}
