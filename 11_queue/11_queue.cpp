#include <iostream>
#include <string>
using namespace std;

enum class RolePriority {
    Guest = 1,
    Administrator = 2,
    Manager = 3,
    Director = 4
};

template <typename T>
class Printer
{
    struct PrintItem
    {
        T data;
        RolePriority priority;
    };
private:
    PrintItem* queue;
    int size;
public:
    Printer();
    ~Printer();

    void Enqueue(T item, RolePriority priority);
    void Dequeue();
    void PrintQueue() const;
    bool IsEmpty() const;
};

template <typename T>
Printer<T>::Printer()
{
    queue = nullptr;
    size = 0;
}

template <typename T>
Printer<T>::~Printer()
{
    if (queue != nullptr)
        delete[] queue;
}

template <typename T>
void Printer<T>::Enqueue(T item, RolePriority priority)
{
    int index = 0;
    while (index < size && queue[index].priority >= priority) {
        index++;
    }

    size++;
    PrintItem* temp = new PrintItem[size];

    for (int i = 0; i < index; i++)
    {
        temp[i] = queue[i];
    }

    temp[index] = PrintItem{ item, priority };

    for (int i = index + 1; i < size; i++)
    {
        temp[i] = queue[i - 1];
    }

    if (queue != nullptr)
        delete[] queue;

    queue = temp;
}

template <typename T>
void Printer<T>::Dequeue()
{
    if (IsEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    size--;
    if (size == 0) {
        delete[] queue;
        queue = nullptr;
        return;
    }

    PrintItem* temp = new PrintItem[size];
    for (int i = 0; i < size; i++) {
        temp[i] = queue[i + 1];
    }

    delete[] queue;
    queue = temp;
}

template <typename T>
void Printer<T>::PrintQueue() const
{
    if (IsEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Item: " << queue[i].data << " | Priority: " << static_cast<int>(queue[i].priority) << endl;
    }
    cout << "----------------------" << endl;
}

template <typename T>
bool Printer<T>::IsEmpty() const
{
    return size == 0;
}

int main()
{
    Printer<string> printer;
    int choice;

    do {
        cout << "\n=== Printer Queue Menu ===\n";
        cout << "1. Add document to queue\n";
        cout << "2. Print document\n";
        cout << "3. Show entire queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string filename;
            int roleChoice;
            RolePriority priority = RolePriority::Guest;

            cout << "Enter filename: ";
            cin.ignore();
            getline(cin, filename);

            cout << "\n--- Select your position ---\n";
            cout << "1. Guest\n";
            cout << "2. Administrator\n";
            cout << "3. Manager\n";
            cout << "4. Director\n";
            cout << "Enter position number: ";
            cin >> roleChoice;

            switch (roleChoice) {
            case 1: priority = RolePriority::Guest; break;
            case 2: priority = RolePriority::Administrator; break;
            case 3: priority = RolePriority::Manager; break;
            case 4: priority = RolePriority::Director; break;
            default: cout << "Invalid choice. Your file priority: Guest\n"; break;
            }

            printer.Enqueue(filename, priority);
            cout << "Document added successfully \n";
        }

        else if (choice == 2) {
            printer.Dequeue();
        }

        else if (choice == 3) {
            printer.PrintQueue();
        }

        else if (choice != 4) {
            cout << "Invalid choice\n";
        }

    } while (choice != 4);
}
