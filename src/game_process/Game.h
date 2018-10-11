#ifndef GAME_H
#define GAME_H

#include "All-include.h"
#include "Player.h"
#include "Unit.h"
#include "Building.h"

class Game {
    protected:
        std::vector<Player> players_;
    public:
        Game();
        Game( int countOfPlayers );
        Game( std::vector<Player> players );
        
        void makeTurn();

//        bool readUnits(/**/);
// when add template
        bool save( std::string name );
        bool load( std::string name );

//        bool isLoose();
//        bool endGame();

};

#include "Game.tpp"

#endif // GAME_H
