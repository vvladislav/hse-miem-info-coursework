#include "All-include.h"
#include "Terrain.h"

Terrain::Terrain() {}

Terrain& Terrain::operator= (const Terrain& ter) {
    this->speedMultiplier_ = ter.getSpeedMultiplier();
    this->permeability_ = ter.getPermeability();
    return *this;
}

Terrain::Terrain( Terrain& ter ) {
    this->speedMultiplier_ = ter.getSpeedMultiplier();
    this->permeability_ = ter.getPermeability();
}

int Terrain::getSpeedMultiplier() const {
    return speedMultiplier_;
}

int Terrain::getPermeability() const {
    return permeability_;
}

void Terrain::setSpeedMultiplier( int const speedMultiplier ) {
    speedMultiplier_ = speedMultiplier;
}

void Terrain::setPermeability( int const permeability ) {
    permeability_ = permeability;
}

void Terrain::changeSpeedMultiplier( int const proportion ) {
    speedMultiplier_ *= proportion;
}

void Terrain::changePermeability( int const proportion ) {
    permeability_ *= proportion;
}
