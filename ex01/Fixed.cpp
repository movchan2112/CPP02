#include "Fixed.hpp"

Fixed::Fixed(const int n){
    std::cout << "Default constructor called" << std::endl;
    this->_value = n << _bits; 
}

Fixed::Fixed(const Fixed &other) : _value(other._value){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other){
        this->_value = other._value;
    }
    return *this;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}