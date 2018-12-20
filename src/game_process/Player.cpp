#include "All-include.h"
#include "Player.h"
#include "Place.h"

Player::Player() {
    id_ = 0;
    name_ = "No name";
    color_ = 0;
    choosedUnits_.clear();
    playersUnits_.clear();
    choosedBuildings_.clear();
    playersBuildings_.clear();
    visiblePlaces_.clear();
}

Player::Player(const Player& player) {
    this->id_ = player.id_;
    this->name_ = player.name_;
    this->color_ = player.color_;
    this->resources_ = player.resources_;
    this->choosedUnits_ = player.choosedUnits_;
    this->playersUnits_ = player.playersUnits_;
    this->choosedBuildings_ = player.choosedBuildings_;
    this->playersBuildings_ = player.playersBuildings_;
    this->visiblePlaces_ = player.visiblePlaces_;
}

Player::Player( int id ) {
    id_ = id;
    name_ = "No name";
    color_ = 0;
    choosedUnits_.clear();
    playersUnits_.clear();
    choosedBuildings_.clear();
    playersBuildings_.clear();
    visiblePlaces_.clear();
}

bool Player::operator== (const Player& player) const {
    if ((this->id_               == player.id_) &&
        (this->name_             == player.name_) &&
        (this->color_            == player.color_) &&
        (this->resources_        == player.resources_) &&
        (this->playersUnits_     == player.playersUnits_) &&
        (this->choosedUnits_     == player.choosedUnits_) &&
        (this->choosedBuildings_ == player.choosedBuildings_) &&
        (this->visiblePlaces_    == player.visiblePlaces_) &&
        (this->inGame_           == player.inGame_) )
        return true;
    return false;
}

int const Player::getId() const {
    return id_;
}

std::string const Player::getName() const {
    return name_;
}

int const Player::getColor() const {
    return color_;
}

std::list<Unit>& Player::getUnits() {
    return playersUnits_;
}

Unit* Player::getUnit( int id ) {
    auto it = playersUnits_.begin();
    for ( ; id > 0; --id) {
        ++it;
    }
    return &(*it);
}

std::list<Building>& Player::getBuildings() {
    return playersBuildings_;
}

std::list<Place*> Player::getVisiblePlaces() const {
    return visiblePlaces_;
}

const std::list<Unit*> Player::getChoosedUnits() const {
    return choosedUnits_;
}

const std::list<Building*> Player::getChoosedBuildings() const {
    return choosedBuildings_;
}

std::vector<std::pair<int,std::string> > Player::getResources() const {
    return resources_;
}

bool Player::getStatus() const {
    return inGame_;
}

//setPlaces();

void Player::setId(int const id) {
    id_ = id;
}

void Player::setName(const std::string name) {
    name_ = name;
}

void Player::setUnits(std::list<Unit> newUnits) {
    playersUnits_ = newUnits;
}

void Player::setChoosedUnits(std::list<Unit*> choosedUnits) {
    choosedUnits_ = choosedUnits;
}

void Player::setChoosedBuildings(std::list<Building*> choosedBuildings) {
    choosedBuildings_ = choosedBuildings;
}

//void setPlaces(std::list<place> visiblePlaces);

void Player::setColor(int const idColor) {
    color_ = idColor;
}

void Player::setResources(std::vector<std::pair<int,std::string> > resources) {
    resources_ = resources;
}

void Player::setStatus( bool inGame ) {
    inGame_ = inGame;
}

void Player::add(Unit newUnit) {
    playersUnits_.push_back(newUnit);
}

void Player::remove(Unit oldUnit) {
    auto it = playersUnits_.begin();
    std::advance( it, oldUnit.getId().second );
    playersUnits_.erase(it);
}

void Player::add( Building newBuilding) {
    newBuilding.setId( std::make_pair(id_ , playersUnits_.size()) );
    playersBuildings_.push_back(newBuilding);
}

void Player::remove(Building& oldBuilding) {
    auto it = playersBuildings_.begin();
    std::advance( it , oldBuilding.getId().second );
    playersBuildings_.erase(it);
}

void Player::addChoosedUnit( Unit* chooseUnit) {
    choosedUnits_.push_back( chooseUnit );
}

void Player::addChoosedBuilding( Building* chooseBuilding) {
    choosedBuildings_.push_back( chooseBuilding );
}

void Player::changePlaces(Unit travelUnit) {
    // create with time
}

void Player::addResources(int idResources, int quality) {
    resources_[idResources].second += quality;
}

void Player::spendResources(int idResources, int quality) {
    resources_[idResources].first -= quality;
}
