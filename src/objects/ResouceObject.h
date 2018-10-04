#ifndef RESOURCE_OBJECT_H
#define RESOURCE_OBJECT_H

#include "All-include.h"
#include "SimpleObject.h"

class ResourceObject : public SimpleObject
{
    private:
        int value_;
        std::string type_;
    public:
        //ResourceObject(): SimpleObject(){};
        //ResourceObject(std::pair<int,int> place): SimpleObject(std::pair<int,int> place){};

        virtual int const getValue() const ;
        virtual std::string const getType() const ;

        virtual void setValue( int value );
        virtual void setType( std::string type );

        virtual void addValue( int add );
        virtual void rmValue( int rm );

};

#endif // RESOURCE_OBJECT_H
