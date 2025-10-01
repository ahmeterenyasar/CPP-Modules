/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/01 00:00:00 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 130); // Grade high enough to sign and execute
        ShrubberyCreationForm shrub("home");
        
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        
        bob.signForm(shrub);
        bob.executeForm(shrub);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 40); // Grade high enough to sign and execute
        RobotomyRequestForm robot("Bender");
        
        std::cout << alice << std::endl;
        std::cout << robot << std::endl;
        
        alice.signForm(robot);
        alice.executeForm(robot);
        alice.executeForm(robot); // Test 50% success rate
        alice.executeForm(robot);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing Grade Too Low Exceptions ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Someone");
        
        std::cout << intern << std::endl;
        std::cout << pardon << std::endl;
        
        intern.signForm(pardon); // Should fail - grade too low to sign
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing Execution Without Signing ===" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("office");
        
        std::cout << boss << std::endl;
        std::cout << shrub << std::endl;
        
        boss.executeForm(shrub); // Should fail - form not signed
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing Different Grade Requirements ===" << std::endl;
    try {
        Bureaucrat mid("Middle", 100);
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Target");
        PresidentialPardonForm pardon("Criminal");
        
        std::cout << "\n--- ShrubberyCreationForm (sign: 145, exec: 137) ---" << std::endl;
        mid.signForm(shrub);
        mid.executeForm(shrub);
        
        std::cout << "\n--- RobotomyRequestForm (sign: 72, exec: 45) ---" << std::endl;
        mid.signForm(robot); // Should fail - grade 100 > 72
        
        std::cout << "\n--- PresidentialPardonForm (sign: 25, exec: 5) ---" << std::endl;
        mid.signForm(pardon); // Should fail - grade 100 > 25
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing Execution Grade Too Low ===" << std::endl;
    try {
        Bureaucrat signer("Signer", 70); // Can sign robotomy but not execute
        Bureaucrat executor("Executor", 150); // Cannot execute
        RobotomyRequestForm robot("Test Subject");
        
        signer.signForm(robot); // Should succeed
        executor.executeForm(robot); // Should fail - grade too low to execute
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
