#ifndef MAP_H
#define MAP_H

#include "All-include.h"
#include "Place.h"

class Map
{
    private:
        std::vector<std::vector<Place>> places_;
    public:
        Map();
        Map( int sizeX, int sizeY);
        Map(const Map& map);
        Map(std::vector<std::vector<Place>> places);
        Map& operator= (const Map& map);

        void setPlace( Place place);
        void setPlace( Place place, int x, int y);
        void setPlaces( std::vector<std::vector<Place>> places );

        Place getPlace(int x, int y) const;
        std::vector<std::vector<Place>> const getPlaces() const;

};

#endif // MAP_H
