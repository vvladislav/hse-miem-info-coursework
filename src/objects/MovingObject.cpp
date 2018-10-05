#include "All-include.h"
#include "MovingObject.h"

MovingObject::MovingObject():SimpleObject() {
    endPoint_ = SimpleObject::getPlace();
}

MovingObject::MovingObject(const MovingObject& movingObject) {
    this->speed_ = movingObject.getSpeed(); 
    this->endPoint_ = movingObject.SimpleObject::getPlace();
}

MovingObject& MovingObject::operator= ( const MovingObject& movingObject) {
    this->speed_ = movingObject.getSpeed(); 
    this->endPoint_ = movingObject.SimpleObject::getPlace();
    return *this;
}

int const MovingObject::getSpeed() const {
    return speed_;
}

void MovingObject::setSpeed( int speed ) {
    speed_ = speed;
}

void MovingObject::addSpeed( int add ) {
    speed_ += add;
}

void MovingObject::rmSpeed( int rm ) {
    speed_ += rm;
}

void MovingObject::move( int x , int y ) {
    endPoint_ = std::make_pair(x,y);
}

void MovingObject::move( std::pair<int,int> endPoint ) {
    endPoint_ = endPoint;
}

bool MovingObject::isMove() {
    if ( endPoint_ != place_ ) return true;
    return false;
}
