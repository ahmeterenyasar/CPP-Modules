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

        void multipleAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end);


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