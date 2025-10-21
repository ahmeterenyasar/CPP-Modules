#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack<T>& operator=(const MutantStack<T>& other);
        ~MutantStack();

        typedef typename std::stack<T>
};

#endif