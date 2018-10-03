#ifndef PLACE_H
#define PLACE_H

#include "All-include.h"
#include "Terrain.h"

class Place
{
    private:
        std::pair<int,int> coors_;
        SimpleObject* stand_ = nullptr;
        std::vector<AttackingObject*> attack_;
        Terrain ter_;
    public:
        Place();
        Place& operator= ( const Place& place);
        Place( const Place& place );
        Place( int x, int y);
        Place( std::pair<int,int> coors);
        Place( int x, int y , Terrain ter);
        
        std::pair< int , int > const getCoors() const;
        std::vector<AttackingObject*> getAttack() const;
        const Terrain& getTerrain() const;

        void setAttack(std::vector<AttackingObject*> object);
        void setAttack(AttackingObject &object);
        void setTerrain( Terrain& ter);

        void addObject(SimpleObject* newObject);
        void removeObject();

};

#endif // PLACE_H
