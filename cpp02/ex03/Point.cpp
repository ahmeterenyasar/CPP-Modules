#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other)
{
    // std::cout << "Copy assignment operator called for Point instance" << std::endl;
    // Since _x and _y are const, we cannot assign them after initialization
    // This operator is required by Orthodox Canonical Form but cannot be fully implemented
    // We can only return *this
    (void)other; // To avoid unused parameter warning
    return (*this);
}

Point::~Point()
{}

Fixed Point::getX() const
{
    return (_x);
}

Fixed Point::getY() const
{
    return (_y);
}
