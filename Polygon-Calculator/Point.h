#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class Point {
private:
    float x, y;

public:
    Point(float x = 0, float y = 0);

    float getX() const;
    void setX(float x);

    float getY() const;
    void setY(float y);

    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    Point& operator=(const Point& p);

    Point operator+(const Point& p) const;

    Point operator-(const Point& p) const;

    float operator*(const Point& p) const;

    float length() const;

    static float cosine(const Point& v1, const Point& v2);
};

#endif 
