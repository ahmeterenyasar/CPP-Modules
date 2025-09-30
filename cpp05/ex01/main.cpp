#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Valid form creation ===" << std::endl;
    try {
        Form formA("Form A", 50, 25);
        std::cout << formA << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Form with grade too high (0) ===" << std::endl;
    try {
        Form invalidForm("Invalid", 0, 50);
        std::cout << invalidForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Form with grade too low (151) ===" << std::endl;
    try {
        Form invalidForm("Invalid", 50, 151);
        std::cout << invalidForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Bureaucrat successfully signs form ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 30);
        Form formB("Form B", 50, 25);
        std::cout << alice << std::endl;
        std::cout << formB << std::endl;
        alice.signForm(formB);
        std::cout << formB << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Bureaucrat fails to sign (grade too low) ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form formC("Form C", 50, 25);
        std::cout << bob << std::endl;
        std::cout << formC << std::endl;
        bob.signForm(formC);
        std::cout << formC << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Edge case - bureaucrat grade equals required grade ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 50);
        Form formD("Form D", 50, 25);
        std::cout << charlie << std::endl;
        std::cout << formD << std::endl;
        charlie.signForm(formD);
        std::cout << formD << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Multiple bureaucrats signing different forms ===" << std::endl;
    try {
        Bureaucrat topBureaucrat("Top", 1);
        Bureaucrat midBureaucrat("Mid", 75);
        Form easyForm("Easy Form", 100, 50);
        Form hardForm("Hard Form", 10, 5);
        
        std::cout << "\nTop bureaucrat attempts:" << std::endl;
        topBureaucrat.signForm(easyForm);
        topBureaucrat.signForm(hardForm);
        
        std::cout << "\nMid bureaucrat attempts:" << std::endl;
        midBureaucrat.signForm(easyForm); // Already signed
        // Create a new form for mid bureaucrat
        Form mediumForm("Medium Form", 80, 60);
        midBureaucrat.signForm(mediumForm);
        
        std::cout << "\nFinal form states:" << std::endl;
        std::cout << easyForm << std::endl;
        std::cout << hardForm << std::endl;
        std::cout << mediumForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Form with highest and lowest grades ===" << std::endl;
    try {
        Form maxSecurityForm("Max Security", 1, 1);
        Form minSecurityForm("Min Security", 150, 150);
        
        Bureaucrat ceo("CEO", 1);
        Bureaucrat intern("Intern", 150);
        
        std::cout << "\nCEO signing max security form:" << std::endl;
        ceo.signForm(maxSecurityForm);
        
        std::cout << "\nIntern signing min security form:" << std::endl;
        intern.signForm(minSecurityForm);
        
        std::cout << "\nIntern trying max security form:" << std::endl;
        intern.signForm(maxSecurityForm);
        
        std::cout << maxSecurityForm << std::endl;
        std::cout << minSecurityForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}