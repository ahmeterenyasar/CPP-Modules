
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

class Form {
private:
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;
    const std::string _name;

public:
    Form();
    ~Form();

    std::string &getName() const;
    bool getIsSigned() const;
    int getGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);

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
