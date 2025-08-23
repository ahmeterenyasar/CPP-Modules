#include <iostream>
#include "Point.hpp"

int main() {
    Point a(0, 3);
    Point b(0, 0);
    Point c(4, 0);

    // İçeride olan bir nokta
    Point p1(1, 1);
    std::cout << "Point (" << p1.getX() << ", " << p1.getY() << ")" 
    << " inside triangle: " << (bsp(a, b, c, p1) ? "true" : "false") << std::endl;

    // Dışarıda olan bir nokta
    Point p2(5, 5);
    std::cout << "Point (" << p2.getX() << ", " << p2.getY() << ")"
    << " inside triangle: " << (bsp(a, b, c, p2) ? "true" : "false") << std::endl;

    return 0;
}
