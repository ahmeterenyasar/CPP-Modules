#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\nAddition to subject main, multiple add test" << std::endl;

    try
    {
        Span span = Span(10);
        span.addNumber(5);
        span.addNumber(15);

        // multiple add
        std::vector<int> nums;
        nums.push_back(20);
        nums.push_back(25);
        nums.push_back(30);
        nums.push_back(35);
        nums.push_back(40);

        span.multipleAdd(nums.begin(), nums.end());

        std::cout << "Printing the span ";
        span.print();

        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}