#include "Intern.hpp"
#include <iostream>

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request", 
        "presidential pardon"
    };
    
    AForm* (*formCreators[3])(const std::string&) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };
    
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    
    std::cout << "Error: Form name '" << formName << "' does not exist!" << std::endl;
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found!";
}