#ifndef UNIT_H
#define UNIT_H

#include "All-include.h"
#include "MovingObject.h"
#include "DestroyingObject.h"
#include "AttackingObject.h"
//#include "Building.h"

//class Unit : virtual public MovingObject,
//             virtual public DestroyingObject,
//             virtual public AttackingObject
class Unit : public MovingObject,
             public DestroyingObject,
             public AttackingObject
{
    private:
        std::pair< int , int > id_; // < player's id, id in vector >
        std::vector < Building* > require_;
    public:
        //Unit():SimpleObject(){};
        //Unit(std::pair<int,int> place): SimpleObject(place){};
        Unit& operator= ( const Unit& unit);

        std::vector < Building* > const getRequire() const;
        std::pair<int,int> getId() const;

        void setRequire(std::vector< Building* > require);
        void setId( std::pair<int,int> id );

        void addRequire( Building* add);
        void rmRequire( int idRm );
        bool hasRequire();

};

#endif // UNIT_H
