#ifndef MAP_H
#define MAP_H

#include "All-include.h"

class Map
{
    private:
        std::vector<std::vector<Place>> places_;
    public:
        Map();
        Map( int mapSize);
        Map(const Map& map);
        Map(std::vector<std::vector<Place>> places);
        Map operator= (const Map& map);

        void setPlace( Place place);
        void setPlace( Place place, int x, int y);
        void setPlaces( std::vector<std::vector<Place>> places );

        Place const getPlace(int x, int y) const;
        std::vector<std::vector<Place>> const getPlaces() const;

};

#endif // MAP_H
