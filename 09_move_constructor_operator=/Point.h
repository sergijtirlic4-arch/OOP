#pragma once

class Point {
    int x;
    int y;
public:
    explicit Point();
    explicit Point(int x, int y);

    void Print() const;

    Point& operator++();
    Point operator++(int);
    Point& operator--();
    Point operator--(int);

    bool operator>(const Point& other) const;
    bool operator<(const Point& other) const;

    Point operator!() const;
};
