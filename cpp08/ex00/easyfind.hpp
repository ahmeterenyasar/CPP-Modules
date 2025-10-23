#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Element not found!";
        }
};

template<typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator iter = std::find(container.begin(), container.end(), value);
    if (iter == container.end())
        throw NotFoundException();
    return iter;
}


#endif