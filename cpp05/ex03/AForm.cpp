/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/01 00:00:00 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _isSigned(false), _signGrade(150), _executeGrade(150), _name("Default AForm") {}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
    : _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade), _name(name) {
    if (signGrade < _highestGrade || executeGrade < _highestGrade) {
        throw GradeTooHighException();
    }
    if (signGrade > _lowestGrade || executeGrade > _lowestGrade) {
        throw GradeTooLowException();
    }
    std::cout << "AForm " << _name << " constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
    : _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade), _name(other._name) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return _name;     
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToExecute() const {
    return _executeGrade;
}

int AForm::getGradeToSign() const {
    return _signGrade;
}

void AForm::beSigned(Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() > _signGrade)
    {
        throw GradeTooHighException();
    }
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!_isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _executeGrade) {
        throw GradeTooHighException();
    }
    executeAction();
}

// Exception implementations
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "AForm " << form.getName() 
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute();
    return out;
}
