/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 00:00:00 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/01 00:00:00 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
protected:
    bool _isSigned;
    const int _signGrade;
    const int _executeGrade;
    const std::string _name;
    static const int _highestGrade = 1;
    static const int _lowestGrade = 150;

public:
    AForm();
    AForm(const std::string& name, int signGrade, int executeGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool getIsSigned() const;
    int getGradeToExecute() const;
    int getGradeToSign() const;

    void beSigned(Bureaucrat& bureaucrat);
    void execute(Bureaucrat const & executor) const;
    virtual void executeAction() const = 0;

    // LOOK public kavramını silince de çalışıyor neden var o zaman?
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

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
