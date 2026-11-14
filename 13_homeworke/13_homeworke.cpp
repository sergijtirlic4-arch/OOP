#include <iostream>
using namespace std;

template <typename T>
class List {
    struct Node {
        T value;
        Node* next;
        Node() : value(T()), next(nullptr) {}
        Node(T value, Node* next) : value(value), next(next) {}
    };
    Node* head;

public:
    List();
    ~List();

    void AddToHead(T value);
    void AddToTail(T value);
    void DeleteFromHead();
    void DeleteFromTail();
    T GetElement(int pos) const;
    bool IsEmpty() const;
    void PrintList() const;
};

template <typename T>
List<T>::List() {
    head = nullptr;
}

template <typename T>
List<T>::~List() {
    Node* current = nullptr;
    while (head != nullptr) {
        current = head;
        head = head->next;
        delete current;
    }
}

template <typename T>
void List<T>::AddToHead(T value) {
    Node* newNode = new Node(value, head);
    head = newNode;
}

template <typename T>
void List<T>::AddToTail(T value) {
    Node* newNode = new Node(value, nullptr);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template <typename T>
void List<T>::DeleteFromHead() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
void List<T>::DeleteFromTail() {
    if (head == nullptr) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}

template <typename T>
T List<T>::GetElement(int pos) const {
    int i = 0;
    Node* current = head;
    while (current != nullptr) {
        if (i == pos - 1) return current->value;
        current = current->next;
        i++;
    }
    return T();
}

template <typename T>
bool List<T>::IsEmpty() const {
    return head == nullptr;
}

template <typename T>
void List<T>::PrintList() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "\n";
}

class Point {
    int x;
    int y;

public:
    Point();
    Point(int x, int y);

    void Print() const;
    friend ostream& operator<<(ostream& out, const Point& p);
};

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

void Point::Print() const {
    cout << "(" << x << "; " << y << ")";
}

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << "; " << p.y << ")";
    return out;
}

class Vector {
    int size;
    List<Point> points;

public:
    Vector();
    Vector(Point p);

    void AddToHead(Point p);
    void AddToTail(Point p);
    void DeleteFromHead();
    void DeleteFromTail();

    int GetSize() const;
    bool IsEmpty() const;
    void Print() const;
};

Vector::Vector() {
    size = 0;
}

Vector::Vector(Point p) {
    size = 0;
    AddToTail(p);
}

void Vector::AddToHead(Point p) {
    points.AddToHead(p);
    size++;
}

void Vector::AddToTail(Point p) {
    points.AddToTail(p);
    size++;
}

void Vector::DeleteFromHead() {
    if (IsEmpty()) {
        cout << "Vector is empty\n";
        return;
    }
    points.DeleteFromHead();
    size--;
}

void Vector::DeleteFromTail() {
    if (IsEmpty()) {
        cout << "Vector is empty\n";
        return;
    }
    points.DeleteFromTail();
    size--;
}

int Vector::GetSize() const {
    return size;
}

bool Vector::IsEmpty() const {
    return size == 0;
}

void Vector::Print() const {
    if (IsEmpty()) {
        cout << "Vector is empty.\n";
        return;
    }
    cout << "Size: " << size << " | Points: ";
    points.PrintList();
}

int main() {
    Vector v;
    v.AddToTail(Point(1, 2));
    v.AddToTail(Point(3, 4));
    v.AddToHead(Point(0, 0));
    v.Print();

    v.DeleteFromHead();
    v.Print();

    v.DeleteFromTail();
    v.Print();

    v.DeleteFromTail();
    v.Print();
}
