/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:07:29 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/15 13:22:36 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cmath>
#include <cctype>
#include <cstdlib>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        
        static bool isChar(const std::string& literal);
        static bool isInt(const std::string& literal);
        static bool isFloat(const std::string& literal);
        static bool isDouble(const std::string& literal);
        
        static double parseValue(const std::string& literal, bool& impossible);
        static void printChar(double value, bool impossible);
        static void printInt(double value, bool impossible);
        static void printFloat(double value, bool impossible);
        static void printDouble(double value, bool impossible);
        
    public:
        static void convert(const std::string& literal);
};

#endif