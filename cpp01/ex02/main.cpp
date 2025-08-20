#include <iostream>
#include <string>

int main() {
    // String variable initialized to "HI THIS IS BRAIN"
    std::string brain = "HI THIS IS BRAIN";
    
    // stringPTR: a pointer to the string
    std::string* stringPTR = &brain;
    
    // stringREF: a reference to the string
    std::string& stringREF = brain;
    
    // Print memory addresses
    std::cout << "The memory address of the string variable: " << &brain << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
    
    // Print values
    std::cout << "The value of the string variable: " << brain << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
    
    return 0;
}