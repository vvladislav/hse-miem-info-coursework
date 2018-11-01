#ifndef PLACE_H
#define PLACE_H

#include "All-include.h"
#include "Terrain.h"

class Place
{
    private:
        std::pair<int,int> coors_;
        SimpleObject* object_ = nullptr;
        std::list<AttackingObject*> attackedBy_; // think about it;
        Terrain ter_;
    public:
        Place();
        Place& operator= ( const Place& place);
        Place( const Place& place );
        Place( int x, int y);
        Place( std::pair<int,int> coors);
        Place( int x, int y , Terrain ter);
        
        std::pair< int , int > const getCoors() const;
        std::list<AttackingObject*> getAttackedBy() const;
        const Terrain& getTerrain() const;
        const SimpleObject* getObject() const;

        void setAttackedBy(std::list<AttackingObject*> object);
        void setAttackedBy(AttackingObject &object);
        void setTerrain( Terrain& ter);
        void setObject(SimpleObject* newObject);

};

#endif // PLACE_H
