#include "All-include.h"
#include "Building.h"

Building& Building::operator= ( const Building& building) {
    this->id_ = building.getId();
    this->require_ = building.getRequire();
    this->place_ = building.getPlace();
    this->train_ = building.getTrain();
    this->training_ = building.getTraining();
    return *this;
}

std::vector< Unit* > const Building::getTrain() const {
    return train_;
}

std::vector< Unit* > const Building::getTraining() const {
    return training_;
}

std::vector < Building* > const Building::getRequire() const {
    return require_;
}

std::pair<int,int> Building::getId() const {
    return id_;
}

void Building::setTrain(std::vector< Unit* > train) {
    train_ = train;
}

void Building::setTraining(std::vector< Unit* > training) {
    training_ = training;
}

void Building::setRequire(std::vector< Building* > require) {
    require_ = require;
}

void Building::setId( std::pair<int,int> id ) {
    id_ = id;
}

void Building::addTrain(Unit* add) {
    train_.push_back( add );
}

void Building::rmTrain( int idRm) {
    train_.erase(train_.begin() + idRm);
}

void Building::addTraining(Unit* add ) {
    training_.push_back( add );
}

void Building::rmTraining( int idRm ) {
    training_.erase(training_.begin() + idRm);
}

void Building::addRequire( Building* add) {
    require_.push_back( add );
}

void Building::rmRequire( int idRm) {
    require_.erase(require_.begin() + idRm);
}

bool Building::hasRequire() {
    return require_.size();
}
