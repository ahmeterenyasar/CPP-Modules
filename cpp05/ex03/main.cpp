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
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Intern makeForm() ===" << std::endl;
    
    try {
        Intern someRandomIntern;
        Bureaucrat president("President", 1);
        AForm* form;
        
        std::cout << "\n--- Creating Robotomy Request Form ---" << std::endl;
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form) {
            std::cout << *form << std::endl;
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
        
        std::cout << "\n--- Creating Shrubbery Creation Form ---" << std::endl;
        form = someRandomIntern.makeForm("shrubbery creation", "home");
        if (form) {
            std::cout << *form << std::endl;
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
        
        std::cout << "\n--- Creating Presidential Pardon Form ---" << std::endl;
        form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (form) {
            std::cout << *form << std::endl;
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing Invalid Form Name ===" << std::endl;
    try {
        Intern intern;
        AForm* invalidForm = intern.makeForm("invalid form", "target");
        if (invalidForm) {
            delete invalidForm;
        }
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing Multiple Interns ===" << std::endl;
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
    
    std::cout << "\n=== Testing Case Sensitivity ===" << std::endl;
    try {
        Intern intern;
        AForm* form;
        
        // Test exact case
        form = intern.makeForm("robotomy request", "Test1");
        if (form) {
            std::cout << "Exact case worked: " << *form << std::endl;
            delete form;
        }
        
        // Test different case (should fail)
        form = intern.makeForm("Robotomy Request", "Test2");
        if (form) {
            delete form;
        }
        
    } catch (std::exception& e) {
        std::cout << "Case sensitivity test - Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Testing Copy Constructor and Assignment ===" << std::endl;
    try {
        Intern original;
        Intern copy(original);
        Intern assigned;
        assigned = original;
        
        AForm* form1 = original.makeForm("shrubbery creation", "original");
        AForm* form2 = copy.makeForm("shrubbery creation", "copy");
        AForm* form3 = assigned.makeForm("shrubbery creation", "assigned");
        
        if (form1) delete form1;
        if (form2) delete form2;
        if (form3) delete form3;
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
