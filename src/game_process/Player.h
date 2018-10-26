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
        std::vector<std::pair<int,std::string> > resource_;
        std::list<Unit> playersUnits_;
        std::list<Unit*> choosedUnits_;
        std::list<Building> playersBuildings_;
        std::list<Building*> choosedBuildings_;
        std::list<Place*> visiblePlaces_; 
        bool inGame_;
        
    public:
        Player();
        Player(const Player& player);
        Player(int const idPlayer);
        bool operator== (const Player& player) const;

        int const getId() const;
        std::string const getName() const;
        int const getColor() const;
        std::list<Unit> getUnits() const;
        std::list<Building> getBuildings() const;
        std::list<Place*> getVisiblePlaces() const; 
        const std::list<Unit*> getChoosedUnits() const;
        const std::list<Building*> getChoosedBuildings() const;
        std::vector<std::pair<int,std::string> > getResource() const;
        bool getStatus() const;

        //setPlaces();
        void setId(int const idPlayer);
        void setName(const std::string name);
        void setUnits(std::list<Unit> newUnits);
        void setChoosedUnits(std::list<Unit*> chooseUnits);
        void setChoosedBuildings(std::list<Building*> chooseBuildings);
        //void setPlaces(std::list<place> visiblePlaces);
        void setColor(int const idColor);
        void setResource(std::vector<std::pair<int,std::string> > resource);
        void setStatus( bool inGame );

        void addUnit( Unit newUnit);
        void removeUnit( Unit oldUnit);
        void addBuilding( Building newBuilding);
        void removeBuilding( Building& oldBuilding);
        void addChoosedUnit( Unit* chooseUnit );
        void addChoosedBuilding( Building* chooseBuilding );
        void changePlaces( Unit travelUnit);
        void changePlaces(std::list<Unit*> travelUnits );
        void addResources(int idResource, int quality);
        void spendResources(int idResource, int quality);

};

#endif // PLAYER_H
