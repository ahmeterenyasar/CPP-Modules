#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

void basicTests()
{
    std::cout << "=== Basic Tests ===" << std::endl;
    
    // Test 1: Default constructor
    std::cout << "\n1. Default constructor (empty array):" << std::endl;
    Array<int> emptyArray;
    std::cout << "   Size: " << emptyArray.size() << std::endl;
    
    // Test 2: Constructor with size
    std::cout << "\n2. Constructor with size (5 elements):" << std::endl;
    Array<int> intArray(5);
    std::cout << "   Size: " << intArray.size() << std::endl;
    std::cout << "   Default initialized values: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test 3: Modifying elements
    std::cout << "\n3. Modifying elements:" << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i * 10;
    }
    std::cout << "   Modified values: ";
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test 4: Copy constructor
    std::cout << "\n4. Copy constructor:" << std::endl;
    Array<int> copiedArray(intArray);
    std::cout << "   Copied array size: " << copiedArray.size() << std::endl;
    std::cout << "   Copied values: ";
    for (unsigned int i = 0; i < copiedArray.size(); i++)
    {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test 5: Deep copy verification
    std::cout << "\n5. Deep copy verification (modifying original):" << std::endl;
    intArray[0] = 999;
    std::cout << "   Original array[0]: " << intArray[0] << std::endl;
    std::cout << "   Copied array[0]: " << copiedArray[0] << std::endl;
    std::cout << "   Arrays are independent: " << (intArray[0] != copiedArray[0] ? "YES" : "NO") << std::endl;
    
    // Test 6: Assignment operator
    std::cout << "\n6. Assignment operator:" << std::endl;
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "   Assigned array size: " << assignedArray.size() << std::endl;
    std::cout << "   Assigned values: ";
    for (unsigned int i = 0; i < assignedArray.size(); i++)
    {
        std::cout << assignedArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test 7: Deep copy verification for assignment
    std::cout << "\n7. Deep copy verification for assignment:" << std::endl;
    intArray[1] = 888;
    std::cout << "   Original array[1]: " << intArray[1] << std::endl;
    std::cout << "   Assigned array[1]: " << assignedArray[1] << std::endl;
    std::cout << "   Arrays are independent: " << (intArray[1] != assignedArray[1] ? "YES" : "NO") << std::endl;
}

void exceptionTests()
{
    std::cout << "\n\n=== Exception Tests ===" << std::endl;
    
    Array<int> arr(5);
    
    // Test 1: Valid access
    std::cout << "\n1. Valid access (index 0-4):" << std::endl;
    try
    {
        arr[0] = 10;
        arr[4] = 50;
        std::cout << "   arr[0] = " << arr[0] << std::endl;
        std::cout << "   arr[4] = " << arr[4] << std::endl;
        std::cout << "   Success!" << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "   Exception: " << e.what() << std::endl;
    }
    
    // Test 2: Out of bounds access
    std::cout << "\n2. Out of bounds access (index 5):" << std::endl;
    try
    {
        std::cout << "   Trying to access arr[5]..." << std::endl;
        arr[5] = 100;
        std::cout << "   No exception thrown (ERROR!)" << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "   Exception caught: " << e.what() << std::endl;
    }
    
    // Test 3: Negative index (will wrap around due to unsigned int)
    std::cout << "\n3. Out of bounds access (large index):" << std::endl;
    try
    {
        std::cout << "   Trying to access arr[1000]..." << std::endl;
        arr[1000] = 100;
        std::cout << "   No exception thrown (ERROR!)" << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "   Exception caught: " << e.what() << std::endl;
    }
    
    // Test 4: Empty array access
    std::cout << "\n4. Empty array access:" << std::endl;
    try
    {
        Array<int> emptyArr;
        std::cout << "   Trying to access emptyArr[0]..." << std::endl;
        emptyArr[0] = 10;
        std::cout << "   No exception thrown (ERROR!)" << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "   Exception caught: " << e.what() << std::endl;
    }
}

void typeTests()
{
    std::cout << "\n\n=== Different Type Tests ===" << std::endl;
    
    // Test 1: String array
    std::cout << "\n1. String array:" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";
    std::cout << "   Elements: ";
    for (unsigned int i = 0; i < strArray.size(); i++)
    {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test 2: Float array
    std::cout << "\n2. Float array:" << std::endl;
    Array<float> floatArray(4);
    for (unsigned int i = 0; i < floatArray.size(); i++)
    {
        floatArray[i] = i * 1.5f;
    }
    std::cout << "   Elements: ";
    for (unsigned int i = 0; i < floatArray.size(); i++)
    {
        std::cout << floatArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Test 3: Character array
    std::cout << "\n3. Character array:" << std::endl;
    Array<char> charArray(5);
    for (unsigned int i = 0; i < charArray.size(); i++)
    {
        charArray[i] = 'A' + i;
    }
    std::cout << "   Elements: ";
    for (unsigned int i = 0; i < charArray.size(); i++)
    {
        std::cout << charArray[i] << " ";
    }
    std::cout << std::endl;
}

void subjectTest()
{
    std::cout << "\n\n=== Subject Test (from PDF) ===" << std::endl;
    
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete[] mirror;
            return;
        }
    }
    
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    
    delete[] mirror;
    
    std::cout << "All tests passed successfully!" << std::endl;
}

int main()
{
    basicTests();
    exceptionTests();
    typeTests();
    subjectTest();
    
    return 0;
}
