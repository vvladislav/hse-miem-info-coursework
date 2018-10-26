#include "All-include.h"
#include "Building.h"
#include "AttackingObject.h"

Building::Building():AttackingObject(), DestroyingObject(), SimpleObject() {
    require_.clear();
    train_.clear();
    training_.clear();
}

Building::Building( const Building& building ): AttackingObject(building), DestroyingObject(building), SimpleObject(building) {
    this->require_ = building.getRequire();
    this->train_ = building.getTrain();
    this->training_ = building.getTraining();
}

Building& Building::operator= ( const Building& building) {
    DestroyingObject::operator= (building);
    SimpleObject::operator= (building);
    this->require_ = building.getRequire();
    this->train_ = building.getTrain();
    this->training_ = building.getTraining();
    return *this;
}

bool Building::operator== ( const Building& building) const {
    if ((this->train_   == building.getTrain()) &&
        (this->training_== building.getTraining()) &&
        (this->require_ == building.getRequire()) &&
        (static_cast< AttackingObject & >(const_cast< Building & >(*this)) ==
             static_cast< AttackingObject & >(const_cast< Building & >(building))) &&
        (static_cast< DestroyingObject & >(const_cast< Building & >(*this)) ==
             static_cast< DestroyingObject & >(const_cast< Building & >(building))))
        return true;
    return false;
}

std::list< Unit* > const Building::getTrain() const {
    return train_;
}

std::list< Unit* > const Building::getTraining() const {
    return training_;
}

std::list < Building* > const Building::getRequire() const {
    return require_;
}

void Building::setTrain(std::list< Unit* > train) {
    train_ = train;
}

void Building::setTraining(std::list< Unit* > training) {
    training_ = training;
}

void Building::setRequire(std::list< Building* > require) {
    require_ = require;
}

void Building::addTrain(Unit* add) {
    train_.push_back( add );
}

void Building::rmTrain( int idRm) {
    auto it = train_.begin();
    std::advance( it , idRm);
    train_.erase(it);
}

void Building::addTraining(Unit* add ) {
    training_.push_back( add );
}

void Building::rmTraining( int idRm ) {
    auto it = training_.begin();
    std::advance( it , idRm);
    training_.erase(it);
}

void Building::addRequire( Building* add) {
    require_.push_back( add );
}

void Building::rmRequire( int idRm) {
    auto it = require_.begin();
    std::advance( it , idRm);
    require_.erase(it);
}

bool Building::hasRequire() {
    return require_.size();
}
