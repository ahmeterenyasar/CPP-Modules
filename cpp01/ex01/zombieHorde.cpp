#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    // Allocate N Zombie objects in a single allocation
    Zombie* horde = new Zombie[N];
    
    // Initialize each zombie with the given name
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    return horde;
}