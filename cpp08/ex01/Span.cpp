#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(const Span& other) {
    *this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _N = other._N;
        _vect = other._vect;
    }
    return *this;
}

void Span::addNumber(int num) {
    if (_vect.size() >= _N)
        throw std::out_of_range("Span is full!");
    _vect.push_back(num);
}


int Span::shortestSpan() {
    if (_vect.empty() || _vect.size() < 2)
        throw std::out_of_range("Vector has less than 2 values");

    std::vector<int> sorted = _vect;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}


int Span::longestSpan() {
    if (_vect.empty() || _vect.size() < 2)
        throw std::out_of_range("Vector has less than 2 elements!!!");
    std::vector<int>::const_iterator maxIter = std::max_element(_vect.begin(), _vect.end());
    std::vector<int>::const_iterator minIter = std::min_element(_vect.begin(), _vect.end());
    return(*maxIter - *minIter);
}

void Span::multipleAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_vect.size() + std::distance(begin, end) > this->_N)
		throw std::out_of_range("ERROR : Range Filling would outgrow the Span instance");
	this->_vect.insert(_vect.end(), begin, end);
}

void Span::print() const
{
    std::cout << "[ ";
    for (std::vector<int>::const_iterator it = _vect.begin(); it != _vect.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << std::endl;
}
