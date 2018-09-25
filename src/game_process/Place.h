#ifndef PLACE_H
#define PLACE_H

#include "All-include.h"

class Place
{
    private:
        std::pair<int,int> const coors_;
        Object* stand_ = nullptr;
        std::vector<attackObject*> attack_;
        Terrain ter_;
        
    public:
        Place();
        Place& operator= (const PLace& place);
        Place( Place& place );
        Place( int x, int y);
        Place( std::pair<int,int> coors);
        Place( int x, int y , Terrain ter);
        
        std::pair< int , int > const getCoors() const;
        std::vector<attackObject*> getAttackObjects() const;
        terrain getTerrain() const;

        void setAttack(std::vector<attackObject*> object);
        void setAttack(attackObject object);
        void setTerrain( &Terrain ter);

        void addObject(Object newObject);
        void removeObject();

};

#endif // PLACE_H
