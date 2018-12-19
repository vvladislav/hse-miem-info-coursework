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

std::ostream& operator << (std::ostream &s, Building& building) {
        if ( building.getPlaces() ) {
            fout << building.getPlaces()->getCoors()[0].first << ' '
                 << building.getPlaces()->getCoors()[0].second
                 << std::endl;
        }
        else {
            fout << -1
                 << -1
                 << std::endl;
        }
        fout << building.SimpleObject::getName()
             << std::endl;
        fout << building.AttackingObject::getDamage() << ' '
             << building.AttackingObject::getRange()
             << std::endl;
        fout << building.AttackingObject::getTarget->getCoors->first << ' '
             << building.AttackingObject::getTarget->getCoors->second
             << std::endl;
        fout << building.DestroyableObject::getHealth()
             << std::endl;
        fout << building.getId().first.first << ' '
             << building.getId().first.second << ' '
             << building.getId().second
             << std::endl;
        fout << building.getTrainables().size()
             << std::endl;
        for ( auto j : building.getTrainables() ) {
            fout << j->getId().second
                 << std::endl;
        }
        fout << building.getRequirements().size()
             << std::endl;
        for ( auto j : building.getRequirements() ) {
            fout << j->getId().second
                 << std::endl;
        }
    }
    return s;
}

std::istream& operator >> (std::istream &s, Building& building) {

    return s;
}
