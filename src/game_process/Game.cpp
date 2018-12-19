#include "All-include.h"
#include "Player.h"
#include "Unit.h"
#include "Building.h"
#include "Game.h"

Game::Game() {
    players_.resize(2);
}
        
Game::Game( int countOfPlayers ) {
    players_.resize(countOfPlayers);
}

Game::Game( std::vector<Player> players ) {
    players_ = players;
}

std::vector<Player> Game::getPlayers() {
    return players_;
}
 
std::vector<Unit> Game::getUnitPrototype() {
    return unitPrototype_;
}

std::vector<Building> Game::getBuildingPrototype() {
    return buildingPrototype_;
}

std::vector<std::string> Game::getResourcePrototype() {
    return resourcePrototype_;
}

bool Game::getActive() {
    return isActive_;
}

void Game::setPlayers(std::vector<Player> players ) {
    players_ = players;
}

void Game::setUnitPrototype(std::vector<Unit> unitPrototype ) {
    unitPrototype_ = unitPrototype;
}

void Game::setBuildingPrototype(std::vector <Building> buildingPrototype ) {
    buildingPrototype_ = buildingPrototype;
}

void Game::setResourcePrototype(std::vector <std::string> resourcePrototype ) {
    resourcePrototype_ = resourcePrototype;
}

void Game::setActive( bool activities ) {
    isActive_ = activities;
}

void Game::addPlayers( Player add ) {
    int i = 0;
    for ( ; (i < players_.size()) && (players_[i] == add); ++i );
    if ( i == players_.size() )
        players_.push_back(add);
}

void Game::addUnitPrototype( Unit add ) {
    int i = 0;
    for ( ; (i < unitPrototype_.size()) && (unitPrototype_[i] == add); ++i );
    if ( i == unitPrototype_.size() )
        unitPrototype_.push_back(add);
}

void Game::addBuildingPrototype( Building add ) {
    int i = 0;
    for ( ; (i < buildingPrototype_.size()) && (buildingPrototype_[i] == add); ++i );
    if ( i == buildingPrototype_.size() )
        buildingPrototype_.push_back(add);
}

void Game::addResourcePrototype( std::string add ) {
    int i = 0;
    for ( ; (i < resourcePrototype_.size()) && (resourcePrototype_[i] == add); ++i );
    if ( i == resourcePrototype_.size() )
        resourcePrototype_.push_back(add);
}

void Game::rmPlayers( Player rm ) {
    int i = 0;
    for ( ; (i < players_.size()) && (players_[i] == rm); ++i );
    if ( i != players_.size() )
        players_.erase(players_.begin() + i);
}
 
void Game::rmUnitPrototype( Unit rm ) {
    int i = 0;
    for ( ; (i < unitPrototype_.size()) && (unitPrototype_[i] == rm); ++i );
    if ( i != unitPrototype_.size() )
        unitPrototype_.erase(unitPrototype_.begin() + i);
}

void Game::rmBuildingPrototype( Building rm ) {
    int i = 0;
    for ( ; (i < buildingPrototype_.size()) && (buildingPrototype_[i] == rm); ++i );
    if ( i != buildingPrototype_.size() )
        buildingPrototype_.erase(buildingPrototype_.begin() + i);
}

void Game::rmResourcePrototype( std::string rm ) {
    int i = 0;
    for ( ; (i < resourcePrototype_.size()) && (resourcePrototype_[i] == rm); ++i );
    if ( i != resourcePrototype_.size() )
        resourcePrototype_.erase(resourcePrototype_.begin() + i);
}

void Game::makeTurn() {
    for ( auto i : players_ ) {
        if ( i.getStatus() ) {
            std::list<Unit> & units = i.getUnits();
            for ( auto i : units ) {
                if ( i.isMove() ) {
                    i.setPlace(i.path_.front(),map_);
                    i.path_.pop_front();
                }
                if ( i.getTarget() != nullptr ) {
                    if ( i.getTarget()->getObject().second == unitType ) {
                        auto target = 
                            players_[i.getTarget()
                            ->getObject().first.first].getUnits()
                            .begin();
                        int k = i.getTarget()->getObject().first.second;
                        for ( ; k > 0; --k ) {
                        target++;
                        }
                        *target - i.getDamage();
                        if ( (*target).getHealth() <= 0 ) {
                            players_[(*target).getId().first]
                                .remove((*target));
                        }
                    } else
                    if ( i.getTarget()->getObject().second == buildingType ) {
                        auto target = 
                            players_[i.getTarget()
                            ->getObject().first.first].getBuildings()
                            .begin();
                        int k = i.getTarget()->getObject().first.second;
                        for ( ; k > 0; --k ) {
                        target++;
                        }
                        (*target) - i.getDamage();
                        if ( (*target).getHealth() <= 0 ) {
                            players_[(*target).getId().first]
                                .remove((*target));
                        }
                    }
                }
            }
            std::list<Building> & buildings = i.getBuildings();
            for ( auto i : buildings ) {
                if ( i.getTarget() != nullptr ) {
                    if ( i.getTarget()->getObject().second == unitType ) {
                        auto target = 
                            players_[i.getTarget()
                            ->getObject().first.first].getUnits()
                            .begin();
                        int k = i.getTarget()->getObject().first.second;
                        for ( ; k > 0; --k ) {
                        target++;
                        }
                        *target - i.getDamage();
                        if ( (*target).getHealth() <= 0 ) {
                            players_[(*target).getId().first]
                                .remove((*target));
                        }
                    } else
                    if ( i.getTarget()->getObject().second == buildingType ) {
                        auto target = 
                            players_[i.getTarget()
                            ->getObject().first.first].getBuildings()
                            .begin();
                        int k = i.getTarget()->getObject().first.second;
                        for ( ; k > 0; --k ) {
                        target++;
                        }
                        (*target) - i.getDamage();
                        if ( (*target).getHealth() <= 0 ) {
                            players_[(*target).getId().first]
                                .remove((*target));
                        }
                    }
                }
            }
        }
    }
}

bool Game::readObjects() {
    std::string path = givePath();
    path += "../common/datebase/Units.txt";
    std::ofstream fin; 
    fin.open(path, std::ios_base::in);
    if (!(fin.is_open()))
        return false;
    int number;
//    fin >> number;
    for ( int i = 0; i < number; ++i ) { 
        Unit unit;
//        fin >> unit;
        addUnitPrototype(unit);
    }
    fin.close();
    path = givePath();
    path += "../common/datebase/Buildings.txt";
    std::ofstream fin1; 
    fin1.open(path, std::ios_base::in);
    if (!(fin1.is_open()))
        return false;
//    fin1 >> number;
    for ( int i = 0; i < number; ++i ) { 
        Building building;
//        fin1 >> unit;
        addBuildingPrototype(building);
    }
    fin1.close();
    return true;
}

bool Game::writeObjects() {
    std::string path = givePath();
    path += "../common/datebase/Units.txt";
    std::ofstream fout; 
    fout.open(path, std::ios_base::out);
    if (!(fout.is_open()))
        return false;
    fout << unitPrototype_.size() << std::endl;;
    for ( int i = 0; i < unitPrototype_.size(); ++i ) { 
        Unit unit;
//        fout << unit;
        addUnitPrototype(unit);
    }
    fout.close();
    path = givePath();
    path += "../common/datebase/Buildings.txt";
    std::ofstream fout1; 
    fout1.open(path, std::ios_base::out);
    if (!(fout1.is_open()))
        return false;
    fout1 << buildingPrototype_.size() << std::endl;
    for ( int i = 0; i < buildingPrototype_.size(); ++i ) { 
        Building building;
//        fout1 << unit;
        addBuildingPrototype(building);
    }
    fout1.close();
    return true;
}

bool Game::save( std::string path ) {
//      path += ".save";
//      std::ofstream fout; 
//      fout.open(path, std::ios_base::out);
//      if (!(fout.is_open()))
//          return false;
//      // map
//      fout << map_.getSize()
//           << std::endl;
//      for ( int i = 0; i < map_.getSize(); ++i ) {
//          fout << map_[i].size()
//               << std::endl;
//          for ( int j = 0; j < map_.getSize(); ++j ) {
//              fout << map_[i][j].getCoors().first
//                   << map_[i][j].getCoors().second
//                   << std::endl;
//              if ( map_[i][j].getObject() ) {
//                  fout << map_[i][j].getObject()->getId().first
//                       << map_[i][j].getObject()->getId().second
//                       << std::endl;
//              }
//              else {
//                  fout << -1
//                       << -1
//                       << std::endl;
//              }
//              fout << map_[i][j].getAttackedBy().size()
//                   << std::endl;
//              for ( auto k : map_[i][j].getAttackedBy() ) {
//                  fout << k->getId().first
//                       << k->getId().second
//                       << std::endl;
//              }
//              // map.terrain
//              fout << map_[i][j].getTerrain().getSpeedMultiplier() << ' '
//                   << map_[i][j].getTerrain().getPermeability()
//                   << std::endl;
//          }
//      }
//      // units
//      fout << unitPrototype_.size() << std::endl;
//      for ( int i = 0; i < unitPrototype_.size(); ++i ) {
//          if ( unitPrototype_[i].getPlaces() ) {
//              fout << unitPrototype_[i].getPlaces()->getCoors().first << ' '
//                   << unitPrototype_[i].getPlaces()->getCoors().second
//                   << std::endl;
//          }
//          else {
//              fout << -1
//                   << -1
//                   << std::endl;
//          }
//          fout << unitPrototype_[i].SimpleObject::getName()
//               << std::endl;
//          fout << unitPrototype_[i].MovingObject::getSpeed()
//               << std::endl;
//          fout << unitPrototype_[i].MovingObject::getDestination().first << ' '
//               << unitPrototype_[i].MovingObject::getDestination().second
//               << std::endl;
//          fout << unitPrototype_[i].AttackingObject::getDamage() << ' '
//               << unitPrototype_[i].AttackingObject::getRange()
//               << std::endl;  
//          fout << unitPrototype_[i].DestroyableObject::getHealth() << ' '
//               << std::endl;
//          fout << unitPrototype_[i].getId().first << ' '
//               << unitPrototype_[i].getId().second
//               << std::endl;
//          fout << unitPrototype_[i].getRequirements().size()
//               << std::endl;
//          for ( auto j : unitPrototype_[i].getRequirements() ) {
//              fout << j->getId().second
//                   << std::endl;
//          }
//      }
//      // building
//      fout << buildingPrototype_.size() << std::endl;
//      for ( int i = 0; i < buildingPrototype_.size(); ++i ) {
//          if ( buildingPrototype_[i].getPlaces() ) {
//              fout << buildingPrototype_[i].getPlaces()->getCoors().first << ' '
//                   << buildingPrototype_[i].getPlaces()->getCoors().second
//                   << std::endl;
//          }
//          else {
//              fout << -1
//                   << -1
//                   << std::endl;
//          }
//          fout << buildingPrototype_[i].SimpleObject::getName()
//               << std::endl;
//          fout << buildingPrototype_[i].AttackingObject::getDamage() << ' '
//               << buildingPrototype_[i].AttackingObject::getRange()
//               << std::endl;
//          fout << buildingPrototype_[i].DestroyableObject::getHealth()
//               << std::endl;
//          fout << buildingPrototype_[i].getId().first << ' '
//               << buildingPrototype_[i].getId().second
//               << std::endl;
//          fout << buildingPrototype_[i].getTrainables().size()
//               << std::endl;
//          for ( auto j : buildingPrototype_[i].getTrainables() ) {
//              fout << j->getId().second
//                   << std::endl;
//          }
//          fout << buildingPrototype_[i].getRequirements().size()
//               << std::endl;
//          for ( auto j : buildingPrototype_[i].getRequirements() ) {
//              fout << j->getId().second
//                   << std::endl;
//          }
//      }
//      // resource
//      fout << resourcePrototype_.size()
//           << std::endl;
//      for ( int i = 0; i < resourcePrototype_.size(); ++i ) {
//          fout << resourcePrototype_[i]
//               << std::endl;
//      }
//      fout << players_.size()
//           << std::endl;
//      // players
//      for ( int i = 0; i < players_.size(); ++i ) {
//          fout << players_[i].getId()
//               << std::endl;
//          fout << players_[i].getName()
//               << std::endl;
//          fout << players_[i].getColor()
//               << std::endl;
//          for ( int j = 0; j < players_[i].getResources().size(); ++j ) {
//              fout << players_[i].getResources()[j].first
//                   << std::endl;
//              fout << players_[i].getResources()[j].second
//                   << std::endl;
//          }
//          // players.units
//          fout << players_[i].getUnits().size()
//               << std::endl;
//          for ( auto p : players_[i].getUnits() ) {
//              if ( p.getPlaces() ) {
//                  fout << p.getPlaces()->getCoors().first << ' '
//                       << p.getPlaces()->getCoors().second
//                       << std::endl;
//              }
//              else {
//                  fout << -1
//                       << -1
//                       << std::endl;
//              }
//              fout << p.SimpleObject::getName()
//                   << std::endl;
//              fout << p.MovingObject::getSpeed()
//                   << std::endl;
//              fout << p.MovingObject::getDestination().first << ' '
//                   << p.MovingObject::getDestination().second
//                   << std::endl;
//              fout << p.AttackingObject::getDamage() << ' '
//                   << p.AttackingObject::getRange()
//                   << std::endl;  
//              fout << p.DestroyableObject::getHealth()
//                   << std::endl;
//              fout << p.getId().first << ' '
//                   << p.getId().second
//                   << std::endl;
//              fout << p.getRequirements().size()
//                   << std::endl;
//              for ( auto j : p.getRequirements() ) {
//                  fout << j->getId().second
//                       << std::endl;
//              }
//          }
//          fout << players_[i].getChoosedUnits().size()
//               << std::endl;
//          for ( auto p : players_[i].getChoosedUnits() ) {
//              fout << p->getId().first
//                   << std::endl;
//              fout << p->getId().second
//                   << std::endl;
//          }
//          // players.buildings
//          fout << players_[i].getBuildings().size()
//               << std::endl;
//          for ( auto p : players_[i].getBuildings() ) {
//              if ( p.getPlaces() ) {
//                  fout << p.getPlaces()->getCoors().first << ' '
//                       << p.getPlaces()->getCoors().second
//                       << std::endl;
//              }
//              else {
//                  fout << -1
//                       << -1
//                       << std::endl;
//              }
//              fout << p.SimpleObject::getName()
//                   << std::endl;
//              fout << p.AttackingObject::getDamage() << ' '
//                   << p.AttackingObject::getRange()
//                   << std::endl;  
//              fout << p.DestroyableObject::getHealth()
//                   << std::endl;
//              fout << p.getId().first << ' '
//                   << p.getId().second
//                   << std::endl;
//              fout << p.getTrainables().size()
//                   << std::endl;
//              for ( auto j : p.getTrainables() ) {
//                  fout << j->getId().second
//                       << std::endl;
//              }
//              fout << p.getTraining().size()
//                   << std::endl;
//              for ( auto j : p.getTraining() ) {
//                  fout << j->getId().second
//                       << std::endl;
//              }
//              fout << p.getRequirements().size()
//                   << std::endl;
//              for ( auto j : p.getRequirements() ) {
//                  fout << j->getId().second
//                       << std::endl;
//              }
//          }
//      }
//      // add resource object and other
    return true;
}

bool Game::load( std::string path ) {
    // code
    return true;
}

bool Game::isLoose() {
    // code
    return true;
}

bool Game::endGame() {
    // code
    return true;
}
