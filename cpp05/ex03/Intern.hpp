/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/01 00:00:00 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
    struct FormFactory {
        std::string formName;
        AForm* (*createFunction)(const std::string& target);
    };
    
    static AForm* createShrubberyCreationForm(const std::string& target);
    static AForm* createRobotomyRequestForm(const std::string& target);
    static AForm* createPresidentialPardonForm(const std::string& target);
    
    static const FormFactory _formFactories[3];
    
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    
    AForm* makeForm(const std::string& formName, const std::string& target);
    
    class FormNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif