#ifndef TERRAIN_H
#define TERRAIN_H

#include "All-include.h"

class Terrain {
    private:
        int speed_ = 1;
        int permeability_ = 1;
        // image
    public:
        Terrain();
        Terrain& operator= (const Terrain& ter);
        Terrain( Terrain& ter );

        int getSpeed() const;
        int getPermeability() const;

        void setSpeed( int const speed );
        void setPermeability( int const permeability );

        void changeSpeed( int const proportion );
        void changePermeability( int const proportion );

};

#endif // TERRAIN_H
