#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <sstream>

std::string intToString(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
}

int main() {
    std::cout << "=== Basic Tests from Subject ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    
    delete j; // should not create a leak
    delete i;
    
    std::cout << "\n=== Array of Animals Test (Half Dogs, Half Cats) ===" << std::endl;
    const int arraySize = 10;
    Animal* animals[arraySize];
    
    // Fill half with Dogs, half with Cats
    for (int k = 0; k < arraySize; k++) {
        if (k < arraySize / 2) {
            animals[k] = new Dog();
            std::cout << "Created Dog " << k << std::endl;
        } else {
            animals[k] = new Cat();
            std::cout << "Created Cat " << k << std::endl;
        }
    }
    
    std::cout << "\n--- Testing polymorphism ---" << std::endl;
    for (int k = 0; k < arraySize; k++) {
        std::cout << "Animal[" << k << "] type: " << animals[k]->getType() << " - ";
        animals[k]->makeSound();
    }
    
    std::cout << "\n--- Deleting all animals ---" << std::endl;
    for (int k = 0; k < arraySize; k++) {
        std::cout << "Deleting animal " << k << " (" << animals[k]->getType() << ")" << std::endl;
        delete animals[k]; // Delete as Animals - must call proper destructors
    }
    
    std::cout << "\n=== Deep Copy ===" << std::endl;
    
    // Test Dog deep copy
    std::cout << "\n--- Dog Deep Copy Test ---" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "I love bones!");
    originalDog->getBrain()->setIdea(1, "Squirrel!");
    originalDog->getBrain()->setIdea(2, "Walk time!");
    
    std::cout << "Original dog ideas:" << std::endl;
    for (int k = 0; k < 3; k++) {
        std::cout << "  Idea " << k << ": " << originalDog->getBrain()->getIdea(k) << std::endl;
    }
    
    // Copy constructor test
    Dog copiedDog(*originalDog);
    std::cout << "\nCopied dog ideas (should be same):" << std::endl;
    for (int k = 0; k < 3; k++) {
        std::cout << "  Idea " << k << ": " << copiedDog.getBrain()->getIdea(k) << std::endl;
    }
    
    // Modify original dog's brain
    originalDog->getBrain()->setIdea(0, "Modified idea!");
    std::cout << "\nAfter modifying original dog's first idea:" << std::endl;
    std::cout << "Original dog idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied dog idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    
    if (originalDog->getBrain()->getIdea(0) != copiedDog.getBrain()->getIdea(0)) {
        std::cout << "✓ Deep copy successful! Ideas are independent." << std::endl;
    } else {
        std::cout << "✗ Shallow copy detected! Ideas are shared." << std::endl;
    }
    
    // Test Cat deep copy
    std::cout << "\n--- Cat Deep Copy Test ---" << std::endl;
    Cat* originalCat = new Cat();
    originalCat->getBrain()->setIdea(0, "I love fish!");
    originalCat->getBrain()->setIdea(1, "Yarn ball!");
    originalCat->getBrain()->setIdea(2, "Nap time!");
    
    // Assignment operator test
    Cat assignedCat;
    assignedCat = *originalCat;
    
    std::cout << "Original cat ideas:" << std::endl;
    for (int k = 0; k < 3; k++) {
        std::cout << "  Idea " << k << ": " << originalCat->getBrain()->getIdea(k) << std::endl;
    }
    
    std::cout << "\nAssigned cat ideas (should be same):" << std::endl;
    for (int k = 0; k < 3; k++) {
        std::cout << "  Idea " << k << ": " << assignedCat.getBrain()->getIdea(k) << std::endl;
    }
    
    // Modify original cat's brain
    originalCat->getBrain()->setIdea(1, "Modified cat idea!");
    std::cout << "\nAfter modifying original cat's second idea:" << std::endl;
    std::cout << "Original cat idea 1: " << originalCat->getBrain()->getIdea(1) << std::endl;
    std::cout << "Assigned cat idea 1: " << assignedCat.getBrain()->getIdea(1) << std::endl;
    
    if (originalCat->getBrain()->getIdea(1) != assignedCat.getBrain()->getIdea(1)) {
        std::cout << "✓ Deep copy successful! Ideas are independent." << std::endl;
    } else {
        std::cout << "✗ Shallow copy detected! Ideas are shared." << std::endl;
    }
    
    delete originalDog;
    delete originalCat;
    
    std::cout << "\n=== Brain Pointer Comparison ===" << std::endl;
    Dog dog1;
    Dog dog2(dog1);
    
    if (dog1.getBrain() != dog2.getBrain()) {
        std::cout << "✓ Different Brain pointers - Deep copy confirmed!" << std::endl;
        std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
        std::cout << "Dog2 brain address: " << dog2.getBrain() << std::endl;
    } else {
        std::cout << "✗ Same Brain pointers - Shallow copy detected!" << std::endl;
    }
    
    std::cout << "\n=== Wrong Classes Test (No virtual) ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // Will output WrongAnimal sound, not WrongCat!
    wrongMeta->makeSound();
    
    delete wrongMeta;
    delete wrongCat;
    
    std::cout << "\n=== Memory Management ===" << std::endl;
    std::cout << "Creating and destroying multiple animals to test for leaks..." << std::endl;
    
    for (int k = 0; k < 5; k++) {
        Animal* testDog = new Dog();
        Animal* testCat = new Cat();
        
        std::cout << "Created " << testDog->getType() << " and " << testCat->getType() << std::endl;
        
        delete testDog;
        delete testCat;
        
        std::cout << "Deleted both animals" << std::endl;
    }
    
    std::cout << "\n=== Brain Ideas Capacity ===" << std::endl;
    Dog smartDog;
    std::cout << "Setting 100 ideas in dog's brain..." << std::endl;
    
    for (int k = 0; k < 100; k++) {
        std::string idea = "Idea number " + intToString(k);
        smartDog.getBrain()->setIdea(k, idea);
    }
    
    std::cout << "First 5 ideas:" << std::endl;
    for (int k = 0; k < 5; k++) {
        std::cout << "  " << smartDog.getBrain()->getIdea(k) << std::endl;
    }
    
    std::cout << "Last 5 ideas:" << std::endl;
    for (int k = 95; k < 100; k++) {
        std::cout << "  " << smartDog.getBrain()->getIdea(k) << std::endl;
    }
    
    std::cout << "\n=== Program completed successfully ===" << std::endl;
    
    return 0;
}