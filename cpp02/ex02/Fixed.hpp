#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    // Constructors and destructor
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    ~Fixed();

    // Assignment operator
    Fixed &operator=(const Fixed &other);

    // Getter and setter
    int getRawBits() const;
    void setRawBits(int const raw);

    // Conversion functions
    float toFloat() const;
    int toInt() const;

    // Comparison operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment/decrement operators
    Fixed &operator++();    // pre-increment
    Fixed operator++(int);  // post-increment
    Fixed &operator--();    // pre-decrement
    Fixed operator--(int);  // post-decrement

    // Static member functions
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Stream insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif