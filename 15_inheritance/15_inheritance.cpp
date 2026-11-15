#include <iostream>
using namespace std;

class Student {
protected:
	string name;
	string surname;
	int age;
	string university;
	string group;
public:
	Student();
	Student(string name, string surname, int age, string university, string group);
	void PrintInfo() const;
};

class Aspirant : public Student {
	string thesisTopic;
	int writtenPages;
public:
	Aspirant();
	Aspirant(string name, string surname, int age, string university, string group, string thesisTopic, int writtenPages);
	void WriteDissertation(int pages);
	void DefendDissertation() const;
	void PrintInfo() const;
};


Student::Student() {
	name = "Unknown";
	surname = "Unknown";
	age = 18;
	university = "Unknown";
	group = "Unknown";
}

Student::Student(string name, string surname, int age, string university, string group) {
	this->name = name;
	this->surname = surname;
	this->age = age;
	this->university = university;
	this->group = group;
}

void Student::PrintInfo() const {
	cout << "Student: " << name << " " << surname << " | Age: " << age << endl;
	cout << "University: " << university << " | Group: " << group << endl;
}

Aspirant::Aspirant() : Student() {
	thesisTopic = "No topic";
	writtenPages = 0;
}

Aspirant::Aspirant(string name, string surname, int age, string university, string group, string thesisTopic, int writtenPages)
	: Student(name, surname, age, university, group) {
	this->thesisTopic = thesisTopic;
	this->writtenPages = writtenPages;
}

void Aspirant::WriteDissertation(int pages) {
	if (pages > 0) {
		writtenPages += pages;
		cout << "Added " << pages << " pages. Total written: " << writtenPages << endl;
	}
	else {
		cout << "Invalid number of pages" << endl;
	}
}

void Aspirant::DefendDissertation() const {
	cout << "\n--- Dissertation Defense ---\n";
	if (writtenPages >= 100) {
		cout << "Aspirant " << name << " " << surname << " successfully defended the thesis: \"" << thesisTopic << "\"!" << endl;
	}
	else {
		cout << "Not enough pages. Minimum required: 100. Currently written: " << writtenPages << endl;
	}
}

void Aspirant::PrintInfo() const {
	Student::PrintInfo();
	cout << "Thesis Topic: " << thesisTopic << " | Written pages: " << writtenPages << endl;
	cout << "------------------------------------------" << endl;
}

int main() {
	Aspirant aspirant("Ivan", "Petrenko", 24, "KPI", "CS-101", "Artificial Intelligence in Medicine", 85);

	int choice;
	do {
		cout << "\n=== Aspirant Menu ===\n";
		cout << "1. Show aspirant info\n";
		cout << "2. Write dissertation (add pages)\n";
		cout << "3. Defend dissertation\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			aspirant.PrintInfo();
		}
		else if (choice == 2) {
			int pages;
			cout << "Enter number of pages written: ";
			cin >> pages;
			aspirant.WriteDissertation(pages);
		}
		else if (choice == 3) {
			aspirant.DefendDissertation();
		}
		else if (choice != 4) {
			cout << "Invalid choice\n";
		}

	} while (choice != 4);
}
