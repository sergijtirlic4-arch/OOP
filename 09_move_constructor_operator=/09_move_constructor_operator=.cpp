#include <iostream>
#include "Point.h"
#include "Vector.h"

using namespace std;

int main() {
    Point p1(3, 4);
    Point p2(1, 1);

    cout << "p1: "; p1.Print(); cout << "\n";
    cout << "p2: "; p2.Print(); cout << "\n";

    if (p1 > p2) cout << "p1 is further than p2\n";
    else cout << "p1 is closer than p2\n";

    (++p2).Print(); cout << "\n";

    Point pInverted = !p1;
    pInverted.Print(); cout << "\n\n";

    Vector v1;
    v1.Add(Point(1, 2));
    v1.Add(Point(4, 3));
    v1.Add(Point(-2, 1));

    cout << "Vector v1 elements: ";
    v1.Print();

    Vector v2 = v1;
    cout << "Vector v2 elements: ";
    v2.Print();

    Vector v3 = move(v1);
    cout << "Vector v3 elements: ";
    v3.Print();
}
