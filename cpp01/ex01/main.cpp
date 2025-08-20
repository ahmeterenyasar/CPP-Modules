#include "Zombie.hpp"

int main() {
    std::cout << "=== Creating a horde of 5 zombies ===" << std::endl;
    int hordeSize = 5;
    Zombie* horde = zombieHorde(hordeSize, "HordeZombie");
    
    std::cout << "\n=== Zombies announcing themselves ===" << std::endl;
    for (int i = 0; i < hordeSize; i++) {
        std::cout << "Zombie " << i << ": ";
        horde[i].announce();
    }
    
    std::cout << "\n=== Destroying the horde ===" << std::endl;
    delete[] horde;
    
    std::cout << "\n=== Testing edge cases ===" << std::endl;

    Zombie* singleZombie = zombieHorde(1, "LoneWolf");
    std::cout << "Single zombie: ";
    singleZombie->announce();
    delete[] singleZombie;

    std::cout << "\nTesting with 0 zombies:" << std::endl;
    if (0 > 0) {
        Zombie* emptyHorde = zombieHorde(0, "Nobody");
        delete[] emptyHorde;
    } else {
        std::cout << "No zombies to create!" << std::endl;
    }
    
    return 0;
}