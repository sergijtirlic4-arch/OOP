#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Abonent {
    string fullName;
    string homePhone;
    string workPhone;
    string mobilePhone;
    string extraInfo;

    static int abonentCount;

public:
    explicit Abonent();
    explicit Abonent(string fullName, string mobilePhone);
    explicit Abonent(string fullName, string homePhone, string workPhone, string mobilePhone, string extraInfo);

    ~Abonent();

    void Show() const;
    void SaveToFile(ofstream& out) const;
    void LoadFromFile(ifstream& in);

    string GetFullName() const;
    string GetHomePhone() const;
    string GetWorkPhone() const;
    string GetMobilePhone() const;

    static int GetCount();
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

void Abonent::SaveToFile(ofstream& out) const {
    if (out.is_open()) {
        out << fullName << "\n" << homePhone << "\n" << workPhone << "\n" << mobilePhone << "\n" << extraInfo << "\n";
    }
}

void Abonent::LoadFromFile(ifstream& in) {
    if (in.is_open()) {
        getline(in, fullName);
        getline(in, homePhone);
        getline(in, workPhone);
        getline(in, mobilePhone);
        getline(in, extraInfo);
    }
}

string Abonent::GetFullName() const { return fullName; }
string Abonent::GetHomePhone() const { return homePhone; }
string Abonent::GetWorkPhone() const { return workPhone; }
string Abonent::GetMobilePhone() const { return mobilePhone; }


class PhoneBook {
    Abonent* abonents;
    int countAbonent;

public:
    explicit PhoneBook();
    ~PhoneBook();

    void Add(const Abonent& a);
    void Delete(string phone);
    void SearchByName(string name) const;
    void SearchByPhone(string phone) const;
    void ShowAll() const;

    void SaveAbonentToFile(int index, const string& filename) const;
    void LoadAbonentFromFile(const string& filename);
};

PhoneBook::PhoneBook() {
    abonents = nullptr;
    countAbonent = 0;
}

PhoneBook::~PhoneBook() {
    delete[] abonents;
}

void PhoneBook::Add(const Abonent& a) {
    Abonent* temp = new Abonent[countAbonent + 1];
    for (int i = 0; i < countAbonent; ++i) {
        temp[i] = abonents[i];
    }
    temp[countAbonent] = a;
    delete[] abonents;
    abonents = temp;
    countAbonent++;
}

void PhoneBook::Delete(string phone) {
    int index = -1;
    for (int i = 0; i < countAbonent; ++i) {
        if (abonents[i].GetMobilePhone() == phone ||
            abonents[i].GetHomePhone() == phone ||
            abonents[i].GetWorkPhone() == phone) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Subscriber with phone " << phone << " not found\n";
        return;
    }

    Abonent* temp = new Abonent[countAbonent - 1];
    for (int i = 0, j = 0; i < countAbonent; ++i) {
        if (i != index) {
            temp[j++] = abonents[i];
        }
    }
    delete[] abonents;
    abonents = temp;
    countAbonent--;
    cout << "Subscriber successfully deleted\n";
}

void PhoneBook::SearchByName(string name) const {
    cout << "\n--- Search results for name: \"" << name << "\" ---\n";
    bool found = false;
    for (int i = 0; i < countAbonent; ++i) {
        if (abonents[i].GetFullName().find(name) != string::npos) {
            abonents[i].Show();
            found = true;
        }
    }
    if (!found) cout << "No subscribers found\n";
}

void PhoneBook::SearchByPhone(string phone) const {
    cout << "\n--- Search results for phone: \"" << phone << "\" ---\n";
    bool found = false;
    for (int i = 0; i < countAbonent; ++i) {
        if (abonents[i].GetMobilePhone() == phone ||
            abonents[i].GetHomePhone() == phone ||
            abonents[i].GetWorkPhone() == phone) {
            abonents[i].Show();
            found = true;
        }
    }
    if (!found) cout << "No subscribers found\n";
}

void PhoneBook::ShowAll() const {
    cout << "\n=== PHONE BOOK (" << countAbonent << " subscribers) ===\n";
    if (countAbonent == 0) {
        cout << "Phone book is empty.\n";
        return;
    }
    cout << left << setw(20) << "Name"
        << setw(15) << "Mobile Phone"
        << setw(15) << "Home Phone"
        << setw(15) << "Work Phone"
        << "Extra Info\n";
    cout << string(80, '-') << "\n";
    for (int i = 0; i < countAbonent; ++i) {
        abonents[i].Show();
    }
}

void PhoneBook::SaveAbonentToFile(int index, const string& filename) const {
    if (index >= 0 && index < countAbonent) {
        ofstream out(filename);
        abonents[index].SaveToFile(out);
        out.close();
        cout << "Subscriber saved to file\n";
    }
    else {
        cout << "Invalid index\n";
    }
}

void PhoneBook::LoadAbonentFromFile(const string& filename) {
    ifstream in(filename);
    if (in.is_open()) {
        Abonent temp;
        temp.LoadFromFile(in);
        in.close();
        Add(temp);
        cout << "Subscriber loaded from file\n";
    }
    else {
        cout << "Error\n";
    }
}

int main() {
    PhoneBook myBook;

    myBook.Add(Abonent("John Doe", "02-123", "02-987", "0971112233", "Colleague"));
    myBook.Add(Abonent("Alice Smith", "0634445566"));
    myBook.Add(Abonent("Bob Johnson", "-", "-", "0507778899", "Doctor"));

    myBook.ShowAll();

    myBook.SaveAbonentToFile(0, "subscriber.txt");

    myBook.Delete("0634445566");
    myBook.ShowAll();

    myBook.SearchByName("Bob");

    myBook.LoadAbonentFromFile("subscriber.txt");
    myBook.ShowAll();
}
