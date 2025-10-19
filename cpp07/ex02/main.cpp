#include <iostream>
#include <string>
#include "Array.hpp"
#include <cstdlib>


void basicTests()
{
    std::cout << "\n\nDEFAULT CONSTRUCTOR" << std::endl;
    Array<int> emptyArray;
    std::cout << "Size: " << emptyArray.size() << std::endl;
    
    std::cout << "\nCONSTRUCTOR WITH PARAMETER" << std::endl;
    Array<int> intArray(5);
    std::cout << "Size: " << intArray.size() << std::endl;
    std::cout << "Default initialized values: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << " ";
    }

    
    std::cout << "\nint *a definition from subject" << std::endl;
    int *a = new int();
    std::cout << *a << std::endl;

    std::cout << std::endl;
    
    
    std::cout << "\nCOPY CONSTRUCTOR" << std::endl;
    Array<int> copiedArray(intArray);
    std::cout << "Copied array size: " << copiedArray.size() << std::endl;
    std::cout << "Copied values: ";
    for (unsigned int i = 0; i < copiedArray.size(); i++)
    {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "\nCOPY ASSIGNMENT OPERATOR" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
    std::cout << "Assigned values: ";
    for (unsigned int i = 0; i < assignedArray.size(); i++)
    {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
}

void exceptionTests()
{
    std::cout << "\n\n=== Exception Tests ===" << std::endl;
    Array<int> arr(5);
    
    std::cout << "\nVALID ACCESS" << std::endl;
    try
    {
        arr[0] = 10;
        arr[4] = 50;
        std::cout << "arr[0] = " << arr[0] << std::endl;
        std::cout << "arr[4] = " << arr[4] << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nOUT OF BOUNDS ACCESS" << std::endl;
    try
    {
        arr[10] = 100;
        std::cout << "No exception thrown" << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\nEmpty array access:" << std::endl;
    try
    {
        Array<int> emptyArr;
        emptyArr[0] = 10;
        std::cout << "No exception thrown" << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main()
{
    basicTests();
    exceptionTests();
    return 0;
}
