#ifndef RESOURCE_OBJECT_H
#define RESOURCE_OBJECT_H

#include "All-include.h"

class ResourceObject : SimpleObject
{
    private:
        int value;
        int type;
    public:
        ResourceObject(): SimpleObject(){};
        ResourceObject(std::pair<int,int> place): SimpleObject(std::pair<int,int> place){};

        int const getValue() const ;
        int const getType() const ;

        void setValue( int Value );
        void setType( int Type );

        void addValue( int add );
        void rmValue( int rm );

};

#endif // RESOURCE_OBJECT_H
