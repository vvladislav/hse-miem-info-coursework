#ifndef SIMPLE_OBJECT_H
#define SIMPLE_OBJECT_H

#include "All-include.h"
#include "Place.h"

class SimpleObject
{
    protected:
        std::pair<int,int> place_;
        std::string name_;
        // there are must be image
    public:
        SimpleObject();
        SimpleObject(std::pair<int,int> place);
        SimpleObject(const SimpleObject& simpleObject);
        SimpleObject& operator= ( const SimpleObject& simpleObject);
        bool operator== ( const SimpleObject& simpleObject) const;

        // there are must be function with image

        std::pair<int,int> const getPlace() const;
        std::string const getName() const;

        void setPlace( std::pair<int,int> place);
        void setName( std::string name);

};

#endif // SIMPLE_OBJECT_H
