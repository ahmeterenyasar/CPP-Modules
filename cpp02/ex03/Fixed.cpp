#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
    // std::cout << "Default constructor called for Fixed instance" << "\n";
}

Fixed::Fixed(const int value) : _fixedPointValue(value * (1 << _fractionalBit))
{
    // std::cout << "Integer constructor called for Fixed instance" << "\n";
}

Fixed::Fixed(const float value) : _fixedPointValue(roundf(value * (1 << _fractionalBit)))
{
    // std::cout << "Float constructor called for Fixed instance" << "\n";
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue)
{
    // std::cout << "Copy constructor called for Fixed instance" << "\n";
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called for fixed instance" << "\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called for Fixed instance" << "\n";
    if (this != &other)
    {
        _fixedPointValue = other._fixedPointValue;
    }
    return (*this);
}

int Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called" << "\n";

    return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << "\n";
    _fixedPointValue = raw;
}


float Fixed::toFloat(void) const
{
    return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBit));
}

int Fixed::toInt(void) const
{
    return (roundf(static_cast<float>(_fixedPointValue) / (1 << _fractionalBit)));
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->_fixedPointValue != other._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;

    result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;

    result._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;

    long long mul =
        static_cast<long long>(this->_fixedPointValue) * other._fixedPointValue;
    result._fixedPointValue = static_cast<int>(mul / (1 << _fractionalBit));

    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;

    if (other._fixedPointValue == 0)
        throw std::runtime_error("Division by zero");

    long long numerator =
        static_cast<long long>(this->_fixedPointValue) * (1 << _fractionalBit);
    long long division = numerator / other._fixedPointValue;
    result._fixedPointValue = static_cast<int>(division);

    return (result);
}

Fixed &Fixed::operator++()
{
    _fixedPointValue += 1;
    return (*this);
}

Fixed &Fixed::operator--()
{
    _fixedPointValue -= 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    _fixedPointValue += 1;
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    _fixedPointValue -= 1;
    return (temp);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return ((a > b) ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return ((a < b) ? a : b);
}