#include <iostream>
using namespace std;

struct Vagon {
    int number;
    int seats;
    int passengers;

    Vagon();
    Vagon(int number, int seats, int passengers);
    friend ostream& operator<<(ostream& out, const Vagon& v);
};

Vagon::Vagon() {
    number = 0;
    seats = 0;
    passengers = 0;
}

Vagon::Vagon(int number, int seats, int passengers) {
    this->number = number;
    this->seats = seats;
    this->passengers = passengers;
}

ostream& operator<<(ostream& out, const Vagon& v) {
    out << "[Vagon #" << v.number << " | Seats: " << v.seats << " | Passengers: " << v.passengers << "]";
    return out;
}

template <typename T>
class List {
    struct Node {
        T value;
        Node* prev;
        Node* next;

        Node() : value(T()), prev(nullptr), next(nullptr) {}
        Node(T value, Node* prev, Node* next) : value(value), prev(prev), next(next) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    List();
    List(const List<T>& other);
    ~List();

    List<T>& operator=(const List<T>& other);

    void AddToHead(T value);
    void AddToTail(T value);
    void AddAtPosition(T value, int pos);

    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAtPosition(int pos);

    int GetSize() const;
    bool IsEmpty() const;
    void Clear();
    void PrintList() const;
};

template <typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <typename T>
List<T>::List(const List<T>& other) {
    head = nullptr;
    tail = nullptr;
    size = 0;

    Node* current = other.head;
    while (current != nullptr) {
        AddToTail(current->value);
        current = current->next;
    }
}

template <typename T>
List<T>::~List() {
    Clear();
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this == &other) return *this;
    Clear();

    Node* current = other.head;
    while (current != nullptr) {
        AddToTail(current->value);
        current = current->next;
    }
    return *this;
}

template <typename T>
void List<T>::AddToHead(T value) {
    Node* newNode = new Node(value, nullptr, head);
    if (IsEmpty()) {
        head = tail = newNode;
    }
    else {
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void List<T>::AddToTail(T value) {
    Node* newNode = new Node(value, tail, nullptr);
    if (IsEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
void List<T>::AddAtPosition(T value, int pos) {
    if (pos < 1 || pos > size + 1) {
        cout << "Invalid position\n";
        return;
    }
    if (pos == 1) {
        AddToHead(value);
        return;
    }
    if (pos == size + 1) {
        AddToTail(value);
        return;
    }

    Node* current = head;
    for (int i = 1; i < pos; i++) {
        current = current->next;
    }

    Node* newNode = new Node(value, current->prev, current);
    current->prev->next = newNode;
    current->prev = newNode;
    size++;
}

template <typename T>
void List<T>::DeleteFromHead() {
    if (IsEmpty()) return;

    Node* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
void List<T>::DeleteFromTail() {
    if (IsEmpty()) return;

    Node* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size--;
}

template <typename T>
void List<T>::DeleteAtPosition(int pos) {
    if (IsEmpty() || pos < 1 || pos > size) {
        cout << "Invalid position or list is empty\n";
        return;
    }
    if (pos == 1) {
        DeleteFromHead();
        return;
    }
    if (pos == size) {
        DeleteFromTail();
        return;
    }

    Node* current = head;
    for (int i = 1; i < pos; i++) {
        current = current->next;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    size--;
}

template <typename T>
int List<T>::GetSize() const {
    return size;
}

template <typename T>
bool List<T>::IsEmpty() const {
    return head == nullptr;
}

template <typename T>
void List<T>::Clear() {
    while (!IsEmpty()) {
        DeleteFromHead();
    }
}

template <typename T>
void List<T>::PrintList() const {
    Node* current = head;
    while (current != nullptr) {
        cout << "  " << current->value << "\n";
        current = current->next;
    }
}

class Train {
private:
    string model;
    int countVagons;
    List<Vagon> vagons;

public:
    Train();
    Train(string model);
    Train(const Train& other);

    void AddVagonToHead(Vagon v);
    void AddVagonToTail(Vagon v);
    void AddVagonAtPosition(Vagon v, int pos);

    void DeleteVagonFromHead();
    void DeleteVagonFromTail();
    void DeleteVagonAtPosition(int pos);

    void Show() const;
};

Train::Train() {
    model = "Unknown";
    countVagons = 0;
}

Train::Train(string model) {
    this->model = model;
    this->countVagons = 0;
}

Train::Train(const Train& other) {
    this->model = other.model;
    this->countVagons = other.countVagons;
    this->vagons = other.vagons;
}

void Train::AddVagonToHead(Vagon v) {
    vagons.AddToHead(v);
    countVagons++;
}

void Train::AddVagonToTail(Vagon v) {
    vagons.AddToTail(v);
    countVagons++;
}

void Train::AddVagonAtPosition(Vagon v, int pos) {
    if (pos < 1 || pos > countVagons + 1) {
        cout << "Cannot add vagon\n";
        return;
    }
    vagons.AddAtPosition(v, pos);
    countVagons++;
}

void Train::DeleteVagonFromHead() {
    if (countVagons == 0) {
        cout << "Train has no vagons\n";
        return;
    }
    vagons.DeleteFromHead();
    countVagons--;
}

void Train::DeleteVagonFromTail() {
    if (countVagons == 0) {
        cout << "Train has no vagons\n";
        return;
    }
    vagons.DeleteFromTail();
    countVagons--;
}

void Train::DeleteVagonAtPosition(int pos) {
    if (countVagons == 0 || pos < 1 || pos > countVagons) {
        cout << "Cannot delete vagon\n";
        return;
    }
    vagons.DeleteAtPosition(pos);
    countVagons--;
}

void Train::Show() const {
    cout << "Train Model: " << model << " | Vagons count: " << countVagons << "\n";
    if (countVagons == 0) {
        cout << "  No vagons attached.\n";
    }
    else {
        vagons.PrintList();
    }
    cout << "--------------------------------------------------\n";
}

int main() {
    Train t1("Intercity+");
    t1.AddVagonToTail(Vagon(1, 50, 45));
    t1.AddVagonToTail(Vagon(3, 60, 58));
    t1.AddVagonToHead(Vagon(0, 20, 10));
    t1.Show();

    cout << "Adding Vagon #2 at position 3:\n";
    t1.AddVagonAtPosition(Vagon(2, 54, 50), 3);
    t1.Show();

    cout << "Copied Train (t2):\n";
    Train t2 = t1;
    t2.Show();

    cout << "Deleting vagon at position 2 and from head in t1:\n";
    t1.DeleteVagonAtPosition(2);
    t1.DeleteVagonFromHead();
    t1.Show();

    cout << "Check t2 after modifying t1 (deep copy works):\n";
    t2.Show();

}
