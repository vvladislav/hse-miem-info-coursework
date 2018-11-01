#ifndef SIMPLE_OBJECT_H
#define SIMPLE_OBJECT_H

#include "All-include.h"
#include "Place.h"
#include "Map.h"

class SimpleObject
{
    protected:
        std::pair< int , int > id_; // player's id, id in list
        Place* place_;
        std::string name_;
        // there are must be image
    public:
        SimpleObject();
        SimpleObject(Place* place);
        SimpleObject(const SimpleObject& simpleObject);
        SimpleObject& operator= ( const SimpleObject& simpleObject);
        bool operator== ( const SimpleObject& simpleObject) const;

        // there are must be function with image

        Place* const getPlace() const;
        std::string const getName() const;
        std::pair<int,int> getId() const;

        void setPlace( Place* place);
        void setName( std::string name);
        void setId( std::pair<int,int> id );

        ~SimpleObject();

};

#endif // SIMPLE_OBJECT_H
