#include <iostream>
using namespace std;

template <typename T>
class Stack {
    T* arr;
    int capacity;
    int topIndex;

    void resize(int newCapacity);

public:
    Stack();
    Stack(int capacity);
    Stack(int capacity, initializer_list<T> list);
    ~Stack();

    void Push(const T& value);
    void Pop();
    T Peek() const;

    int GetCount() const;
    bool IsEmpty() const;
    bool IsFull() const;
    void Clear();
    void Show() const;
};

template <typename T>
void Stack<T>::resize(int newCapacity) {
    if (newCapacity < capacity) return;
    T* temp = new T[newCapacity];
    for (int i = 0; i <= topIndex; ++i) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    capacity = newCapacity;
}

template <typename T>
Stack<T>::Stack() {
    capacity = 10;
    topIndex = -1;
    arr = new T[capacity];
}

template <typename T>
Stack<T>::Stack(int capacity) {
    if (capacity <= 0) capacity = 10;
    this->capacity = capacity;
    topIndex = -1;
    arr = new T[this->capacity];
}

template <typename T>
Stack<T>::Stack(int capacity, initializer_list<T> list) {
    if (capacity < static_cast<int>(list.size())) {
        this->capacity = list.size();
    }
    else {
        this->capacity = capacity;
    }
    topIndex = -1;
    arr = new T[this->capacity];
    for (const auto& item : list) {
        Push(item);
    }
}

template <typename T>
Stack<T>::~Stack() {
    delete[] arr;
}

template <typename T>
void Stack<T>::Push(const T& value) {
    if (IsFull()) {
        resize(capacity * 2);
    }
    arr[++topIndex] = value;
}

template <typename T>
void Stack<T>::Pop() {
    if (IsEmpty()) {
        cout << "Stack Underflow\n";
        return;
    }
    topIndex--;
}

template <typename T>
T Stack<T>::Peek() const {
    if (IsEmpty()) {
        cout << "Stack is empty\n";
        return T();
    }
    return arr[topIndex];
}

template <typename T>
int Stack<T>::GetCount() const {
    return topIndex + 1;
}

template <typename T>
bool Stack<T>::IsEmpty() const {
    return topIndex == -1;
}

template <typename T>
bool Stack<T>::IsFull() const {
    return (topIndex + 1) == capacity;
}

template <typename T>
void Stack<T>::Clear() {
    topIndex = -1;
}

template <typename T>
void Stack<T>::Show() const {
    if (IsEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }
    for (int i = topIndex; i >= 0; --i) {
        cout << arr[i] << "\n";
    }
    cout << "-----\n";
}

int main() {
    Stack<int> s(2, { 1, 2, 3, 4 });
    s.Show();

    s.Push(5);
    s.Show();
}
