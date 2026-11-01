#include <iostream>
#include <initializer_list>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class Array {
    T* arr;
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
            this->arr = new T[this->size]{};
        }
        else {
            this->arr = nullptr;
        }
    }

    Array(const Array& other) {
        this->size = other.size;
        if (this->size > 0) {
            this->arr = new T[this->size];
            for (int i = 0; i < this->size; ++i) {
                this->arr[i] = other.arr[i];
            }
        }
        else {
            this->arr = nullptr;
        }
    }

    Array(initializer_list<T> list) {
        this->size = list.size();
        if (this->size > 0) {
            this->arr = new T[this->size];
            int i = 0;
            for (const auto& element : list) {
                this->arr[i++] = element;
            }
        }
        else {
            this->arr = nullptr;
        }
    }

    ~Array() {
        delete[] this->arr;
    }

    int getSize() const {
        return this->size;
    }

    T* getRawArray() {
        return this->arr;
    }

    const T* getRawArray() const {
        return this->arr;
    }

    void fillRandom(T minVal = 1, T maxVal = 100) {
        if (this->size == 0) return;
        for (int i = 0; i < this->size; ++i) {
            this->arr[i] = minVal + rand() % static_cast<int>(maxVal - minVal + 1);
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

    void addElement(T value) {
        T* temp = new T[this->size + 1];
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

        T* temp = new T[this->size - 1];
        for (int i = 0, j = 0; i < this->size; ++i) {
            if (i == index) continue;
            temp[j++] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = temp;
        this->size--;
        return true;
    }

    bool removeByValue(T value) {
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
                        T temp = this->arr[j];
                        this->arr[j] = this->arr[j + 1];
                        this->arr[j + 1] = temp;
                    }
                }
                else {
                    if (this->arr[j] < this->arr[j + 1]) {
                        T temp = this->arr[j];
                        this->arr[j] = this->arr[j + 1];
                        this->arr[j + 1] = temp;
                    }
                }
            }
        }
    }

    T getMin() const {
        if (this->size == 0) {
            cout << "Array is empty\n";
            return T();
        }
        T min = this->arr[0];
        for (int i = 1; i < this->size; ++i) {
            if (this->arr[i] < min) min = this->arr[i];
        }
        return min;
    }

    T getMax() const {
        if (this->size == 0) {
            cout << "Array is empty.\n";
            return T();
        }
        T max = this->arr[0];
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

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            cout << "Error\n";
            static const T default_value = T();
            return default_value;
        }
        return arr[index];
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            cout << "Error\n";
            static T default_value = T();
            return default_value;
        }
        return arr[index];
    }

    void operator()(T num) {
        for (int i = 0; i < size; i++) {
            arr[i] += num;
        }
    }
};

template <typename T>
T FindMax(const Array<T>& array) {
    return array.getMax();
}

template <typename T>
T FindMin(const Array<T>& array) {
    return array.getMin();
}

template <typename T>
void SortArray(Array<T>& array, bool ascending = true) {
    array.sort(ascending);
}

template <typename T>
int BinarySearch(const Array<T>& array, T target) {
    Array<T> tempCopy = array;
    tempCopy.sort(true);

    int left = 0;
    int right = tempCopy.getSize() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (tempCopy[mid] == target) {
            return mid;
        }
        if (tempCopy[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

template <typename T>
void ReplaceElement(Array<T>& array, T oldValue, T newValue) {
    T* raw = array.getRawArray();
    int size = array.getSize();
    for (int i = 0; i < size; ++i) {
        if (raw[i] == oldValue) {
            raw[i] = newValue;
        }
    }
}

int main() {
    srand(time(0));

    Array<int> intArr = { 5, 2, 9, 1, 5, 6 };
    cout << "Original template list: ";
    intArr.show();

    cout << "Max external: " << FindMax(intArr) << "\n";
    cout << "Min external: " << FindMin(intArr) << "\n";

    SortArray(intArr, true);
    intArr.show();

    int searchVal = 9;
    int index = BinarySearch(intArr, searchVal);

    ReplaceElement(intArr, 5, 99);
    intArr.show();

    Array<double> doubleArr(4);
    doubleArr[0] = 4.5;
    doubleArr[1] = 1.2;
    doubleArr[2] = 3.8;
    doubleArr[3] = 2.9;
    cout << "Double array: ";
    doubleArr.show();

    SortArray(doubleArr, false);
    doubleArr.show();
}
