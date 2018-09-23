#include "All-include.h"
#include "Place.h"

Player::Player() {
    idPlayer_ = 0;
    name_ = "";
    colorPlayer_ = 0;
    //resource_.resize();
    choosedUnits_.resize(0);
    playersUnits_.resize(0);
    playersBuildings_.resize(0);
    visiblePlaces_.resize(0);
}

Player::Player(const Player& player) {
    this->idPlayer_ = player.getId();
    this->name_ = player.getName();
    this->colorPlayer_ = player.getColor();
    this->resource_ = player.getResource();
    this->choosedUnits_ = player.getChoosedUnits();
    this->playersUnits_ = player.getUnits();
    this->playersBuildings_ = player.getBuildings();
    this->visiblePlaces_ = player.getVisibleUnits();
}

Place::Place( int id ) {
    idPlayer_ = id;
    name_ = "";
    colorPlayer_ = 0;
    //resource_.resize();
    choosedUnits_.resize(0);
    playersUnits_.resize(0);
    playersBuildings_.resize(0);
    visiblePlaces_.resize(0);
}

int const getId() const {
    return idPlayer_;
}

std::string const getName() const {
    return name_;
}

int const getColor() const {
    return colorPlayer_;
}

std::vector<Units> getUnits() const {
    return playersUnits_;
}

std::vector<Building> getBuildings() const {
    return playersBuilding_;
}

std::vector<Place> getVisiblePlaces() const {
    return visibleplaces_;
}

std::vector<int> getChoosedUnits() const {
    return choosedUnits_;
}

std::vector<int> getResource() const {
    return resource_;
}

//setPlaces();

void setId(int const idPlayer) {
    idPlayer_ = idPlayer;
}

void setName(const std::string name) {
    name_ = name;
}

void setUnits(std::vector<units> newUnits) {
    playersUnits_ = newUnits;_
}

void setChoosedUnits(std::vector<int> choosedUnits) {
    choosedUnits_ = choosedUnits;
}

//void setPlaces(std::vector<place> visiblePlaces);

void setColor(int const idColor) {
    colorPlayer_ = idColor;
}

void addUnit(units newUnit) {
    playersUnits_.push_back(newUnit);
}

void removeUnit(units oldUnit) {
    playersUnits_.erase(vec.begin() + oldUnit.getId());
}

void addBuilding(units newBuilding) {
    playersUnits_.push_back(newBuilding);
}

void removeBuilding(Unit oldBuilding) {
    playersBuildings_.erase(vec.begin() + oldBuilding.getId());
}

void addIdChoosedUnits(int chooseUnit) {
    choosedUnits_.push_back(chooseUnit);
}

void addChoosedUnits(std::vector<int> chooseUnits) {
    choosedUnits_.add(choosedUnits_,chooseUnits);
}

void changePlaces(Unit travelUnit) {
    // create with time
}

void changePlaces(std::vector<units> travelUnits ) {
    // create with time
}

void addResources(int idResource, int quality) {
    resource_[idResource] += quality;
}

void spendResources(int idResource, int quality) {
    resource_[idResource] -= quality;
}


}
