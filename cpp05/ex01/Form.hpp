
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;
    const std::string _name;

public:
    Form();
    Form(const std::string name, int signGrade, int executeGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    const bool getIsSigned() const;
    const int getGradeToExecute() const;
    const int getGradeToSign() const;

    void beSigned(Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
