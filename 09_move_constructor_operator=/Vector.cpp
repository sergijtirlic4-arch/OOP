#include "Vector.h"
#include <iostream>

using namespace std;

Vector::Vector() : points(nullptr), countPoint(0) {}

Vector::Vector(int size) {
    if (size < 0) size = 0;
    countPoint = size;
    if (countPoint > 0) {
        points = new Point[countPoint];
    }
    else {
        points = nullptr;
    }
}

Vector::Vector(const Vector& other) {
    countPoint = other.countPoint;
    if (countPoint > 0) {
        points = new Point[countPoint];
        for (int i = 0; i < countPoint; ++i) {
            points[i] = other.points[i];
        }
    }
    else {
        points = nullptr;
    }
}

Vector::Vector(Vector&& other) {
    points = other.points;
    countPoint = other.countPoint;
    other.points = nullptr;
    other.countPoint = 0;
}

Vector::~Vector() {
    delete[] points;
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) return *this;
    delete[] points;
    countPoint = other.countPoint;
    if (countPoint > 0) {
        points = new Point[countPoint];
        for (int i = 0; i < countPoint; ++i) {
            points[i] = other.points[i];
        }
    }
    else {
        points = nullptr;
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) {
    if (this == &other) return *this;
    delete[] points;
    points = other.points;
    countPoint = other.countPoint;
    other.points = nullptr;
    other.countPoint = 0;
    return *this;
}

void Vector::Add(const Point& p) {
    Point* temp = new Point[countPoint + 1];
    for (int i = 0; i < countPoint; ++i) {
        temp[i] = points[i];
    }
    temp[countPoint] = p;
    delete[] points;
    points = temp;
    countPoint++;
}

void Vector::Print() const {
    if (countPoint == 0) {
        cout << "Vector is empty.\n";
        return;
    }
    for (int i = 0; i < countPoint; ++i) {
        points[i].Print();
        cout << " ";
    }
    cout << "\n";
}
