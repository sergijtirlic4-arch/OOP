#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Worker
{
    string fullName;
    string position;
    int hireYear;
    double salary;

public:
    explicit Worker();
    explicit Worker(string fullName, string position, int hireYear, double salary);
    ~Worker();

    void Show() const;
    static void PrintByExperience(const Worker workers[], int size, int years);
    static void PrintBySalary(const Worker workers[], int size, double minSalary);
    static void PrintByPosition(const Worker workers[], int size, const string& position);
};

Worker::Worker()
{
    fullName = "Unknown";
    position = "Unknown";
    hireYear = 0;
    salary = 0.0;
}

Worker::Worker(string fullName, string position, int hireYear, double salary)
{
    this->fullName = fullName;
    this->position = position;
    this->hireYear = hireYear;
    this->salary = salary;
}

Worker::~Worker()
{
}

void Worker::Show() const
{
    cout << left << setw(20) << fullName
        << setw(20) << position
        << setw(12) << hireYear
        << salary << " USD\n";
}

void Worker::PrintByExperience(const Worker workers[], int size, int years)
{
    cout << "\n--- Workers with experience over " << years << " years ---\n";
    bool found = false;
    int currentYear = 2026;
    for (int i = 0; i < size; ++i) {
        if ((currentYear - workers[i].hireYear) > years) {
            workers[i].Show();
            found = true;
        }
    }
    if (!found) cout << "No workers found.\n";
}

void Worker::PrintBySalary(const Worker workers[], int size, double minSalary)
{
    cout << "\n--- Workers with salary over " << minSalary << " ---\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (workers[i].salary > minSalary) {
            workers[i].Show();
            found = true;
        }
    }
    if (!found) cout << "No workers found.\n";
}

void Worker::PrintByPosition(const Worker workers[], int size, const string& position)
{
    cout << "\n--- Workers holding position: " << position << " ---\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (workers[i].position == position) {
            workers[i].Show();
            found = true;
        }
    }
    if (!found) cout << "No workers found.\n";
}

int main()
{
    const int SIZE = 5;
    Worker staff[SIZE] = {
        Worker("John Doe", "Manager", 2015, 2500.0),
        Worker("Alice Smith", "Developer", 2022, 3500.0),
        Worker("Bob Johnson", "Designer", 2018, 2200.0),
        Worker("Charlie Brown", "Developer", 2020, 3800.0),
        Worker("Diana Prince", "Manager", 2024, 2700.0)
    };

    cout << "All workers in company:\n";
    for (int i = 0; i < SIZE; ++i) {
        staff[i].Show();
    }

    Worker::PrintByExperience(staff, SIZE, 5);
    Worker::PrintBySalary(staff, SIZE, 3000.0);
    Worker::PrintByPosition(staff, SIZE, "Developer");
}
