#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <iostream>
# include <sstream>
# include <cstdlib>

class RPN
{
private:
	std::stack<int> _stack;
	
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	
	bool isOperator(const std::string& token) const;
	bool isNumber(const std::string& token) const;
	int performOperation(int a, int b, char op);

public:
	RPN();
	~RPN();
	
	int calculate(const std::string& expression);
};

#endif
