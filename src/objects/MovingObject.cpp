#include "All-include.h"
#include "MovingObject.h"

MovingObject::MovingObject():SimpleObject() {
    endPoint_ = SimpleObject::getPlace()->getCoors();
}

MovingObject::MovingObject(const MovingObject& movingObject) {
    this->speed_ = movingObject.getSpeed(); 
    this->endPoint_ = movingObject.SimpleObject::getPlace()->getCoors();
}

MovingObject& MovingObject::operator= ( const MovingObject& movingObject) {
    this->speed_ = movingObject.getSpeed(); 
    this->endPoint_ = movingObject.SimpleObject::getPlace()->getCoors();
    return *this;
}

bool MovingObject::operator== ( const MovingObject& movingObject) const {
    if ((this->speed_      == movingObject.getSpeed()) &&
        (this->endPoint_   == movingObject.getEndPoint()) &&
        (static_cast< SimpleObject & >(const_cast< MovingObject & >(*this)) ==
             static_cast< SimpleObject & >(const_cast< MovingObject & >(movingObject))))
        return true;
    return false;
}

int const MovingObject::getSpeed() const {
    return speed_;
}

const std::pair<int,int> MovingObject::getEndPoint() const {
    return endPoint_;
}

void MovingObject::setSpeed( int speed ) {
    speed_ = speed;
}

void MovingObject::setEndPoint( int x , int y ) {
    endPoint_ = std::make_pair(x,y);
}

void MovingObject::setEndPoint( std::pair<int,int> endPoint ) {
    endPoint_ = endPoint;
}

void MovingObject::addSpeed( int add ) {
    speed_ += add;
}

void MovingObject::rmSpeed( int rm ) {
    speed_ += rm;
}

bool MovingObject::isMove() {
    return ( endPoint_ != place_->getCoors() );
}
