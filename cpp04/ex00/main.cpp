#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Basic Tests from Subject ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== Wrong Classes ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // Will output WrongAnimal sound, not WrongCat!
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n=== Additional ===" << std::endl;
    
    // Test 1: Stack allocation
    std::cout << "\n--- Stack Allocation Test ---" << std::endl;
    Animal animal;
    Dog dog;
    Cat cat;
    
    animal.makeSound();
    dog.makeSound();
    cat.makeSound();
    
    // Test 2: Array of Animal pointers
    std::cout << "\n--- Array of Animal Pointers Test ---" << std::endl;
    Animal* animals[4];
    animals[0] = new Animal();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Dog();
    
    for (int k = 0; k < 4; k++) {
        std::cout << "animals[" << k << "] type: " << animals[k]->getType() 
                  << " sound: ";
        animals[k]->makeSound();
    }
    
    for (int k = 0; k < 4; k++) {
        delete animals[k];
    }
    
    // Test 3: Copy constructor and assignment
    std::cout << "\n--- Copy Constructor and Assignment Test ---" << std::endl;
    Dog originalDog;
    Dog copiedDog(originalDog);
    Dog assignedDog;
    assignedDog = originalDog;
    
    std::cout << "Original dog: ";
    originalDog.makeSound();
    std::cout << "Copied dog: ";
    copiedDog.makeSound();
    std::cout << "Assigned dog: ";
    assignedDog.makeSound();
    
    // Test 4: Polymorphism through function parameter
    std::cout << "\n--- Function Parameter Test ---" << std::endl;
    
    Animal baseAnimal;
    Dog testDog;
    Cat testCat;
    
    std::cout << "Animal type: " << baseAnimal.getType() << ", sound: ";
    baseAnimal.makeSound();
    std::cout << "Animal type: " << testDog.getType() << ", sound: ";
    testDog.makeSound();
    std::cout << "Animal type: " << testCat.getType() << ", sound: ";
    testCat.makeSound();
    
    // Test 5: Wrong classes with direct instantiation
    std::cout << "\n--- Wrong Classes Direct Instantiation Test ---" << std::endl;
    WrongAnimal wrongAnimal;
    WrongCat wrongCatDirect;
    
    std::cout << "WrongAnimal direct: ";
    wrongAnimal.makeSound();
    std::cout << "WrongCat direct: ";
    wrongCatDirect.makeSound();
    
    return 0;
}