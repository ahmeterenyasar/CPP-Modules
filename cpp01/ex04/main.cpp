#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "replace.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) 
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) 
    {
        std::cerr << "Error: Could not open file '" << filename << "'" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();
    inputFile.close();
    
    std::string modifiedContent = replaceOccurrences(content, s1, s2);
    
    // Create output filename
    std::string outputFilename = filename + ".replace";
    
    // Write to output file
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file '" << outputFilename << "'" << std::endl;
        return 1;
    }
    
    outputFile << modifiedContent;
    outputFile.close();
    
    std::cout << "File processed successfully. Output written to '" << outputFilename << "'" << std::endl;
    
    return 0;
}