#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl harl;
    
    std::cout << "=== Harl 2.0 Complaint System ===" << std::endl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("INVALID");
    
    return 0;
}