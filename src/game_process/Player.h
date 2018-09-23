#ifndef PLAYER_H
#define PLAYER_H

#include "All-include.h"

class Player
{
    private:
        int idPlayer_;
        std::string name_;
        int colorPlayer_;
        std::vector<int> resource_;
        std::vector<int> choosed_;
        std::vector<> playersUnits_;
        std::vector<Building> playersBuildings_;
        std::vector<std::pair<int,int>> visiblePlaces_; // id
        
    public:
        Player();
        Player(const Player& player);
        Player(int const idPlayer);

        int const getId() const;
        std::string const getName() const;
        int const getColor() const;
        std::vector<> getUnits() const;
        std::vector<Building> getBuildings() const;
        std::vector<Place> getVisiblePlaces() const; 
        std::vector<int> getChoosed() const;
        std::vector<int> getResource() const;

        //setPlaces();
        void setId(int const idPlayer);
        void setName(const std::string name);
        void set(std::vector<Unit> newUnits);
        void setChoosed(std::vector<int> chooseUnits);
        //void setPlaces(std::vector<place> visiblePlaces);
        void setColor(int const idColor);

        void addUnit( newUnit);
        void removeUnit( oldUnit);
        void addBuilding( newBuilding);
        void removeBuilding( oldBuilding);
        void addIdChoosed(int chooseUnit);
        void addIdChoosed(std::vector<int> chooseUnits);
        // think about choose buildings
        void changePlaces( travelUnit);
        void changePlaces(std::vector<> travelUnits );
        void addResources(int idResource, int quality);
        void spendResources(int idResource, int quality);

};

#endif // PLAYER_H
