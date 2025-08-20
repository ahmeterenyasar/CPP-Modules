#include "replace.hpp"

std::string replaceOccurrences(const std::string& content, const std::string& s1, const std::string& s2) 
{
    
    // Avoid infinite loop if s1 is empty
    if (s1.empty()) 
    {
        return content;
    }
    
    std::string result;
    size_t pos = 0;
    size_t found = 0;

    while ((found = content.find(s1, pos)) != std::string::npos) 
    {
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(content, pos);
    return result;
}