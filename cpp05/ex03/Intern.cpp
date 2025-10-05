/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/01 00:00:00 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

const Intern::FormFactory Intern::_formFactories[3] = {
    {"shrubbery creation", &Intern::createShrubberyCreationForm},
    {"robotomy request", &Intern::createRobotomyRequestForm},
    {"presidential pardon", &Intern::createPresidentialPardonForm}
};

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    for (int i = 0; i < 3; i++) {
        if (_formFactories[i].formName == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return _formFactories[i].createFunction(target);
        }
    }
    
    std::cout << "Error: Form name '" << formName << "' does not exist!" << std::endl;
    throw FormNotFoundException();
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found!";
}