#include "ScalarConverter.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 13:07:27 by ayasar            #+#    #+#             */
/*   Updated: 2025/10/12 13:07:28 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    bool impossible = false;
    double value = parseValue(literal, impossible);
    
    printChar(value, impossible);
    printInt(value, impossible);
    printFloat(value, impossible);
    printDouble(value, impossible);
}

bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty()) return false;
    
    int start = 0;
    if (literal[0] == '+' || literal[0] == '-') start = 1;
    
    for (int i = start; i < (int)literal.length(); i++) {
        if (!std::isdigit(literal[i])) return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") return true;
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f') return false;
    
    std::string temp = literal.substr(0, literal.length() - 1);
    bool hasDot = false;
    int start = 0;
    
    if (temp[0] == '+' || temp[0] == '-') start = 1;
    
    for (int i = start; i < (int)temp.length(); i++) {
        if (temp[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(temp[i])) {
            return false;
        }
    }
    return hasDot;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan") return true;
    
    bool hasDot = false;
    int start = 0;
    
    if (literal[0] == '+' || literal[0] == '-') start = 1;
    
    for (int i = start; i < (int)literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    return hasDot;
}

double ScalarConverter::parseValue(const std::string& literal, bool& impossible) {
    impossible = false;
    
    if (isChar(literal)) {
        return static_cast<double>(literal[1]);
    }
    
    if (isInt(literal)) {
        char* endptr;
        double value = std::strtod(literal.c_str(), &endptr);
        if (*endptr != '\0' || std::isinf(value)) {
            impossible = true;
            return value;
        }
        return value;
    }
    
    if (isFloat(literal)) {
        if (literal == "-inff") return -std::numeric_limits<double>::infinity();
        if (literal == "+inff") return std::numeric_limits<double>::infinity();
        if (literal == "nanf") return std::numeric_limits<double>::quiet_NaN();
        
        char* endptr;
        double value = std::strtod(literal.c_str(), &endptr);
        return value;
    }
    
    if (isDouble(literal)) {
        if (literal == "-inf") return -std::numeric_limits<double>::infinity();
        if (literal == "+inf") return std::numeric_limits<double>::infinity();
        if (literal == "nan") return std::numeric_limits<double>::quiet_NaN();
        
        char* endptr;
        double value = std::strtod(literal.c_str(), &endptr);
        return value;
    }
    
    impossible = true;
    return 0.0;
}

void ScalarConverter::printChar(double value, bool impossible) {
    std::cout << "char: ";
    
    if (impossible || std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible";
    } else if (value >= 0 && value <= 127 && value == static_cast<int>(value)) {
        if (std::isprint(static_cast<int>(value))) {
            std::cout << "'" << static_cast<char>(value) << "'";
        } else {
            std::cout << "Non displayable";
        }
    } else {
        std::cout << "impossible";
    }
    std::cout << std::endl;
}

void ScalarConverter::printInt(double value, bool impossible) {
    std::cout << "int: ";
    
    if (impossible || std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<int>::min() || 
        value > std::numeric_limits<int>::max() ||
        value != static_cast<int>(value)) {
        std::cout << "impossible";
    } else {
        std::cout << static_cast<int>(value);
    }
    std::cout << std::endl;
}

void ScalarConverter::printFloat(double value, bool impossible) {
    std::cout << "float: ";
    
    if (impossible && !std::isnan(value) && !std::isinf(value)) {
        std::cout << "impossible";
    } else if (std::isnan(value)) {
        std::cout << "nanf";
    } else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "+inff";
        } else {
            std::cout << "-inff";
        }
    } else {
        float floatValue = static_cast<float>(value);
        if (std::isinf(floatValue)) {
            if (value > 0) {
                std::cout << "+inff";
            } else {
                std::cout << "-inff";
            }
        } else {
            std::cout << floatValue;
            if (floatValue == static_cast<int>(floatValue)) {
                std::cout << ".0";
            }
            std::cout << "f";
        }
    }
    std::cout << std::endl;
}

void ScalarConverter::printDouble(double value, bool impossible) {
    std::cout << "double: ";
    
    if (impossible && !std::isnan(value) && !std::isinf(value)) {
        std::cout << "impossible";
    } else if (std::isnan(value)) {
        std::cout << "nan";
    } else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "+inf";
        } else {
            std::cout << "-inf";
        }
    } else {
        std::cout << value;
        if (value == static_cast<int>(value)) {
            std::cout << ".0";
        }
    }
    std::cout << std::endl;
}