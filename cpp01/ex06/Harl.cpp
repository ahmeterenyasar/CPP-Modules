#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./harlFilter <level>" << std::endl;
        std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }
    
    Harl harl;
    harl.complainFilter(argv[1]);
    
    return 0;
}