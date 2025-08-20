#include "Fixed.hpp"
#include <iostream>

// Default constructor - initializes fixed-point value to 0
Fixed::Fixed() : _val(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) : _val(other._val) 
{
    std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _val = other._val;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

// Returns the raw value of the fixed-point number
int Fixed::getRawBits(void) const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return _val;
}

// Sets the raw value of the fixed-point number
void Fixed::setRawBits(int const raw) 
{
    _val = raw;
}