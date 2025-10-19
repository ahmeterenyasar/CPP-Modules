#include <iostream>
#include <string>
#include "iter.hpp"


template <typename T>
void printElement(T const & element)
{
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T & element)
{
    element++;
}






int main(void)
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLen = 5;
    
    std::cout << "Original: ";
    ::iter(intArray, intArrayLen, printElement<int>);
    std::cout << std::endl;
    
    ::iter(intArray, intArrayLen, incrementElement<int>);
    std::cout << "After increment: ";
    ::iter(intArray, intArrayLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "---------------------------------" << std::endl;

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrayLen = 5;
    
    std::cout << "Original: ";
    ::iter(charArray, charArrayLen, printElement<char>);
    std::cout << std::endl;
    
    ::iter(charArray, charArrayLen, incrementElement<char>);
    std::cout << "After increment: ";
    ::iter(charArray, charArrayLen, printElement<char>);
    std::cout << std::endl;

    return 0;
}
