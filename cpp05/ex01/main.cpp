#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Form formA("Form A", 50, 25);
        std::cout << formA << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Form invalidForm("Invalid", 0, 50);
        std::cout << invalidForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;

    try {
        Form invalidForm("Invalid", 50, 151);
        std::cout << invalidForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Bureaucrat ahmet("Ahmet", 30);
        Form formB("Form B", 50, 25);
        std::cout << ahmet << std::endl;
        std::cout << formB << std::endl;
        ahmet.signForm(formB);
        std::cout << formB << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat mehmet("Mehmet", 100);
        Form formC("Form C", 50, 25);
        std::cout << mehmet << std::endl;
        std::cout << formC << std::endl;
        mehmet.signForm(formC);
        std::cout << formC << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat ayse("Ayse", 50);
        Form formD("Form D", 50, 25);
        std::cout << ayse << std::endl;
        std::cout << formD << std::endl;
        ayse.signForm(formD);
        std::cout << formD << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}