#include "All-include.h"
#include "Player.h"

Player::Player() {
    idPlayer_ = 0;
    name_ = "No name";
    colorPlayer_ = 0;
    choosedUnits_.clear();
    playersUnits_.clear();
    playersBuildings_.clear();
    visiblePlaces_.clear();
}

Player::Player(const Player& player) {
    this->idPlayer_ = player.getId();
    this->name_ = player.getName();
    this->colorPlayer_ = player.getColor();
    this->resource_ = player.getResource();
    this->choosedUnits_ = player.getChoosed();
    this->playersUnits_ = player.getUnits();
    this->playersBuildings_ = player.getBuildings();
    this->visiblePlaces_ = player.getVisiblePlaces();
}

Player::Player( int id ) {
    idPlayer_ = id;
    name_ = "No name";
    colorPlayer_ = 0;
    choosedUnits_.clear();
    playersUnits_.clear();
    playersBuildings_.clear();
    visiblePlaces_.clear();
}

int const Player::getId() const {
    return idPlayer_;
}

std::string const Player::getName() const {
    return name_;
}

int const Player::getColor() const {
    return colorPlayer_;
}

std::list<Unit> Player::getUnits() const {
    return playersUnits_;
}

std::list<Building> Player::getBuildings() const {
    return playersBuildings_;
}

std::list<Place*> Player::getVisiblePlaces() const {
    return visiblePlaces_;
}

const std::list<Unit*> Player::getChoosed() const {
    return choosedUnits_;
}

std::vector<int> Player::getResource() const {
    return resource_;
}

//setPlaces();

void Player::setId(int const idPlayer) {
    idPlayer_ = idPlayer;
}

void Player::setName(const std::string name) {
    name_ = name;
}

void Player::setUnits(std::list<Unit> newUnits) {
    playersUnits_ = newUnits;
}

void Player::setChoosed(std::list<Unit*> choosedUnits) {
    choosedUnits_ = choosedUnits;
}

//void setPlaces(std::list<place> visiblePlaces);

void Player::setColor(int const idColor) {
    colorPlayer_ = idColor;
}

void Player::addUnit(Unit newUnit) {
    playersUnits_.push_back(newUnit);
}

void Player::removeUnit(Unit oldUnit) {
    auto it = playersUnits_.begin();
    std::advance( it, oldUnit.getId().second );
    playersUnits_.erase(it);
}

void Player::addBuilding( Building newBuilding) {
    newBuilding.setId( std::make_pair(idPlayer_ , playersUnits_.size()) );
    playersBuildings_.push_back(newBuilding);
}

void Player::removeBuilding(Building& oldBuilding) {
    auto it = playersBuildings_.begin();
    std::advance( it , oldBuilding.getId().second );
    playersBuildings_.erase(it);
}

void Player::addChoosed( Unit* chooseUnit) {
    choosedUnits_.push_back( chooseUnit );
}

void Player::changePlaces(Unit travelUnit) {
    // create with time
}

void Player::addResources(int idResource, int quality) {
    resource_[idResource] += quality;
}

void Player::spendResources(int idResource, int quality) {
    resource_[idResource] -= quality;
}
