#include "Polygon.h"
#include <cmath>
#include <iostream>

Polygon::Polygon(std::vector<Point> vertices) : vertice(vertices) {}

Polygon::Polygon(const Polygon& other) {
    vertice = other.vertice;
}

const std::vector<Point>& Polygon::getVertices() const {
    return vertice;
}

void Polygon::setVertices(const std::vector<Point>& vertices) {
    vertice = vertices;
}

void Polygon::addVertex(const Point& p) {
    vertice.push_back(p);
}

void Polygon::removeVertex(size_t index) {
    if (index < vertice.size()) {
        vertice.erase(vertice.begin() + index);
    }
}

float Polygon::area() const {
    float area = 0;
    for (size_t i = 0; i < vertice.size(); ++i) {
        size_t j = (i + 1) % vertice.size();
        area += vertice[i].getX() * vertice[j].getY();
        area -= vertice[i].getY() * vertice[j].getX();
    }
    return fabs(area) / 2.0;
}

bool Polygon::isConvex() const {
    bool sign = false;
    for (size_t i = 0; i < vertice.size(); ++i) {
        size_t j = (i + 1) % vertice.size();
        size_t k = (i + 2) % vertice.size();
        float crossProduct = (vertice[j].getX() - vertice[i].getX()) * (vertice[k].getY() - vertice[j].getY()) -
            (vertice[j].getY() - vertice[i].getY()) * (vertice[k].getX() - vertice[j].getX());
        if (i == 0) {
            sign = crossProduct > 0;
        }
        if ((crossProduct > 0) != sign) {
            return false;
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Polygon& p) {
    for (const auto& v : p.vertice) {
        os << v << " ";
    }
    return os;
}

Point& Polygon::operator[](size_t index) {
    return vertice[index];
}

const Point& Polygon::operator[](size_t index) const {
    return vertice[index];
}
