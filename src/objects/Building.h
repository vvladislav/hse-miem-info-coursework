#ifndef BUILDING_H
#define BUILDING_H

#include "All-include.h"
#include "AttackingObject.h"
#include "DestroyableObject.h"
#include "Unit.h"

class Building : virtual public DestroyableObject,
                 virtual public AttackingObject
{
    private:
        std::list< Unit* > trainables_;
        std::list< Unit* > training_;
        std::list < Building* > requirements_;
    public:
        Building();
        Building(const Building& building);
        Building& operator= ( const Building& building);
        bool operator== (const Building& building) const;

        std::list< Unit* > const getTrainables() const;
        std::list< Unit* > const getTraining() const;
        std::list < Building* > const getRequirements() const;

        void setTrainables(std::list< Unit* > trainables);
        void setTraining(std::list< Unit* > training);
        void setRequirements(std::list< Building* > requirements);

        void addTrainables(Unit* trainables);
        void rmTrainables(int idRm);
        void addTraining(Unit* train);
        void rmTraining( int idRm );
        void addRequirements( Building*  add);
        void rmRequirements( int idRm);
        bool hasRequirements();
};

// std::ostream& operator << (std::ostream &s, Building& building);
// std::istream& operator >> (std::istream &s, Building& building); 

#endif // BUILDING_H
