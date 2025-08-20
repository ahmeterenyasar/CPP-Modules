#include "Zombie.hpp"

int main() 
{
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "HordeZombie");    
    
    if (horde)
    {
        for (int i = 0; i < hordeSize; i++) 
            horde[i].announce();
        delete[] horde;
    }
    else
    {
        std::cout << "Failed to create zombie horde." << std::endl;
    }
    return 0;
}