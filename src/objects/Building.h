#ifndef BUILDING_H
#define BUILDING_H

#include "All-include.h"
#include "AttackingObject.h"
#include "DestroyingObject.h"
#include "Unit.h"

class Building : public DestroyingObject, virtual public AttackingObject
{
    private:
        std::pair< int , int > id_; // player's id, id in vector
        std::vector< Unit* > train_;
        std::vector< Unit* > training_;
        std::vector < Building* > require_;
    public:
        //Building():DestroyingObject(){};
        //Building(std::pair<int,int> place):DestroyingObject(place){};
        Building& operator= ( const Building& building);

        std::vector< Unit* > const getTrain() const;
        std::vector< Unit* > const getTraining() const;
        std::vector < Building* > const getRequire() const;
        std::pair<int,int> getId() const;

        void setTrain(std::vector< Unit* > train);
        void setTraining(std::vector< Unit* > training);
        void setRequire(std::vector< Building* > require);
        void setId( std::pair<int,int> id );

        void addTrain(Unit* train);
        void rmTrain(int idRm);
        void addTraining(Unit* train);
        void rmTraining( int idRm );
        void addRequire( Building*  add);
        void rmRequire( int idRm);
        bool hasRequire();
};

#endif // BUILDING_H
