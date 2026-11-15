#include <iostream>
#include <string>
using namespace std;

class Passport {
protected:
	string fullName;
	string birthDate;
	string passportNumber;
	string registrationAddress;

public:
	Passport();
	Passport(string fullName, string birthDate, string passportNumber, string registrationAddress);
	void PrintInfo() const;
};

class ForeignPassport : public Passport {
private:
	string foreignPassportNumber;
	string* visas;
	int visaCount;

public:
	ForeignPassport();
	ForeignPassport(string fullName, string birthDate, string passportNumber, string registrationAddress, string foreignPassportNumber);
	~ForeignPassport();
	void AddVisa(string visaInfo);
	void PrintInfo() const;
};


Passport::Passport() {
	fullName = "Unknown";
	birthDate = "01.01.2000";
	passportNumber = "000000000";
	registrationAddress = "Unknown";
}

Passport::Passport(string fullName, string birthDate, string passportNumber, string registrationAddress) {
	this->fullName = fullName;
	this->birthDate = birthDate;
	this->passportNumber = passportNumber;
	this->registrationAddress = registrationAddress;
}

void Passport::PrintInfo() const {
	cout << "=== Citizen of Ukraine Passport ===\n";
	cout << "Full Name: " << fullName << endl;
	cout << "Birth Date: " << birthDate << endl;
	cout << "ID Number: " << passportNumber << endl;
	cout << "Address: " << registrationAddress << endl;
}


ForeignPassport::ForeignPassport() : Passport() {
	foreignPassportNumber = "XX000000";
	visas = nullptr;
	visaCount = 0;
}

ForeignPassport::ForeignPassport(string fullName, string birthDate, string passportNumber, string registrationAddress, string foreignPassportNumber)
	: Passport(fullName, birthDate, passportNumber, registrationAddress) {
	this->foreignPassportNumber = foreignPassportNumber;
	this->visas = nullptr;
	this->visaCount = 0;
}

ForeignPassport::~ForeignPassport() {
	if (visas != nullptr) {
		delete[] visas;
	}
}

void ForeignPassport::AddVisa(string visaInfo) {
	string* temp = new string[visaCount + 1];
	for (int i = 0; i < visaCount; i++) {
		temp[i] = visas[i];
	}
	temp[visaCount] = visaInfo;

	if (visas != nullptr) {
		delete[] visas;
	}
	visas = temp;
	visaCount++;
}

void ForeignPassport::PrintInfo() const {
	Passport::PrintInfo();
	cout << "--- Foreign Passport Details ---\n";
	cout << "Foreign Passport Number: " << foreignPassportNumber << endl;
	cout << "Visas (" << visaCount << "): ";
	if (visaCount == 0) {
		cout << "No visas\n";
	}
	else {
		cout << endl;
		for (int i = 0; i < visaCount; i++) {
			cout << "  " << i + 1 << ". " << visas[i] << endl;
		}
	}
	cout << "--------------------------------\n";
}

int main() {
	ForeignPassport fPassport("Kovalenko Olena Vasylivna", "15.05.1998", "001234567", "Kyiv, Khreshchatyk St, 1", "FE987654");

	int choice;
	do {
		cout << "\n=== Passport System Menu ===\n";
		cout << "1. Show passport info\n";
		cout << "2. Add visa\n";
		cout << "3. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 1) {
			fPassport.PrintInfo();
		}
		else if (choice == 2) {
			string visa;
			cout << "Enter visa details: ";
			cin.ignore();
			getline(cin, visa);
			fPassport.AddVisa(visa);
			cout << "Visa added successfully\n";
		}
		else if (choice != 3) {
			cout << "Invalid choice\n";
		}

	} while (choice != 3);
}
