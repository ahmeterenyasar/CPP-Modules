/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:19:25 by ayasar            #+#    #+#             */
/*   Updated: 2025/11/13 17:19:26 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <iostream>
# include <sstream>
# include <cstdlib>
# include <stdexcept>

class RPN
{
private:
	std::stack<int> _stack;
	
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	
	// Token validation methods
	bool isOperator(const std::string& token) const;
	bool isNumber(const std::string& token) const;
	bool isValidToken(const std::string& token) const;
	bool isSingleDigit(const std::string& token) const;
	bool isNegativeSingleDigit(const std::string& token) const;
	
	// Operator methods
	int performOperation(int a, int b, char op) const;
	int add(int a, int b) const;
	int subtract(int a, int b) const;
	int multiply(int a, int b) const;
	int divide(int a, int b) const;
	
	// Stack operations
	void pushNumber(int number);
	int popNumber();
	bool hasEnoughOperands(size_t required) const;
	bool hasExactlyOneResult() const;
	int getResult();
	
	// Token processing
	void processNumber(const std::string& token);
	void processOperator(const std::string& token);
	void processToken(const std::string& token);
	int convertToNumber(const std::string& token) const;
	
	void validateExpression(const std::string& expression) const;

public:
	RPN();
	~RPN();
	
	int calculate(const std::string& expression);
};

#endif
