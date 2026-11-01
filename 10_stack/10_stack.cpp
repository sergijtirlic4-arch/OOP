#include <iostream>
using namespace std;

class CharStack {
    static const int MAX_SIZE = 100;
    char arr[MAX_SIZE];
    int topIndex;

public:
    CharStack();

    void Push(char value);
    void Pop();
    char Peek() const;

    int GetCount() const;
    bool IsEmpty() const;
    bool IsFull() const;
    void Clear();
    void Show() const;
};

CharStack::CharStack() {
    topIndex = -1;
}

void CharStack::Push(char value) {
    if (IsFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    arr[++topIndex] = value;
}

void CharStack::Pop() {
    if (IsEmpty()) {
        cout << "Stack Underflow\n";
        return;
    }
    topIndex--;
}

char CharStack::Peek() const {
    if (IsEmpty()) {
        cout << "Stack is empty\n";
        return '\0';
    }
    return arr[topIndex];
}

int CharStack::GetCount() const {
    return topIndex + 1;
}

bool CharStack::IsEmpty() const {
    return topIndex == -1;
}

bool CharStack::IsFull() const {
    return (topIndex + 1) == MAX_SIZE;
}

void CharStack::Clear() {
    topIndex = -1;
}

void CharStack::Show() const {
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
    CharStack s;
    s.Push('X');
    s.Push('Y');
    s.Push('Z');
    s.Show();

    cout << s.Peek() << "\n\n";
    s.Pop();
    s.Show();

    s.Clear();
    s.Show();
}
