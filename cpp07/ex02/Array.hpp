#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
private:
    T*              _elements;
    unsigned int    _size;

public:
    Array() : _elements(NULL), _size(0) {}
    Array(unsigned int n) : _elements(new T[n]()), _size(n) {}
    Array(Array const & other) : _elements(NULL), _size(0) {
        *this = other;
    }
    Array & operator=(Array const & other)
    {
        if (this != &other)
        {
            if (_elements != NULL)
                delete[] _elements;
            
            _size = other._size;
            
            if (_size > 0)
            {
                _elements = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                {
                    _elements[i] = other._elements[i];
                }
            }
            else
            {
                _elements = NULL;
            }
        }
        return *this;
    }

    ~Array() {
        if (_elements != NULL)
            delete[] _elements;
    }

    T & operator[](unsigned int index)
    {
        if (index >= _size)
            throw OutOfBoundsException();
        return _elements[index];
    }

    unsigned int size() const
    {
        return _size;
    }

    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Array index out of bounds";
        }
    };
};

#endif
