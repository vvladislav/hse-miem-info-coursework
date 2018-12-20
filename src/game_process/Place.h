#ifndef PLACE_H
#define PLACE_H

#include "All-include.h"
#include "Terrain.h"
// #include "Building.h"
// #include "Unit.h"

class Place
{
    private:
        std::pair<int,int> coors_;
        std::pair< std::pair<int,int> , int > object_ = std::make_pair(std::make_pair(-1,-1),-1); // id player, type from enum
        std::list< std::pair< std::pair<int,int> , int > > attackedBy_; // list : id player, type from enum
        Terrain ter_;
    public:
        Place();
        Place& operator= ( const Place& place);
        Place( const Place& place );
        Place( int x, int y);
        Place( std::pair<int,int> coors);
        Place( int x, int y , Terrain ter);
        
        std::pair< int , int > const getCoors() const;
        std::list< std::pair< std::pair<int,int> , int > > getAttackedBy() const;
        const Terrain& getTerrain() const;
        std::pair< std::pair<int,int> , int > getObject() const;

        void setAttackedBy(std::list< std::pair< std::pair<int,int> , int > > object);
        void addAttackedBy(Unit &object);
        void addAttackedBy(Building &object);
        void setTerrain( Terrain& ter);
        void setObject(std::pair< std::pair<int,int> , int > newObject);
        void setObject( const Unit* newObject);
        void setObject( const Building* newObject);
        void setObject( Unit* newObject);
        void setObject( Building* newObject);

};

#endif // PLACE_H
