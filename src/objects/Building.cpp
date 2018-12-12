#include "All-include.h"
#include "Building.h"
#include "AttackingObject.h"

Building::Building():AttackingObject(), DestroyableObject(), SimpleObject() {
    requirements_.clear();
    trainables_.clear();
    training_.clear();
}

Building::Building( const Building& building ): AttackingObject(building), DestroyableObject(building), SimpleObject(building) {
    this->requirements_ = building.getRequirements();
    this->trainables_ = building.getTrainables();
    this->training_ = building.getTraining();
}

Building& Building::operator= ( const Building& building) {
    DestroyableObject::operator= (building);
    SimpleObject::operator= (building);
    this->requirements_ = building.getRequirements();
    this->trainables_ = building.getTrainables();
    this->training_ = building.getTraining();
    return *this;
}

bool Building::operator== ( const Building& building) const {
    return (this->id_ == building.id_);
}

std::list< Unit* > const Building::getTrainables() const {
    return trainables_;
}

std::list< Unit* > const Building::getTraining() const {
    return training_;
}

std::list < Building* > const Building::getRequirements() const {
    return requirements_;
}

void Building::setTrainables(std::list< Unit* > trainables) {
    trainables_ = trainables;
}

void Building::setTraining(std::list< Unit* > training) {
    training_ = training;
}

void Building::setRequirements(std::list< Building* > requirements) {
    requirements_ = requirements;
}

void Building::addTrainables(Unit* add) {
    trainables_.push_back( add );
}

void Building::rmTrainables( int idRm) {
    auto it = trainables_.begin();
    std::advance( it , idRm);
    trainables_.erase(it);
}

void Building::addTraining(Unit* add ) {
    training_.push_back( add );
}

void Building::rmTraining( int idRm ) {
    auto it = training_.begin();
    std::advance( it , idRm);
    training_.erase(it);
}

void Building::addRequirements( Building* add) {
    requirements_.push_back( add );
}

void Building::rmRequirements( int idRm) {
    auto it = requirements_.begin();
    std::advance( it , idRm);
    requirements_.erase(it);
}

bool Building::hasRequirements() {
    return requirements_.size();
}
