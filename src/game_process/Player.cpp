#include "All-include.h"
#include "Player.h"

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
    this->choosedUnits_ = player.getChoosed();
    this->playersUnits_ = player.getUnits();
    this->playersBuildings_ = player.getBuildings();
    this->visiblePlaces_ = player.getVisiblePlaces();
}

Player::Player( int id ) {
    idPlayer_ = id;
    name_ = "";
    colorPlayer_ = 0;
    //resource_.resize();
    choosedUnits_.resize(0);
    playersUnits_.resize(0);
    playersBuildings_.resize(0);
    visiblePlaces_.resize(0);
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

std::vector<Unit> Player::getUnits() const {
    return playersUnits_;
}

std::vector<Building> Player::getBuildings() const {
    return playersBuildings_;
}

std::vector<Place*> Player::getVisiblePlaces() const {
    return visiblePlaces_;
}

const std::vector<Unit*> Player::getChoosed() const {
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

void Player::setUnits(std::vector<Unit> newUnits) {
    playersUnits_ = newUnits;
}

void Player::setChoosed(std::vector<Unit*> choosedUnits) {
    choosedUnits_ = choosedUnits;
}

//void setPlaces(std::vector<place> visiblePlaces);

void Player::setColor(int const idColor) {
    colorPlayer_ = idColor;
}

void Player::addUnit(Unit newUnit) {
    playersUnits_.push_back(newUnit);
}

void Player::removeUnit(Unit oldUnit) {
    playersUnits_.erase(playersUnits_.begin() + oldUnit.getId().second);
}

void Player::addBuilding( Building newBuilding) {
    newBuilding.setId( std::make_pair(idPlayer_ , playersUnits_.size()) );
    playersBuildings_.push_back(newBuilding);
}

void Player::removeBuilding(Building& oldBuilding) {
    playersBuildings_.erase(playersBuildings_.begin() + oldBuilding.getId().second);
}

void Player::removeBuilding( int oldBuilding) {
    playersBuildings_.erase(playersBuildings_.begin() + oldBuilding);
}

void Player::addIdChoosed(int chooseUnit) {
    choosedUnits_.push_back(&(getUnits()[chooseUnit]));
}

void Player::addIdChoosed(std::vector<Unit*> chooseUnit) {
    choosedUnits_.insert(std::end(choosedUnits_), std::begin(chooseUnit), std::end(chooseUnit));
    //choosedUnits_.add(choosedUnits_ , chooseUnit);
}

void Player::changePlaces(Unit travelUnit) {
    // create with time
}

void Player::changePlaces(std::vector<Unit*> travelUnits ) {
    // create with time
}

void Player::addResources(int idResource, int quality) {
    resource_[idResource] += quality;
}

void Player::spendResources(int idResource, int quality) {
    resource_[idResource] -= quality;
}
