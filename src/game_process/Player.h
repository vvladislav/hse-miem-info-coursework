#ifndef PLAYER_H
#define PLAYER_H

#include "All-include.h"
#include "Unit.h"
#include "Building.h"

class Player {
    private:
        int idPlayer_;
        std::string name_;
        int colorPlayer_;
        std::vector<int> resource_;
        std::vector<int> choosed_;
        std::vector<Unit> playersUnits_;
        std::vector<Unit*> choosedUnits_; // maybe add for building
        std::vector<Building> playersBuildings_;
        std::vector<Place*> visiblePlaces_; // id
        
    public:
        Player();
        Player(const Player& player);
        Player(int const idPlayer);

        int const getId() const;
        std::string const getName() const;
        int const getColor() const;
        std::vector<Unit> getUnits() const;
        std::vector<Building> getBuildings() const;
        std::vector<Place*> getVisiblePlaces() const; 
        const std::vector<Unit*> getChoosed() const;
        std::vector<int> getResource() const;

        //setPlaces();
        void setId(int const idPlayer);
        void setName(const std::string name);
        void setUnits(std::vector<Unit> newUnits);
        void setChoosed(std::vector<Unit*> chooseUnits);
        //void setPlaces(std::vector<place> visiblePlaces);
        void setColor(int const idColor);

        void addUnit( Unit newUnit);
        void removeUnit( Unit oldUnit);
        void addBuilding( Building newBuilding);
        void removeBuilding( Building& oldBuilding);
        void removeBuilding( int oldBuilding);
        void addIdChoosed(int chooseUnit);
        void addIdChoosed(std::vector<Unit*> chooseUnit);
        // think about choose buildings
        void changePlaces( Unit travelUnit);
        void changePlaces(std::vector<Unit*> travelUnits );
        void addResources(int idResource, int quality);
        void spendResources(int idResource, int quality);

};

#endif // PLAYER_H
