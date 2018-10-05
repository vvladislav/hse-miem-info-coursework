#include "All-include.h"
#include "ResourceObject.h"

ResourceObject::ResourceObject() {
    value_ = 1;
    type_ = "No name";
}

ResourceObject::ResourceObject(const ResourceObject& resourceObject) {
    this->value_ = resourceObject.getValue();
    this->type_ = resourceObject.getType(); 
}

ResourceObject& ResourceObject::operator= ( const ResourceObject& resourceObject ) {
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

std::string const ResourceObject::getType() const {
    return type_;
}

void ResourceObject::setValue( int value ) {
    value_ = value;
}

void ResourceObject::setType( std::string type ) {
    type_ = type;
}

void ResourceObject::addValue( int add ) {
    value_ += add;
}

void ResourceObject::rmValue( int rm ) {
    value_ -= rm;
}
