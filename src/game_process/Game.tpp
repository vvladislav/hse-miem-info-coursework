#ifndef GAME_TPP
#define GAME_TPP

#include "All-include.h"
#include "Player.h"
#include "Unit.h"
#include "Building.h"

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

// code

}
       
// bool readUnits(/**/);

bool Game::save( std::string saveFileName ) {
#ifdef __unix__
    char result[256];
    ssize_t count = readlink("/proc/self/exe", result, 256);
    std::string path;
    path = std::string(result , (count > 0) ? count : 0);
    for (int i = path.size() - 1 ; path[i] != '/' ; --i) 
        path.pop_back();
    path += "../common/save/";
#endif
    path += saveFileName;
    path += ".save";
    std::ofstream fout; 
    fout.open(path, std::ios_base::out);
    if (!(fout.is_open()))
        return false;
    // read game private
    fout << unitPrototype_.size() << std::endl;
    for ( int i = 0; i < unitPrototype_.size(); ++i ) {
        fout << unitPrototype_[i].SimpleObject::getPlace()->getCoors().first
             << unitPrototype_[i].SimpleObject::getPlace()->getCoors().second
             << std::endl;
        fout << unitPrototype_[i].SimpleObject::getName()
             << std::endl;
        fout << unitPrototype_[i].MovingObject::getSpeed();
        fout << unitPrototype_[i].MovingObject::getEndPoint().first
             << unitPrototype_[i].MovingObject::getEndPoint().second
             << std::endl;
        fout << unitPrototype_[i].AttackingObject::getAttack()
             << unitPrototype_[i].AttackingObject::getRange()
             << std::endl;  
        fout << unitPrototype_[i].DestroyingObject::getHealth()
             << std::endl;
        fout << unitPrototype_[i].getId().first
             << unitPrototype_[i].getId().second
             << std::endl;
        fout << unitPrototype_[i].getRequire().size()
             << std::endl;
        for ( auto j : unitPrototype_[i].getRequire() ) {
            fout << j->getId().second
                 << std::endl;
        }
    }
    fout << buildingPrototype_.size() << std::endl;
    for ( int i = 0; i < buildingPrototype_.size(); ++i ) {
        //building
    }
    fout << resourcePrototype_.size()
         << std::endl;
    for ( int i = 0; i < resourcePrototype_.size(); ++i ) {
        fout << resourcePrototype_[i]
             << std::endl;
    }
    fout << players_.size()
         << std::endl;
    for ( int i = 0; i < players_.size(); ++i ) {
        fout << players_[i].getId()
             << std::endl;
        fout << players_[i].getName()
             << std::endl;
        fout << players_[i].getColor()
             << std::endl;
        for ( int j = 0; j < players_[i].getResource().size(); ++j ) {
            fout << players_[i].getResource()[j].first
                 << std::endl;
            fout << players_[i].getResource()[j].second
                 << std::endl;
        }
        fout << players_[i].getUnits().size()
             << std::endl;
        for ( auto p : players_[i].getUnits() ) {
            fout << p.SimpleObject::getPlace()->getCoors().first
                 << p.SimpleObject::getPlace()->getCoors().second
                 << std::endl;
            fout << p.SimpleObject::getName()
                 << std::endl;
            fout << p.MovingObject::getSpeed();
            fout << p.MovingObject::getEndPoint().first
                 << p.MovingObject::getEndPoint().second
                 << std::endl;
            fout << p.AttackingObject::getAttack()
                 << p.AttackingObject::getRange()
                 << std::endl;  
            fout << p.DestroyingObject::getHealth()
                 << std::endl;
            fout << p.getId().first
                 << p.getId().second
                 << std::endl;
            fout << p.getRequire().size()
                 << std::endl;
            for ( auto j : p.getRequire() ) {
                fout << j->getId().second
                     << std::endl;
            }
        }
        fout << players_[i].getChoosedUnits().size()
             << std::endl;
        for ( auto p : players_[i].getChoosedUnits() ) {
            fout << p->getId().first
                 << std::endl;
            fout << p->getId().second
                 << std::endl;
        }
        //buildings
        fout << players_[i].getBuildings().size()
             << std::endl;
        for ( auto p : players_[i].getBuildings() ) {
            fout << p.SimpleObject::getPlace()->getCoors().first
                 << p.SimpleObject::getPlace()->getCoors().second
                 << std::endl;
            fout << p.SimpleObject::getName()
                 << std::endl;
            fout << p.AttackingObject::getAttack()
                 << p.AttackingObject::getRange()
                 << std::endl;  
            fout << p.DestroyingObject::getHealth()
                 << std::endl;
            fout << p.getId().first
                 << p.getId().second
                 << std::endl;
            fout << p.getTrain().size()
                 << std::endl;
            for ( auto j : p.getTrain() ) {
                fout << j->getId().second
                     << std::endl;
            }
            fout << p.getTraining().size()
                 << std::endl;
            for ( auto j : p.getTraining() ) {
                fout << j->getId().second
                     << std::endl;
            }
            fout << p.getRequire().size()
                 << std::endl;
            for ( auto j : p.getRequire() ) {
                fout << j->getId().second
                     << std::endl;
            }
        }
    }
    return true;
}

bool Game::load( std::string loadFileName ) {
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

#endif // GAME_TPP
