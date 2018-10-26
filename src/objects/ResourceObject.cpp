#include "All-include.h"
#include "ResourceObject.h"

ResourceObject::ResourceObject() {
    value_ = 1;
    type_ = 0;
}

ResourceObject::ResourceObject(const ResourceObject& resourceObject): SimpleObject(resourceObject) {
    this->value_ = resourceObject.getValue();
    this->type_ = resourceObject.getType(); 
}

ResourceObject& ResourceObject::operator= ( const ResourceObject& resourceObject ) {
    SimpleObject::operator= (resourceObject);
    this->value_ = resourceObject.getValue();
    this->type_ = resourceObject.getType(); 
    return *this;
}

ResourceObject& ResourceObject::operator- ( int rm ) {
    value_ -= rm;
    return *this;
}

ResourceObject& ResourceObject::operator+ ( int add ) {
    value_ += add;
    return *this;
}

int const ResourceObject::getValue() const {
    return value_;
}

int const ResourceObject::getType() const {
    return type_;
}

void ResourceObject::setValue( int value ) {
    value_ = value;
}

void ResourceObject::setType( int type ) {
    type_ = type;
}

void ResourceObject::addValue( int add ) {
    value_ += add;
}

void ResourceObject::rmValue( int rm ) {
    value_ -= rm;
}
