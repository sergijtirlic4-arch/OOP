#include <iostream>
#include <iomanip>

using namespace std;

class Abonent {
    string fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string extraInfo;

    static int abonentCount;

public:
    Abonent();
    Abonent(string fullName, string mobilePhone);
    Abonent(string fullName, string homePhone, string workPhone, string mobilePhone, string extraInfo);

    ~Abonent();

    void Show() const;

    static int GetCount();
    static void PrintByMobilePrefix(const Abonent phoneBook[], int size, const string& prefix);
    static void FindByName(const Abonent phoneBook[], int size, const string& name);
};

int Abonent::abonentCount = 0;

Abonent::Abonent() : Abonent("Unknown", "-", "-", "-", "-") {
}

Abonent::Abonent(string fullName, string mobilePhone)
    : Abonent(fullName, "-", "-", mobilePhone, "-") {
}

Abonent::Abonent(string fullName, string homePhone, string workPhone, string mobilePhone, string extraInfo) {
    this->fullName = fullName;
    this->homePhone = homePhone;
    this->workPhone = workPhone;
    this->mobilePhone = mobilePhone;
    this->extraInfo = extraInfo;

    abonentCount++;
}

Abonent::~Abonent() {
    abonentCount--;
}

int Abonent::GetCount() {
    return abonentCount;
}

void Abonent::Show() const {
    cout << left << setw(20) << fullName
        << setw(15) << mobilePhone
        << setw(15) << homePhone
        << setw(15) << workPhone
        << extraInfo << "\n";
}

void Abonent::PrintByMobilePrefix(const Abonent phoneBook[], int size, const string& prefix) {
    cout << "\n--- Subscribers with mobile prefix \"" << prefix << "\" ---\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (phoneBook[i].mobilePhone.rfind(prefix, 0) == 0) {
            phoneBook[i].Show();
            found = true;
        }
    }
    if (!found) cout << "No subscribers found\n";
}

void Abonent::FindByName(const Abonent phoneBook[], int size, const string& name) {
    cout << "\n--- Search results for name: \"" << name << "\" ---\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (phoneBook[i].fullName.find(name) != string::npos) {
            phoneBook[i].Show();
            found = true;
        }
    }
    if (!found) cout << "No subscribers found\n";
}

int main() {
    const int SIZE = 5;

    Abonent phoneBook[SIZE] = {
        Abonent("John Doe", "02-123-45", "02-987-65", "0971112233", "Friend from work"),
        Abonent("Alice Smith", "0634445566"),
        Abonent("Bob Johnson", "-", "-", "0507778899", "Doctor"),
        Abonent("Charlie Brown", "02-555-44", "-", "0979998877", "Neighbor"),
        Abonent()
    };

    cout << "Total subscribers created: " << Abonent::GetCount() << "\n\n";

    cout << left << setw(20) << "Name"
        << setw(15) << "Mobile Phone"
        << setw(15) << "Home Phone"
        << setw(15) << "Work Phone"
        << "Extra Info\n";
    cout << string(80, '-') << "\n";

    for (int i = 0; i < SIZE; ++i) {
        phoneBook[i].Show();
    }

    Abonent::PrintByMobilePrefix(phoneBook, SIZE, "097");
    Abonent::FindByName(phoneBook, SIZE, "Alice");
}

