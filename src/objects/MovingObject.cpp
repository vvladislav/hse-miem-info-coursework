#include "All-include.h"
#include "MovingObject.h"

MovingObject::MovingObject():SimpleObject() {
    destination_ = SimpleObject::getPlaces()[0][0]->getCoors();
}

MovingObject::MovingObject(const MovingObject& movingObject):SimpleObject(movingObject) {
    this->speed_ = movingObject.getSpeed(); 
    this->destination_ = movingObject.SimpleObject::getPlaces()[0][0]->getCoors();
}

MovingObject& MovingObject::operator= ( const MovingObject& movingObject) {
    SimpleObject::operator= (movingObject);
    this->speed_ = movingObject.getSpeed(); 
    this->destination_ = movingObject.SimpleObject::getPlaces()[0][0]->getCoors();
    return *this;
}

bool MovingObject::operator== ( const MovingObject& movingObject) const {
    return (this->id_  == movingObject.id_);
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
    return ( destination_ != place_[0][0]->getCoors() );
}

void MovingObject::calculatePath() {
    // temporary
    auto destination = destination_;
    while ( destination != place_[0][0]->getCoors() ) {
        if (destination.first > place_[0][0]->getCoors().first) {
            --destination.first;
        }
        else if (destination.first < place_[0][0]->getCoors().first) {
            ++destination.first;
        }
        else if (destination.second > place_[0][0]->getCoors().second) {
            --destination.second;

        }
        else if (destination.second < place_[0][0]->getCoors().second) {
            ++destination.second;
        }
        path_.push_back(destination);
    }
}
