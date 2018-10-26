#ifndef UNIT_H
#define UNIT_H

#include "All-include.h"
#include "MovingObject.h"
#include "DestroyingObject.h"
#include "AttackingObject.h"

class Unit : public MovingObject,
             public DestroyingObject,
             public AttackingObject
{
    private:
        std::list < Building* > require_;
    public:
        Unit();
        Unit(const Unit& unit);
        Unit& operator= ( const Unit& unit);
        bool operator== (const Unit& unit) const;

        std::list < Building* > const getRequire() const;

        void setRequire(std::list< Building* > require);

        void addRequire( Building* add);
        void rmRequire( int idRm );
        bool hasRequire();

};

#endif // UNIT_H
