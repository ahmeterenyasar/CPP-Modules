#include "MutantStack.hpp"
#include <list>
#include <string>

int main()
{
    std::cout << "subject:" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\nstd::list test:" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "\ndifferent types:" << std::endl;
    
    std::cout << "String test:" << std::endl;
    MutantStack<std::string> strStack;
    strStack.push("Ekam");
    strStack.push("Tuzgen");
    strStack.push("-42");
    
    for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
        std::cout << *it << " ";
        
    std::cout << std::endl << std::endl;

    std::cout << "Integer reverse iteration:" << std::endl;
    MutantStack<int> revStack;
    for (int i = 1; i <= 5; i++)
        revStack.push(i);
    
    for (MutantStack<int>::reverse_iterator rit = revStack.rbegin(); rit != revStack.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << std::endl;

    return 0;
}