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

    std::cout << "-----------------------------------" << std::endl;

    try {
        Bureaucrat topBureaucrat("Top", 1);
        Bureaucrat midBureaucrat("Mid", 75);
        Form easyForm("Easy Form", 100, 50);
        Form hardForm("Hard Form", 10, 5);
        
        std::cout << "\nTop bureaucrat attempts:" << std::endl;
        topBureaucrat.signForm(easyForm);
        topBureaucrat.signForm(hardForm);
        
        std::cout << "\nMid bureaucrat attempts:" << std::endl;
        midBureaucrat.signForm(easyForm);
        Form mediumForm("Medium Form", 80, 60);
        midBureaucrat.signForm(mediumForm);
        
        std::cout << "\nFinal form states:" << std::endl;
        std::cout << easyForm << std::endl;
        std::cout << hardForm << std::endl;
        std::cout << mediumForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

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
    return 0;
}