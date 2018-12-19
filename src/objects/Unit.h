#ifndef UNIT_H
#define UNIT_H

#include "All-include.h"
#include "MovingObject.h"
#include "DestroyableObject.h"
#include "AttackingObject.h"

class Unit : virtual public MovingObject,
             virtual public DestroyableObject,
             virtual public AttackingObject
{
    private:
        std::list < Building* > requirements_;
    public:
        Unit();
        Unit(const Unit& unit);
        Unit(std::string name, int placeWidth, int placeHight, QPixmap* image
            , int damage, int range, int health, int speed, std::list<Building*>& requirements);
        Unit& operator= ( const Unit& unit);
        bool operator== (const Unit& unit) const;

        std::list < Building* > const getRequirements() const;

        void setRequirements(std::list< Building* > requirements);

        void addRequirements( Building* add);
        void rmRequirements( int idRm );
        bool hasRequirements();

};

#endif // UNIT_H
