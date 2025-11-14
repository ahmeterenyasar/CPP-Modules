/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:19:16 by ayasar            #+#    #+#             */
/*   Updated: 2025/11/13 17:19:17 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isSingleDigit(const std::string& token) const
{
	return (token.length() == 1 && token[0] >= '0' && token[0] <= '9');
}

bool RPN::isNegativeSingleDigit(const std::string& token) const
{
	return (token.length() == 2 && token[0] == '-' && token[1] >= '0' && token[1] <= '9');
}

bool RPN::isNumber(const std::string& token) const
{
	if (token.empty())
		return false;
	
	return (isSingleDigit(token) || isNegativeSingleDigit(token));
}

bool RPN::isValidToken(const std::string& token) const
{
	return (isNumber(token) || isOperator(token));
}

int RPN::add(int a, int b) const
{
	return a + b;
}

int RPN::subtract(int a, int b) const
{
	return a - b;
}

int RPN::multiply(int a, int b) const
{
	return a * b;
}

int RPN::divide(int a, int b) const
{
	if (b == 0)
		throw std::runtime_error("Error");
	return a / b;
}

int RPN::performOperation(int a, int b, char op) const
{
	switch (op)
	{
		case '+':
			return add(a, b);
		case '-':
			return subtract(a, b);
		case '*':
			return multiply(a, b);
		case '/':
			return divide(a, b);
		default:
			throw std::runtime_error("Error");
	}
}

void RPN::pushNumber(int number)
{
	_stack.push(number);
}

int RPN::popNumber()
{
	if (_stack.empty())
		throw std::runtime_error("Error");
	
	int value = _stack.top();
	_stack.pop();
	return value;
}

bool RPN::hasEnoughOperands(size_t required) const
{
	return _stack.size() >= required;
}

bool RPN::hasExactlyOneResult() const
{
	return _stack.size() == 1;
}

int RPN::getResult()
{
	if (!hasExactlyOneResult())
		throw std::runtime_error("Error");
	
	return _stack.top();
}

int RPN::convertToNumber(const std::string& token) const
{
	return std::atoi(token.c_str());
}

void RPN::processNumber(const std::string& token)
{
	int number = convertToNumber(token);
	pushNumber(number);
}

void RPN::processOperator(const std::string& token)
{
	if (!hasEnoughOperands(2))
		throw std::runtime_error("Error");
	
	int b = popNumber();
	int a = popNumber();
	
	int result = performOperation(a, b, token[0]);
	pushNumber(result);
}

void RPN::processToken(const std::string& token)
{
	if (!isValidToken(token))
		throw std::runtime_error("Error");
	
	if (isNumber(token))
		processNumber(token);
	else if (isOperator(token))
		processOperator(token);
}

void RPN::validateExpression(const std::string& expression) const
{
	if (expression.empty())
		throw std::runtime_error("Error");
}

int RPN::calculate(const std::string& expression)
{
	validateExpression(expression);
	
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token)
	{
		processToken(token);
	}
	
	return getResult();
}
