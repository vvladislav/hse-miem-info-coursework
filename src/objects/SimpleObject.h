#ifndef SIMPLE_OBJECT_H
#define SIMPLE_OBJECT_H

#include "All-include.h"
#include "Place.h"
#include "Map.h"

class SimpleObject
{
    protected:
        std::vector<std::vector<Place*>> place_; // for matrix of Place* for big objects
        std::pair< int , int > id_; // player's id, id in list
        std::string name_;

    public:
        // wide uses in many variants in class Game
        QPixmap* image_;

        // methods
        SimpleObject();
        SimpleObject(Place*** place, int placeWidth, int placeHight);
        SimpleObject(const SimpleObject& simpleObject);
        SimpleObject& operator= ( const SimpleObject& simpleObject);
        bool operator== ( const SimpleObject& simpleObject) const;

        std::string const getName() const;
        std::pair<int,int> getId() const;
        std::vector<std::vector<Place*>> getPlaces() const;

        void setName( std::string name);
        void setId( std::pair<int,int> id );
        void setSize(int x, int y);
        void setPlaces( std::vector<std::vector<Place*>> place);
        void setPlace( Place* place, Map& map);

        ~SimpleObject();

};

#endif // SIMPLE_OBJECT_H
