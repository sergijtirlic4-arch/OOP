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
    List() { head = nullptr; }

    void AddToHead(T value) {
        Node* newNode = new Node(value, head);
        head = newNode;
    }

    void DeleteFromHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void PrintList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~List() {
        Node* current = nullptr;
        while (head != nullptr) {
            current = head;
            head = head->next;
            delete current;
        }
    }

    void AddToTail(T value) {
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

    T GetElement(int pos) {
        int i = 0;
        Node* current = head;
        while (current != nullptr) {
            if (i == pos - 1) return current->value;
            current = current->next;
            i++;
        }
        return T();
    }

    void DeleteFromTail() {
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
};

int main() {
    List<string> l;
    l.AddToTail("Hi");
    l.AddToTail("Hello");
    l.AddToTail("Hello World");
    l.PrintList();
    cout << "Get second element : " << l.GetElement(2) << endl;
    l.DeleteFromHead();
    l.PrintList();
    l.DeleteFromHead();
    l.PrintList();
    l.DeleteFromHead();
    l.PrintList();

}
