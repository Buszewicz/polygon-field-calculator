#include "Point.h"

Point::Point(float x, float y) : x(x), y(y) {}

float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}

void Point::setX(float x) {
    this->x = x;
}

void Point::setY(float y) {
    this->y = y;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

Point& Point::operator=(const Point& p) {
    if (this != &p) {
        x = p.x;
        y = p.y;
    }
    return *this;
}

Point Point::operator+(const Point& p) const {
    return Point(x + p.x, y + p.y);
}

Point Point::operator-(const Point& p) const {
    return Point(x - p.x, y - p.y);
}

float Point::operator*(const Point& p) const {
    return x * p.x + y * p.y;
}

float Point::length() const {
    return sqrt(x * x + y * y);
}

float Point::cosine(const Point& v1, const Point& v2) {
    float scalar = v1 * v2;
    return scalar / (v1.length() * v2.length());
}
