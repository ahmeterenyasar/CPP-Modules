#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int _val;
    static const int _fractionalBits = 8;

public:
    // Orthodox Canonical Form - Four required functions
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    
    // Member functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif