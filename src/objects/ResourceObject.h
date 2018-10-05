#ifndef RESOURCE_OBJECT_H
#define RESOURCE_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class ResourceObject : virtual public SimpleObject
{
    private:
        int value_;
        std::string type_;
    public:
        ResourceObject();
        ResourceObject(const ResourceObject& ResourceObject);
        ResourceObject& operator= ( const ResourceObject& resourceObject);
        ResourceObject& operator- ( int rm );
        ResourceObject& operator+ ( int add );

        int const getValue() const ;
        std::string const getType() const ;

        void setValue( int value );
        void setType( std::string type );

        void addValue( int add );
        void rmValue( int rm );

};

#endif // RESOURCE_OBJECT_H
