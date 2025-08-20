#include "replace.hpp"

std::string replaceOccurrences(const std::string& content, const std::string& s1, const std::string& s2) {
    if (s1.empty()) {
        return content;  // Avoid infinite loop if s1 is empty
    }
    
    std::string result;
    size_t pos = 0;
    size_t found = 0;
    
    while ((found = content.find(s1, pos)) != std::string::npos) {
        // Append the part before the found occurrence
        result.append(content, pos, found - pos);
        // Append the replacement string
        result.append(s2);
        // Move position past the found occurrence
        pos = found + s1.length();
    }
    
    // Append the remaining part of the string
    result.append(content, pos);
    
    return result;
}