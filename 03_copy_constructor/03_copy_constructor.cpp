#include <iostream>
using namespace std;

class Array {
private:
    long* arr;
    int size;

public:
    Array() {
        this->size = 0;
        this->arr = nullptr;
    }

    Array(int size) {
        if (size < 0) size = 0;
        this->size = size;
        if (this->size > 0) {
            this->arr = new long[this->size] {0};
        }
        else {
            this->arr = nullptr;
        }
    }

    Array(const Array& other) {
        this->size = other.size;
        if (this->size > 0) {
            this->arr = new long[this->size];
            for (int i = 0; i < this->size; ++i) {
                this->arr[i] = other.arr[i];
            }
        }
        else {
            this->arr = nullptr;
        }
    }

    ~Array() {
        delete[] this->arr;
    }

    void fillRandom(long minVal = 1, long maxVal = 100) {
        if (this->size == 0) return;
        for (int i = 0; i < this->size; ++i) {
            this->arr[i] = minVal + rand() % (maxVal - minVal + 1);
        }
    }

    void fillFromKeyboard() {
        if (this->size == 0) {
            cout << "Array is empty.\n";
            return;
        }
        cout << "Enter " << this->size << " elements:\n";
        for (int i = 0; i < this->size; ++i) {
            cout << "[" << i << "]: ";
            cin >> this->arr[i];
        }
    }

    void show() const {
        if (this->size == 0 || this->arr == nullptr) {
            cout << "Array is empty.\n";
            return;
        }
        for (int i = 0; i < this->size; ++i) {
            cout << this->arr[i] << " ";
        }
        cout << "\n";
    }

    void addElement(long value) {
        long* temp = new long[this->size + 1];
        for (int i = 0; i < this->size; ++i) {
            temp[i] = this->arr[i];
        }
        temp[this->size] = value;

        delete[] this->arr;
        this->arr = temp;
        this->size++;
    }

    bool removeByIndex(int index) {
        if (index < 0 || index >= this->size) {
            cout << "Error: Invalid index.\n";
            return false;
        }

        if (this->size == 1) {
            delete[] this->arr;
            this->arr = nullptr;
            this->size = 0;
            return true;
        }

        long* temp = new long[this->size - 1];
        for (int i = 0, j = 0; i < this->size; ++i) {
            if (i == index) continue;
            temp[j++] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = temp;
        this->size--;
        return true;
    }

    bool removeByValue(long value) {
        int index = -1;
        for (int i = 0; i < this->size; ++i) {
            if (this->arr[i] == value) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Error: Element not found.\n";
            return false;
        }

        return removeByIndex(index);
    }

    void sort(bool a = true) {
        if (this->size <= 1) return;
        for (int i = 0; i < this->size - 1; ++i) {
            for (int j = 0; j < this->size - i - 1; ++j) {
                if (a) {
                    if (this->arr[j] > this->arr[j + 1]) {
                        long temp = this->arr[j];
                        this->arr[j] = this->arr[j + 1];
                        this->arr[j + 1] = temp;
                    }
                }
                else {
                    if (this->arr[j] < this->arr[j + 1]) {
                        long temp = this->arr[j];
                        this->arr[j] = this->arr[j + 1];
                        this->arr[j + 1] = temp;
                    }
                }
            }
        }
    }

    long getMin() const {
        if (this->size == 0) {
            cout << "Array is empty\n";
            return 0;
        }
        long min = this->arr[0];
        for (int i = 1; i < this->size; ++i) {
            if (this->arr[i] < min) min = this->arr[i];
        }
        return min;
    }

    long getMax() const {
        if (this->size == 0) {
            cout << "Array is empty.\n";
            return 0;
        }
        long max = this->arr[0];
        for (int i = 1; i < this->size; ++i) {
            if (this->arr[i] > max) max = this->arr[i];
        }
        return max;
    }

    double getAverage() const {
        if (this->size == 0) return 0.0;
        double sum = 0;
        for (int i = 0; i < this->size; ++i) {
            sum += this->arr[i];
        }
        return sum / this->size;
    }
};

struct Vagon {
    int number;
    int maxSeats;
    int passengersCount;
};

class Train {
private:
    string model;
    int vagonCount;
    Vagon* vagon;

public:
    Train() {
        this->model = "Unknown";
        this->vagonCount = 0;
        this->vagon = nullptr;
    }

    Train(string model, int vagonCount) {
        this->model = model;
        if (vagonCount < 0) vagonCount = 0;
        this->vagonCount = vagonCount;

        if (this->vagonCount > 0) {
            this->vagon = new Vagon[this->vagonCount];
            for (int i = 0; i < this->vagonCount; ++i) {
                this->vagon[i].number = i + 1;
                this->vagon[i].maxSeats = 50;
                this->vagon[i].passengersCount = 0;
            }
        }
        else {
            this->vagon = nullptr;
        }
    }

    Train(const Train& other) {
        this->model = other.model;
        this->vagonCount = other.vagonCount;

        if (this->vagonCount > 0) {
            this->vagon = new Vagon[this->vagonCount];
            for (int i = 0; i < this->vagonCount; ++i) {
                this->vagon[i] = other.vagon[i];
            }
        }
        else {
            this->vagon = nullptr;
        }
    }

    ~Train() {
        delete[] this->vagon;
    }

    void show() const {
        cout << "Train model: " << this->model << " | Carriage count: " << this->vagonCount << "\n";
        if (this->vagonCount == 0 || this->vagon == nullptr) {
            cout << "   No carriages attached.\n";
            return;
        }
        for (int i = 0; i < this->vagonCount; ++i) {
            cout << "   Carriage #" << this->vagon[i].number
                << " | Passengers: " << this->vagon[i].passengersCount
                << " / " << this->vagon[i].maxSeats << "\n";
        }
    }

    void addVagon(int number, int maxSeats, int passengersCount) {
        if (passengersCount > maxSeats) passengersCount = maxSeats;
        if (passengersCount < 0) passengersCount = 0;

        Vagon* temp = new Vagon[this->vagonCount + 1];
        for (int i = 0; i < this->vagonCount; ++i) {
            temp[i] = this->vagon[i];
        }

        temp[this->vagonCount].number = number;
        temp[this->vagonCount].maxSeats = maxSeats;
        temp[this->vagonCount].passengersCount = passengersCount;

        delete[] this->vagon;
        this->vagon = temp;
        this->vagonCount++;
    }

    bool addOnePassenger(int vagonNumber) {
        for (int i = 0; i < this->vagonCount; ++i) {
            if (this->vagon[i].number == vagonNumber) {
                if (this->vagon[i].passengersCount < this->vagon[i].maxSeats) {
                    this->vagon[i].passengersCount++;
                    return true;
                }
                else {
                    cout << "Error\n";
                    return false;
                }
            }
        }
        cout << "Error\n";
        return false;
    }
};

int main() {
    srand(time(0));

    Array arr1(5);
    arr1.fillRandom(10, 50);
    cout << "Array 1: ";
    arr1.show();

    Array arr2 = arr1;
    arr2.show();

    arr1.addElement(99);
    arr1.show();
    arr2.show();

    arr1.sort(false);
    arr1.show();
    cout << "Min: " << arr1.getMin() << ", Max: " << arr1.getMax() << ", Avg: " << arr1.getAverage() << "\n\n";

    Train train1("Express-A", 2);
    cout << "Train 1:\n";
    train1.show();

    train1.addOnePassenger(1);
    train1.addVagon(3, 40, 10);

    train1.show();

    Train train2 = train1;
    train2.show();
}
