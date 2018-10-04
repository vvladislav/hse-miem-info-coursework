#include "ResouceObject.h"

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
