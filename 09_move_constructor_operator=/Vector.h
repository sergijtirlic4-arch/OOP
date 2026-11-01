#include "Point.h"

class Vector {
    Point* points;
    int countPoint;
public:
    explicit Vector();
    explicit Vector(int size);
    Vector(const Vector& other);
    Vector(Vector&& other);
    ~Vector();

    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other);

    void Add(const Point& p);
    void Print() const;
};
