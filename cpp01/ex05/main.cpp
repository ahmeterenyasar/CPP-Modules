#include "Harl.hpp"
#include <iostream>

int main()
{
    Harl harl;
    
    std::cout << "=== Harl 2.0 Complaint System Test ===" << std::endl << std::endl;
    
    std::cout << "Testing DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    std::cout << "Testing INFO level:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    
    std::cout << "Testing WARNING level:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    
    std::cout << "Testing ERROR level:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    
    std::cout << "Testing invalid level:" << std::endl;
    harl.complain("INVALID");
    std::cout << std::endl;
    
    std::cout << "Testing case sensitivity:" << std::endl;
    harl.complain("debug");
    harl.complain("Info");
    std::cout << std::endl;
    
    std::cout << "Sequential complaints (Harl being Harl):" << std::endl;
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    
    return 0;
}