#include <iostream>
using namespace std;

class Airplane {
    string model;
    string type;
    int currentPassengers;
    int maxPassengers;

public:
    Airplane(string model, string type, int current, int max) {
        this->model = model;
        this->type = type;
        this->maxPassengers = max;

        if (current > max) {
            this->currentPassengers = max;
        }
        else {
            this->currentPassengers = current;
        }
    }

    void PrintInfo() const {
        cout << "Model: " << model << " | Type: " << type
            << " | Passengers: " << currentPassengers << "/" << maxPassengers << "\n";
    }

    friend bool operator==(const Airplane& a1, const Airplane& a2) {
        return a1.type == a2.type;
    }

    friend bool operator>(const Airplane& a1, const Airplane& a2) {
        return a1.maxPassengers > a2.maxPassengers;
    }

    Airplane& operator++() {
        if (currentPassengers < maxPassengers) {
            currentPassengers++;
        }
        else {
            cout << "Warning\n";
        }
        return *this;
    }

    Airplane& operator--() {
        if (currentPassengers > 0) {
            currentPassengers--;
        }
        else {
            cout << "Warning\n";
        }
        return *this;
    }

    void operator()(int count) {
        if (currentPassengers + count <= maxPassengers) {
            currentPassengers += count;
        }
        else {
            cout << "Error: Adding " << count << " passengers exceeds maximum capacity ("
                << maxPassengers << ")\n";
        }
    }
};

int main() {
    Airplane plane1("Boeing 737", "Commercial", 148, 150);
    Airplane plane2("Airbus A320", "Commercial", 175, 180);
    Airplane plane3("F-16 Fighting Falcon", "Military", 1, 2);

    plane1.PrintInfo();
    plane2.PrintInfo();
    plane3.PrintInfo();

    if (plane1 == plane2) {
        cout << "\nPlane 1 and Plane 2 have the same type.\n";
    }
    else {
        cout << "Plane 1 and Plane 2 have different types.\n";
    }

    if (plane1 == plane3) {
        cout << "Plane 1 and Plane 3 have the same type.\n";
    }
    else {
        cout << "Plane 1 and Plane 3 have different types.\n";
    }

    if (plane2 > plane1) {
        cout << "Plane 2 has a larger max capacity than Plane 1.\n";
    }

    cout << "\nCurrent state of Plane 1: "; plane1.PrintInfo();
    ++plane1;
    ++plane1;
    cout << "\nAfter ++ twice: "; plane1.PrintInfo();

    ++plane1;

    --plane1;
    cout << "\nAfter -- once:  "; plane1.PrintInfo();

    cout << "\nCurrent state of Plane 2: "; plane2.PrintInfo();

    plane2(5);
    cout << "\nAfter plane2(5): "; plane2.PrintInfo();

    plane2(15);
    cout << "\nAfter plane2(15): "; plane2.PrintInfo();
}
