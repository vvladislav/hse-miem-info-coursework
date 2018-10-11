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
        std::list<int> choosed_;
        std::list<Unit> playersUnits_;
        std::list<Unit*> choosedUnits_; // maybe add for building
        std::list<Building> playersBuildings_;
        std::list<Place*> visiblePlaces_; // id
        bool inGame_;
        
    public:
        Player();
        Player(const Player& player);
        Player(int const idPlayer);

        int const getId() const;
        std::string const getName() const;
        int const getColor() const;
        std::list<Unit> getUnits() const;
        std::list<Building> getBuildings() const;
        std::list<Place*> getVisiblePlaces() const; 
        const std::list<Unit*> getChoosed() const;
        std::vector<int> getResource() const;

        //setPlaces();
        void setId(int const idPlayer);
        void setName(const std::string name);
        void setUnits(std::list<Unit> newUnits);
        void setChoosed(std::list<Unit*> chooseUnits);
        //void setPlaces(std::list<place> visiblePlaces);
        void setColor(int const idColor);

        void addUnit( Unit newUnit);
        void removeUnit( Unit oldUnit);
        void addBuilding( Building newBuilding);
        void removeBuilding( Building& oldBuilding);
        void addChoosed( Unit* chooseUnit );
        // think about choose buildings
        void changePlaces( Unit travelUnit);
        void changePlaces(std::list<Unit*> travelUnits );
        void addResources(int idResource, int quality);
        void spendResources(int idResource, int quality);

};

#endif // PLAYER_H
