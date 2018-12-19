#include "All-include.h"
#include "SimpleObject.h"

SimpleObject::SimpleObject() {
    id_         = std::make_pair(-1,-1);
    place_      = nullptr;
    name_       = "No name";
}

SimpleObject::SimpleObject(Place*** place, int placeWidth, int placeHight) {
    id_    = std::make_pair(-1,-1);
    placeWidth_ = placeWidth_;
    placeHight_ = placeHight_;
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
    this->id_         = simpleObject.id_;
    this->placeHight_ = simpleObject.placeHight_;
    this->placeWidth_ = simpleObject.placeWidth_;
    this->place_      = new Place**[placeHight_];
    for ( int i = 0; i < placeHight_; ++i ) {
        this->place_[i] = new Place*[placeWidth_];
        for ( int j = 0; j < placeWidth_; ++j ) {
            this->place_[i][j]   = simpleObject.place_[i][j];
        }
    }
    this->name_  = simpleObject.name_;
}

SimpleObject& SimpleObject::operator= ( const SimpleObject& simpleObject) {
    this->id_    = simpleObject.id_;
    this->placeHight_ = simpleObject.placeHight_;
    this->placeWidth_ = simpleObject.placeWidth_;
    this->place_      = new Place**[placeHight_];
    for ( int i = 0; i < placeHight_; ++i ) {
        this->place_[i] = new Place*[placeWidth_];
        for ( int j = 0; j < placeWidth_; ++j ) {
            this->place_[i][j]   = simpleObject.place_[i][j];
        }
    }
    this->name_  = simpleObject.name_;
    return *this;
}

bool SimpleObject::operator== ( const SimpleObject& simpleObject) const {
    return (this->id_      == simpleObject.id_);
}

void setSize(int x, int y) {
    place_.resize(y);
    for ( int i = 0; i < y; ++i ) {
        place_.resize(x);
    }
}

std::vector<std::vector<Place*>> getPlaces() const {
    return place_;
}

std::string const SimpleObject::getName() const {
    return name_;
}

std::pair<int,int> SimpleObject::getId() const {
    return id_;
}

void SimpleObject::setPlaces( std::vector<std::vector<Place*>> place) {
    place_ = place;
    for ( int i = 0; i < place_.size(); ++i ) {
        for ( int j = 0; j < place[i]_.size(); ++j ) {
            place_[i][j]->setObject(this);
        }
    }
}

void SimpleObject::setPlace( Place* place, Map& map) {
    int k1 = place.getCoors().first;
    int k2 = place.getCoors().second;
    for ( int i = 0; i < place_.size(); ++i ) {
        for ( int j = 0; j < place[i]_.size(); ++j ) {
            map[k1+i][k2+j]->setObject(this);
            place_[i][j] = map[k1+i][k2+j];
        }
    }
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
    }
}
