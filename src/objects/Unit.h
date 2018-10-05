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
        std::pair< int , int > id_; // < player's id, id in list >
        std::list < Building* > require_;
    public:
        Unit& operator= ( const Unit& unit);

        std::list < Building* > const getRequire() const;
        std::pair<int,int> getId() const;

        void setRequire(std::list< Building* > require);
        void setId( std::pair<int,int> id );

        void addRequire( Building* add);
        void rmRequire( int idRm );
        bool hasRequire();

};

#endif // UNIT_H
