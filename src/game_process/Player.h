#ifndef PLAYER_H
#define PLAYER_H

#include "All-include.h"
#include "Unit.h"
#include "Building.h"

class Player {
    private:
        int id_;
        std::string name_;
        int color_;
        std::vector<std::pair<int,std::string> > resources_;
        std::list<Unit> playersUnits_;
        std::list<Unit*> choosedUnits_;
        std::list<Building> playersBuildings_;
        std::list<Building*> choosedBuildings_;
        std::list<Place*> visiblePlaces_; 
        bool inGame_;
        
    public:
        Player();
        Player(const Player& player);
        Player(int const id);
        bool operator== (const Player& player) const;

        int const getId() const;
        std::string const getName() const;
        int const getColor() const;
        std::list<Unit>& getUnits();
        std::list<Building>& getBuildings();
        std::list<Place*> getVisiblePlaces() const; 
        const std::list<Unit*> getChoosedUnits() const;
        const std::list<Building*> getChoosedBuildings() const;
        std::vector<std::pair<int,std::string> > getResources() const;
        bool getStatus() const;

        //setPlaces();
        void setId(int const id);
        void setName(const std::string name);
        void setUnits(std::list<Unit> newUnits);
        void setChoosedUnits(std::list<Unit*> chooseUnits);
        void setChoosedBuildings(std::list<Building*> chooseBuildings);
        //void setPlaces(std::list<place> visiblePlaces);
        void setColor(int const idColor);
        void setResources(std::vector<std::pair<int,std::string> > resources);
        void setStatus( bool inGame );

        void add( Unit newUnit);
        void remove( Unit oldUnit);
        void add( Building newBuilding);
        void remove( Building& oldBuilding);
        void addChoosedUnit( Unit* chooseUnit );
        void addChoosedBuilding( Building* chooseBuilding );
        void changePlaces( Unit travelUnit);
        void changePlaces(std::list<Unit*> travelUnits );
        void addResources(int idResources, int quality);
        void spendResources(int idResources, int quality);

};

#endif // PLAYER_H
