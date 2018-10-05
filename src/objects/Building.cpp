#include "All-include.h"
#include "Building.h"
#include "AttackingObject.h"

Building::Building():AttackingObject(), DestroyingObject(),SimpleObject()  {
    id_ = std::make_pair(0,0);
    require_.clear();
    train_.clear();
    training_.clear();
}

Building::Building( const Building& building ) {
    this->id_ = building.getId();
    this->require_ = building.getRequire();
    this->train_ = building.getTrain();
    this->training_ = building.getTraining();
}

Building& Building::operator= ( const Building& building) {
    this->id_ = building.getId();
    this->require_ = building.getRequire();
    this->train_ = building.getTrain();
    this->training_ = building.getTraining();
    return *this;
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

std::pair<int,int> Building::getId() const {
    return id_;
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

void Building::setId( std::pair<int,int> id ) {
    id_ = id;
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
