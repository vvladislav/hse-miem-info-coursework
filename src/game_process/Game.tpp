#ifndef GAME_H
#define GAME_H

#include "All-include.h"
#include "Player.h"
#include "Unit.h"
#include "Building.h"

class Game {

Game::Game() {
    players_.resize(2);
}
        
Game::Game( int countOfPlayers ) {
    players_.resize(countOfPlayers);
}

Game::Game( std::vector<Player> players ) {
    players_ = players;
}

void Game::makeTurn() {

// code

}
       
// bool readUnits(/**/);

bool save( std::string name ) {

}

bool load( std::string name ) {

}

//bool isLoose();
//bool endGame();

};

#endif // GAME_H
