#include "Point.hpp"

// Helper function to calculate the area of a triangle using cross product
static Fixed area(Point const &a, Point const &b, Point const &c)
{
    Fixed area = ((a.getX() * (b.getY() - c.getY())) + 
                  (b.getX() * (c.getY() - a.getY())) + 
                  (c.getX() * (a.getY() - b.getY())));
    
    // Return absolute value of the area
    if (area < Fixed(0))
        return (area * Fixed(-1));
    return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // Calculate the area of the main triangle ABC
    Fixed areaABC = area(a, b, c);
    
    // If the main triangle has no area, it's not a valid triangle
    if (areaABC == Fixed(0))
        return (false);
    
    // Calculate the areas of the three sub-triangles formed by the point
    Fixed areaPBC = area(point, b, c);
    Fixed areaAPC = area(a, point, c);
    Fixed areaABP = area(a, b, point);
    
    // If any of the sub-triangles has zero area, the point is on an edge or vertex
    if (areaPBC == Fixed(0) || areaAPC == Fixed(0) || areaABP == Fixed(0))
        return (false);
    
    // Check if the sum of the three sub-triangle areas equals the main triangle area
    // If yes, the point is inside the triangle
    return (areaABC == (areaPBC + areaAPC + areaABP));
}
