/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:11:45 by ayasar            #+#    #+#             */
/*   Updated: 2025/09/29 10:21:10 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat();
    ~Bureaucrat();
    Bureaucrat& opeartor=(const Bureaucrat& obj);

    const std::string& getName();
    const int& getGrade();
    void gradeIncrease();
    void gradeDecrase();
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& obj);

#endif