#include <iostream>
#include <string>
#include "iter.hpp"

// Function templates that can be instantiated
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


// Regular functions
void printInt(int const & n)
{
    std::cout << n << " ";
}

void printString(std::string const & s)
{
    std::cout << s << " ";
}

void toUpperCase(std::string & s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
    }
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
    std::cout << "Read only since const:" << std::endl;

    const int constArray[] = {100, 200, 300};
    size_t constArrayLen = 3;
    
    std::cout << "Const elements: ";
    ::iter(constArray, constArrayLen, printElement<int>);
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
