#ifndef BUILDING_H
#define BUILDING_H

#include "All-include.h"
#include "AttackingObject.h"
#include "DestroyingObject.h"
#include "Unit.h"

class Building : public DestroyingObject, public AttackingObject
{
    private:
        std::pair< int , int > id_; // player's id, id in list
        std::list< Unit* > train_;
        std::list< Unit* > training_;
        std::list < Building* > require_;
    public:
        Building();
        Building(const Building& building);
        Building& operator= ( const Building& building);

        std::list< Unit* > const getTrain() const;
        std::list< Unit* > const getTraining() const;
        std::list < Building* > const getRequire() const;
        std::pair<int,int> getId() const;

        void setTrain(std::list< Unit* > train);
        void setTraining(std::list< Unit* > training);
        void setRequire(std::list< Building* > require);
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
