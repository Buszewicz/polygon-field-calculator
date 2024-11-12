#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "Point.h"

class Polygon {
private:
    std::vector<Point> vertice;

public:
    Polygon(std::vector<Point> vertices);

    Polygon(const Polygon& other);

    const std::vector<Point>& getVertices() const;
    void setVertices(const std::vector<Point>& vertices);
    void addVertex(const Point& p);
    void removeVertex(size_t index);

    float area() const;

    bool isConvex() const;

    friend std::ostream& operator<<(std::ostream& os, const Polygon& p);

    Point& operator[](size_t index);
    const Point& operator[](size_t index) const;
};

#endif 
