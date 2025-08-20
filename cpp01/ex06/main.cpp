#include "Harl.hpp"
#include <iostream>

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
    std::cout << "I really do!" << std::endl;
    std::cout << std::endl;
}

void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
    std::cout << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
    std::cout << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << std::endl;
}

void Harl::complain( std::string level )
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    // Array of pointers to member functions
    void (Harl::*functions[4])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    // Find the matching level and call the corresponding function
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    
    std::cout << "Unknown level: " << level << std::endl;
}

void Harl::complainFilter( std::string level )
{
    int levelIndex = -1;
    
    // Determine the starting level index
    if (level == "DEBUG")
        levelIndex = 0;
    else if (level == "INFO")
        levelIndex = 1;
    else if (level == "WARNING")
        levelIndex = 2;
    else if (level == "ERROR")
        levelIndex = 3;
    
    // Use switch statement with fall-through to display all levels from the specified level and above
    switch (levelIndex)
    {
        case 0:
            debug();
            // fall through
        case 1:
            info();
            // fall through
        case 2:
            warning();
            // fall through
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}