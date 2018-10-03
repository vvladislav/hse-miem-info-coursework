#include "All-include.h"
#include "Terrain.h"

Terrain::Terrain() {}

Terrain& Terrain::operator= (const Terrain& ter) {
    this->speed_ = ter.getSpeed();
    this->permeability_ = ter.getPermeability();
    return *this;
}

Terrain::Terrain( Terrain& ter ) {
    this->speed_ = ter.getSpeed();
    this->permeability_ = ter.getPermeability();
}

int Terrain::getSpeed() const {
    return speed_;
}

int Terrain::getPermeability() const {
    return permeability_;
}

void Terrain::setSpeed( int const speed ) {
    speed_ = speed;
}

void Terrain::setPermeability( int const permeability ) {
    permeability_ = permeability;
}

void Terrain::changeSpeed( int const proportion ) {
    speed_ *= proportion;
}

void Terrain::changePermeability( int const proportion ) {
    permeability_ *= proportion;
}
