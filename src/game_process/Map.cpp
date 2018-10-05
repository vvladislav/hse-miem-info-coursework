#include "All-include.h"
#include "Map.h"

Map::Map() {
    places_.resize( 0 );
    for ( auto placesLine : places_ )
        placesLine.resize( 0 );
}

Map::Map( int sizeX, int sizeY) {
    places_.resize( sizeY );
    for ( auto placesLine : places_ )
        placesLine.resize( sizeX );
}

Map::Map( std::vector<std::vector<Place>> allPlaces ) {
    places_ =  allPlaces;
}

Map::Map(const Map& map) {
    this->places_ =  map.getPlaces();
}

Map& Map::operator = (const Map& map) {
    this->places_  =  map.getPlaces();
    return *this;
}

void Map::setPlace( Place place) {
    if ( place.getCoors().first >= 0 &&
            place.getCoors().second >= 0 &&
                place.getCoors().first <= places_.size() &&
                    place.getCoors().second <= places_[0].size())
        places_ [place.getCoors().first] [place.getCoors().second] = place;
    else
        std::cout << "Exit from game space" << std::endl;
}

void Map::setPlace( Place place, int x, int y) {
    if ( x >= 0 &&
            y >= 0 &&
                x <= places_.size() &&
                    y <= places_[0].size())
        places_ [place.getCoors().first] [place.getCoors().second] = place;
    else
        std::cout << "Exit from game space" << std::endl;
}

void Map::setPlaces( std::vector<std::vector<Place>> places ) {
    places_ =  places;
}

Place Map::getPlace(int x, int y) const {
    return places_[x][y];
}

std::vector<std::vector<Place>> const Map::getPlaces() const {
    return places_;
}
