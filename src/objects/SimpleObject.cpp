#include "All-include.h"
#include "SimpleObject.h"

SimpleObject::SimpleObject() {
    id_         = std::make_pair(-1,-1);
    place_      = nullptr;
    placeWidth_ = 0;
    placeHight_ = 0;
    name_       = "No name";
}

SimpleObject::SimpleObject(Place*** place, int placeWidth, int placeHight) {
    id_    = std::make_pair(-1,-1);
    placeWidth_ = placeWidth;
    placeHight_ = placeHight;
    place_      = new Place**[placeHight_];
    for ( int i = 0; i < placeHight_; ++i ) {
        place_[i] = new Place*[placeWidth_];
        for ( int j = 0; j < placeWidth_; ++j ) {
            place_[i][j] = place[i][j];
        }
    }
    place_ = place;
    name_  = "No name";
}

SimpleObject::SimpleObject(const SimpleObject& simpleObject) {
    this->id_         = simpleObject.getId();
    this->placeHight_ = simpleObject.placeHight_;
    this->placeWidth_ = simpleObject.placeWidth_;
    this->place_      = new Place**[placeHight_];
    for ( int i = 0; i < placeHight_; ++i ) {
        this->place_[i] = new Place*[placeWidth_];
        for ( int j = 0; j < placeWidth_; ++j ) {
            this->place_[i][j]   = simpleObject.place_[i][j];
        }
    }
    this->name_  = simpleObject.getName();
}

SimpleObject& SimpleObject::operator= ( const SimpleObject& simpleObject) {
    this->id_    = simpleObject.getId();
    this->placeHight_ = simpleObject.placeHight_;
    this->placeWidth_ = simpleObject.placeWidth_;
    this->place_      = new Place**[placeHight_];
    for ( int i = 0; i < placeHight_; ++i ) {
        this->place_[i] = new Place*[placeWidth_];
        for ( int j = 0; j < placeWidth_; ++j ) {
            this->place_[i][j]   = simpleObject.place_[i][j];
        }
    }
    this->name_  = simpleObject.getName();
    return *this;
}

bool SimpleObject::operator== ( const SimpleObject& simpleObject) const {
    return (this->id_      == simpleObject.getId());
}

Place*** SimpleObject::getPlaces() const {
    return place_;
}

std::string const SimpleObject::getName() const {
    return name_;
}

std::pair<int,int> SimpleObject::getId() const {
    return id_;
}

void SimpleObject::setPlaces( Place*** place) {
    for ( int i = 0; i < placeHight_; ++i ) {
        for ( int j = 0; j < placeWidth_; ++j ) {
            place_[i][j]->setObject(this);
        }
    }
    place_ = place;
}

void SimpleObject::setName( std::string name) {
    name_ = name;
}

void SimpleObject::setId( std::pair<int,int> id ) {
    id_ = id;
}

SimpleObject::~SimpleObject() {
    for ( int i = 0; i < placeHight_; ++i ) {
        for ( int j = 0; j < placeWidth_; ++j ) {
            place_[i][j]->setObject(nullptr);
        }
        delete place_[i];
    }
    delete place_;
}
