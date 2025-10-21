#include "easyfind.hpp"
#include "iostream"
#include "vector"
#include "deque"
#include "list"

int main()
{
    std::cout << "Testing with Vectors" << std::endl;
    std::vector<int> vect;
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    
    try
    {
        std::vector<int>::iterator iter = easyfind(vect, 3);
        std::cout << "found: " << *iter << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception:" << e.what() << '\n';
    }
    
    std::cout << std::endl;
    std::cout << "Invalid input" << std::endl;

    try
    {
        std::vector<int>::iterator iter = easyfind(vect, 123);
        std::cout << "found: " << *iter << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception:" << e.what() << '\n';
    }

    std::cout << "-------------------------------" << std::endl;

    std::cout << "Testing with List" << std::endl;

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);


    try
    {
        std::list<int>::iterator it = easyfind(lst, 1);
        std::cout << "found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception:" << e.what() << '\n';
    }

    std::cout << "-------------------------------" << std::endl;

    std::cout << "Testing with Deque" << std::endl;

    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 100);
        std::cout << "found: " << *it << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception:" << e.what() << '\n';
    }
    
    std::cout << "-------------------------------" << std::endl;

    std::cout << "Testing Duplicate" << std::endl;
    std::vector<int> dupTest;
    dupTest.push_back(1);
    dupTest.push_back(2);
    dupTest.push_back(3);
    dupTest.push_back(4);
    dupTest.push_back(999999);
    dupTest.push_back(5);
    dupTest.push_back(6);
    dupTest.push_back(7);
    dupTest.push_back(8);
    dupTest.push_back(999999);
    dupTest.push_back(9);

    std::cout << "Printing the list:" << std::endl;

    int i = 0;
    while (dupTest[i])
    {
        std::cout << dupTest[i] << std::endl;
        i++;
    }

    std::cout << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(dupTest, 999999);
        std::cout << "found the first occurance of: " << *it << std::endl;
        std::cout << "PROOF: location -> " << std::distance(dupTest.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception:" << e.what() << '\n';
    }
}