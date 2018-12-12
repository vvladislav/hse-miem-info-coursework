#ifndef GAME_H
#define GAME_H

#include "All-include.h"
#include "Player.h"
#include "Unit.h"
#include "Building.h"

class Game {
    private:
        Map map_;
        std::vector<Player> players_;
        std::vector<Unit> unitPrototype_;
        std::vector<Building> buildingPrototype_;
        std::vector<std::string> resourcePrototype_;
    public:
        Game();
        Game( int countOfPlayers );
        Game( std::vector<Player> players );

        std::vector<Player> getPlayers(); 
        std::vector<Unit> getUnitPrototype();
        std::vector<Building> getBuildingPrototype();
        std::vector<std::string> getResourcePrototype();

        void setPlayers(std::vector<Player> players );  
        void setUnitPrototype(std::vector<Unit> unitPrototype );
        void setBuildingPrototype(std::vector <Building> buildingPrototype );
        void setResourcePrototype(std::vector <std::string> resourcePrototype );
        
        void addPlayers( Player add );  
        void addUnitPrototype( Unit add );
        void addBuildingPrototype( Building add );
        void addResourcePrototype( std::string add );
        
        void rmPlayers( Player rm );  
        void rmUnitPrototype( Unit rm );
        void rmBuildingPrototype( Building rm );
        void rmResourcePrototype( std::string rm );
        
        void makeTurn();

//        bool readUnits(/**/);

        bool save( std::string path );
        bool load( std::string path );

        bool isLoose();
        bool endGame();

};

#endif // GAME_H
