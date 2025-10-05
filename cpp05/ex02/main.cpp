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
    try {
        Bureaucrat ahmet("Ahmet", 130);
        ShrubberyCreationForm shrub("home");
        
        std::cout << ahmet << std::endl;
        std::cout << shrub << std::endl;
        
        ahmet.signForm(shrub);
        ahmet.executeForm(shrub);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Bureaucrat mehmet("Mehmet", 40);
        RobotomyRequestForm robot("Bender");

        std::cout << mehmet << std::endl;
        std::cout << robot << std::endl;
        
        mehmet.signForm(robot);
        // Test 50% success rate
        mehmet.executeForm(robot);
        mehmet.executeForm(robot); 
        mehmet.executeForm(robot);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Ahmet Yasin Akyuz");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon("Someone");
        
        std::cout << intern << std::endl;
        std::cout << pardon << std::endl;
        
        intern.signForm(pardon);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("office");
        
        std::cout << boss << std::endl;
        std::cout << shrub << std::endl;
        
        boss.executeForm(shrub);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Bureaucrat mid("Middle", 100);
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Target");
        PresidentialPardonForm pardon("Criminal");
        
        std::cout << "\n--- ShrubberyCreationForm (sign: 145, exec: 137) ---" << std::endl;
        mid.signForm(shrub);
        mid.executeForm(shrub);
        
        std::cout << "\n--- RobotomyRequestForm (sign: 72, exec: 45) ---" << std::endl;
        mid.signForm(robot);
        
        std::cout << "\n--- PresidentialPardonForm (sign: 25, exec: 5) ---" << std::endl;
        mid.signForm(pardon);
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Bureaucrat signer("Signer", 70);
        Bureaucrat executor("Executor", 150);
        RobotomyRequestForm robot("Test Subject");
        
        signer.signForm(robot);
        executor.executeForm(robot);
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
