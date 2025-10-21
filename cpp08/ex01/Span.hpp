#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits>
#include <exception>
#include <iostream>
class Span {
    private:
        unsigned int _N;
        std::vector<int> _vect;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();


        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end) {
            while (begin != end)
            {
                if (_vect.size() >= _N)
                    throw std::length_error("Span is full!!!");
                _vect.push_back(*begin);
                ++begin;
            }
        }

    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

};

#endif