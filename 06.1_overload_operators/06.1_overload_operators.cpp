#include <iostream>
using namespace std;

class Array {
    long* arr;
    int size;
public:
#pragma region Old
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
            cout << "Error\n";
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
            cout << "Error\n";
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
#pragma endregion
    const long& operator[](int index)const;
    void operator()(long num);
};

const long& Array::operator[](int index)const{
    if (index < 0 || index >= size) {
        cout << "Error\n";
        static const long default_value = 0;
        return default_value;
    }
    return arr[index];
}

void Array::operator()(long num) {
    for (int i = 0; i < size; i++)
    {
        arr[i] += num;
    }
}

int main()
{
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

    cout << "Element: " << arr1[1] << "\n";
    cout << "Element: ";
    long error_check = arr1[9];

    arr1(10);
    arr1.show();
}
