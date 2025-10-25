#include "RPN.hpp"

RPN::RPN()
{
}

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

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const
{
	if (token.empty())
		return false;
	
	// Check if it's a single digit (0-9) or negative single digit
	if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
		return true;
	
	// check negative single digit
	if (token.length() == 2 && token[0] == '-' && token[1] >= '0' && token[1] <= '9')
		return true;
	
	return false;
}

int RPN::performOperation(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: Division by zero");
			return a / b;
		default:
			throw std::runtime_error("Error: Invalid operator");
	}
}

int RPN::calculate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token)
	{
		if (isNumber(token))
		{
			// Convert string to integer
			int num = std::atoi(token.c_str());
			_stack.push(num);
		}
		else if (isOperator(token))
		{
			// Need at least 2 operands
			if (_stack.size() < 2)
				throw std::runtime_error("Error: Insufficient operands");
			
			// Pop two operands (note the order!)
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			
			// Perform operation and push result
			int result = performOperation(a, b, token[0]);
			_stack.push(result);
		}
		else
		{
			throw std::runtime_error("Error: Invalid token");
		}
	}
	
	// Should have exactly one value left
	if (_stack.size() != 1)
		throw std::runtime_error("Error: Invalid expression");
	
	return _stack.top();
}
