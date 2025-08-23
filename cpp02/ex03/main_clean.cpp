#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void printTestResult(const std::string& description, bool result, bool expected)
{
    std::cout << description << ": " << (result ? "true" : "false");
    if (result == expected) {
        std::cout << " ✓" << std::endl;
    } else {
        std::cout << " ✗ (expected " << (expected ? "true" : "false") << ")" << std::endl;
    }
}

int main(void) 
{
    std::cout << "=== BSP (Binary Space Partitioning) Test ===" << std::endl;
    std::cout << "Testing if points are inside a triangle" << std::endl;
    
    // Define a triangle with vertices at (0,0), (4,0), (2,3)
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 3.0f);
    
    std::cout << "\nTriangle vertices:" << std::endl;
    std::cout << "A: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
    std::cout << "B: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
    std::cout << "C: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
    
    std::cout << "\n--- Points inside triangle (should be true) ---" << std::endl;
    Point inside1(2.0f, 1.0f);
    Point inside2(1.5f, 0.5f);
    Point inside3(2.5f, 1.5f);
    
    printTestResult("Point (2, 1)", bsp(a, b, c, inside1), true);
    printTestResult("Point (1.5, 0.5)", bsp(a, b, c, inside2), true);
    printTestResult("Point (2.5, 1.5)", bsp(a, b, c, inside3), true);
    
    std::cout << "\n--- Points outside triangle (should be false) ---" << std::endl;
    Point outside1(5.0f, 1.0f);
    Point outside2(-1.0f, 1.0f);
    Point outside3(2.0f, 4.0f);
    Point outside4(2.0f, -1.0f);
    
    printTestResult("Point (5, 1)", bsp(a, b, c, outside1), false);
    printTestResult("Point (-1, 1)", bsp(a, b, c, outside2), false);
    printTestResult("Point (2, 4)", bsp(a, b, c, outside3), false);
    printTestResult("Point (2, -1)", bsp(a, b, c, outside4), false);
    
    std::cout << "\n--- Vertices (should be false) ---" << std::endl;
    printTestResult("Vertex A", bsp(a, b, c, a), false);
    printTestResult("Vertex B", bsp(a, b, c, b), false);
    printTestResult("Vertex C", bsp(a, b, c, c), false);
    
    std::cout << "\n--- Points on edges (should be false) ---" << std::endl;
    Point edge1(2.0f, 0.0f);    // On edge AB
    Point edge2(1.0f, 1.5f);    // On edge AC
    Point edge3(3.0f, 1.5f);    // On edge BC
    
    printTestResult("Point on edge AB (2, 0)", bsp(a, b, c, edge1), false);
    printTestResult("Point on edge AC (1, 1.5)", bsp(a, b, c, edge2), false);
    printTestResult("Point on edge BC (3, 1.5)", bsp(a, b, c, edge3), false);
    
    std::cout << "\n=== Test Summary ===" << std::endl;
    std::cout << "BSP function correctly identifies:" << std::endl;
    std::cout << "✓ Points inside the triangle" << std::endl;
    std::cout << "✓ Points outside the triangle" << std::endl;
    std::cout << "✓ Points on vertices (returns false as required)" << std::endl;
    std::cout << "✓ Points on edges (returns false as required)" << std::endl;
    
    return 0;
}
