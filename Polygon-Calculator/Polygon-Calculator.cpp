#include <iostream>
#include <vector>
#include "Point.h"
#include "Polygon.h"

int main() {
    Point a(1, 2);
    Point b(3, 4);
    Point c = a + b;

    std::cout << "Point A: " << a << std::endl;
    std::cout << "Point B: " << b << std::endl;
    std::cout << "Point C = A + B: " << c << std::endl;

    std::cout << "Dot product A * B: " << a * b << std::endl;
    std::cout << "Length of vector A: " << a.length() << std::endl;

    std::cout << "Cosine of angle between A and B: " << Point::cosine(a, b) << std::endl;

    std::vector<Point> vertices = { Point(0, 0), Point(4, 0), Point(4, 3), Point(0, 3) };
    Polygon p(vertices);

    std::cout << "Is polygon convex? " << (p.isConvex() ? "Yes" : "No") << std::endl;

    std::cout << "Area of polygon: " << p.area() << std::endl;

    std::cout << "Vertices of polygon: " << p << std::endl;

    std::cout << "First vertex: " << p[0] << std::endl;

    return 0;
}
