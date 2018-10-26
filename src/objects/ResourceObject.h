#ifndef RESOURCE_OBJECT_H
#define RESOURCE_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class ResourceObject : virtual public SimpleObject
{
    private:
        int value_;
        int type_;
    public:
        ResourceObject();
        ResourceObject(const ResourceObject& ResourceObject);
        ResourceObject& operator= ( const ResourceObject& resourceObject);
        ResourceObject& operator- ( int rm );
        ResourceObject& operator+ ( int add );

        int const getValue() const ;
        int const getType() const ;

        void setValue( int value );
        void setType( int type );

        void addValue( int add );
        void rmValue( int rm );

};

#endif // RESOURCE_OBJECT_H
