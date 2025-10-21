#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other)
    {
        this->_N = other._N;
        this->_vect = other._vect;
    }
    return (*this);
}

void Span::addNumber(int num) {
    if (this->_vect.size() >= this->_N)
        throw std::out_of_range("Span is full!!!");
    if (this->_vect.size() < this->_N)
        this->_vect.push_back(num);
}

int Span::shortestSpan() {
    if (_vect.empty() || _vect.size() == 1)
        throw std::out_of_range("Vector has less then 2 values");
    
    std::vector<int> sorted = _vect;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < _vect.size() - 1; i++)
    {
        int tempSpan = sorted[i + 1] - sorted[i];
        if (tempSpan < minSpan)
            minSpan = tempSpan;
    }
    return minSpan;
}

int Span::longestSpan() {
    if (_vect.empty() || _vect.size() == 1)
        throw std::out_of_range("Vector has less then 2 elements!!!");
        std::vector<int>::const_iterator maxIter = std::max_element(_vect.begin(), _vect.end());
        std::vector<int>::const_iterator minIter = std::min_element(_vect.begin(), _vect.end());
        return(*maxIter - *minIter);
}

void Span::multipleAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vect.size() + std::distance(begin, end) > this->_N)
		throw std::out_of_range("ERROR : Range Filling would outgrow the Span instance");
	this->_vect.insert(_vect.begin(), begin, end);
}