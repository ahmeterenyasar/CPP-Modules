/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:20:47 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/10 18:20:49 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    try {
        Intern intern;
        Bureaucrat president("President", 1);
        AForm* form;
        
        std::cout << "\n--- Creating Robotomy Request Form ---" << std::endl;
        form = intern.makeForm("robotomy request", "Bender");
        if (form) {
            std::cout << *form << std::endl;
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
        
        std::cout << "\n--- Creating Shrubbery Creation Form ---" << std::endl;
        form = intern.makeForm("shrubbery creation", "home");
        if (form) {
            std::cout << *form << std::endl;
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
        
        std::cout << "\n--- Creating Presidential Pardon Form ---" << std::endl;
        form = intern.makeForm("presidential pardon", "Ahmet Yasin Akyüz");
        if (form) {
            std::cout << *form << std::endl;
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;

    try {
        Intern intern;
        AForm* invalidForm = intern.makeForm("invalid form", "target");
        if (invalidForm) {
            delete invalidForm;
        }
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Intern intern1;
        Intern intern2;
        Bureaucrat manager("Manager", 40);
        
        AForm* form1 = intern1.makeForm("robotomy request", "Employee1");
        AForm* form2 = intern2.makeForm("robotomy request", "Employee2");
        
        if (form1 && form2) {
            std::cout << "\nFirst form: " << *form1 << std::endl;
            std::cout << "Second form: " << *form2 << std::endl;
            
            manager.signForm(*form1);
            manager.signForm(*form2);
            
            manager.executeForm(*form1);
            manager.executeForm(*form2);
            
            delete form1;
            delete form2;
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "-----------------------------------" << std::endl;
    
    try {
        Intern intern;
        AForm* form;
        form = intern.makeForm("robotomy request", "Test1");
        if (form) {
            std::cout << "Exact case worked: " << *form << std::endl;
            delete form;
        }
        
        form = intern.makeForm("Robotomy Request", "Test2");
        if (form) {
            delete form;
        }
        
    } catch (std::exception& e) {
        std::cout << "Case sensitivity test - Exception: " << e.what() << std::endl;
    }
    return 0;
}
