/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:17:43 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/10 18:17:47 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form() : _isSigned(false), _signGrade(150), _executeGrade(150), _name("Default Form") {}

Form::Form(const std::string& name, int signGrade, int executeGrade)
    : _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade), _name(name) {
    if (signGrade < _highestGrade || executeGrade < _highestGrade) {
        throw GradeTooHighException();
    }
    if (signGrade > _lowestGrade || executeGrade > _lowestGrade) {
        throw GradeTooLowException();
    }
    std::cout << "Form " << _name << " constructor called" << std::endl;
}

Form::Form(const Form& other)
    : _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade), _name(other._name) {}

Form& Form::operator=(const Form& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return _name;     
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeToExecute() const {
    return _executeGrade;
}

int Form::getGradeToSign() const {
    return _signGrade;
}

void Form::beSigned(Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() > _signGrade)
    {
        throw GradeTooHighException();
    }
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form " << form.getName() 
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", grade required to sign: " << form.getGradeToSign()
        << ", grade required to execute: " << form.getGradeToExecute();
    return out;
}