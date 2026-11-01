#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

void Point::Print() const {
    cout << "Point(" << x << ", " << y << ")";
}

Point& Point::operator++() {
    ++x;
    ++y;
    return *this;
}

Point Point::operator++(int) {
    Point temp = *this;
    ++x;
    ++y;
    return temp;
}

Point& Point::operator--() {
    --x;
    --y;
    return *this;
}

Point Point::operator--(int) {
    Point temp = *this;
    --x;
    --y;
    return temp;
}

bool Point::operator>(const Point& other) const {
    double distThis = sqrt(x * x + y * y);
    double distOther = sqrt(other.x * other.x + other.y * other.y);
    return distThis > distOther;
}

bool Point::operator<(const Point& other) const {
    double distThis = sqrt(x * x + y * y);
    double distOther = sqrt(other.x * other.x + other.y * other.y);
    return distThis < distOther;
}

Point Point::operator!() const {
    return Point(-x, -y);
}
