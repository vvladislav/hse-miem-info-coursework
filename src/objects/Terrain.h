#ifndef TERRAIN_H
#define TERRAIN_H

#include "All-include.h"

class Terrain {
    private:
        int speedMultiplier_ = 1;
        int permeability_ = 1;
        // image
    public:
        // methods
        QPixmap* image_;
        // functions
        Terrain();
        Terrain& operator= (const Terrain& ter);
        Terrain( Terrain& ter );

        int getSpeedMultiplier() const;
        int getPermeability() const;

        void setSpeedMultiplier( int const speedMultiplier );
        void setPermeability( int const permeability );

        void changeSpeedMultiplier( int const proportion );
        void changePermeability( int const proportion );

};

#endif // TERRAIN_H
