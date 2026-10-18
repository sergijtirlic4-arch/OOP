#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Day
{
	unsigned short day, month, year;
};

class Student
{
	string name, surname, fathername, city, country, name_of_college, city_of_college, country_of_college, group_number;
	Day birthdate;
	unsigned long long phonenumber;
public:
	void AddStudent() {
		cout << "Enter name: ";					getline(cin, name);
		cout << "Enter surname: ";				getline(cin, surname);
		cout << "Enter fathername: ";           getline(cin, fathername);
		cout << "Enter birth date(day): ";      cin >> birthdate.day;
		cout << "Enter birth date(month): ";    cin >> birthdate.month;
		cout << "Enter birth date(year): ";     cin >> birthdate.year;
		cout << "Enter phone number: +";        cin >> phonenumber;
		cin.ignore();
		cout << "Enter city of residence: ";    getline(cin, city);
		cout << "Enter country of residence: "; getline(cin, country);
		cout << "Enter institution name: ";     getline(cin, name_of_college);
		cout << "Enter institution city: ";     getline(cin, city_of_college);
		cout << "Enter institution country: ";  getline(cin, country_of_college);
		cout << "Enter group number: ";         getline(cin, group_number);
	}

	void ShowStudent() {
		cout << "\n=== Student Info ===\n";
		cout << "Name: " << name << "\n";
		cout << "Surname: " << surname << "\n";
		cout << "Fatnername: " << fathername << "\n";
		cout << "Birth Date: " << birthdate.day << "." << birthdate.month << "." << birthdate.year << "." << "\n";
		cout << "Phone: " << phonenumber << "\n";
		cout << "Address: " << city << ", " << country << "\n";
		cout << "Institution: " << name_of_college << " (" << city_of_college << ", " << country_of_college << ")\n";
		cout << "Group: " << group_number << "\n";
		cout << "====================\n";
	}

	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}

	void setSurname(string surname) {
		this->surname = surname;
	}
	string getSurname() {
		return surname;
	}

	void setFathername(string fathername) {
		this->fathername = fathername;
	}
	string getFathername() {
		return fathername;
	}

	void setBirthdate(Day birthdate) {
		this->birthdate = birthdate;
	}
	Day getBirthdate() {
		return birthdate;
	}

	void setPhonenumber(unsigned long long phonenumber) {
		this->phonenumber = phonenumber;
	}
	unsigned long long getPhonenumber() {
		return phonenumber;
	}

	void setCity(string city) {
		this->city = city;
	}
	string getCity() {
		return city;
	}

	void setCountry(string country) {
		this->country = country;
	}
	string getCountry() {
		return country;
	}

	void setName_of_college(string name_of_college) {
		this->name_of_college = name_of_college;
	}
	string getName_of_college() {
		return name_of_college;
	}

	void setCity_of_college(string city_of_college) {
		this->city_of_college = city_of_college;
	}
	string getCity_of_college() {
		return city_of_college;
	}

	void setCountry_of_college(string country_of_college) {
		this->country_of_college = country_of_college;
	}
	string getCountry_of_college() {
		return country_of_college;
	}

	void setGroup_number(string group_number) {
		this->group_number = group_number;
	}
	string getGroup_number() {
		return group_number;
	}
};

class Point
{
	int x, y, z;
public:
	void EnterPoint() {
		cout << "Enter the x-coordinate"; cin >> x;
		cout << "Enter the y-coordinate"; cin >> y;
		cout << "Enter the z-coordinate"; cin >> z;
	}

	void ShowPoint() {
		cout << "X-coordinate" << x;
		cout << "Y-coordinate" << y;
		cout << "Z-coordinate" << z;
	}

	int setX(int x) {
		this->x = x;
	}
	int getX() {
		return x;
	}

	int setY(int y) {
		this->y = y;
	}
	int getY() {
		return y;
	}

	int setZ(int z) {
		this->z = z;
	}
	int getZ() {
		return z;
	}

	void SaveToFile(const string& filename) {
		ofstream outFile(filename);
		if (outFile.is_open()) {
			outFile << x << " " << y << " " << z;
			outFile.close();
			cout << "Data saved to file" << endl;
		}
		else {
			cout << "Error opening file" << endl;
		}
	}

	void LoadFromFile(const string& filename) {
		ifstream inFile(filename);
		if (inFile.is_open()) {
			inFile >> x >> y >> z;
			inFile.close();
			cout << "Data loaded from file" << endl;
		}
		else {
			cout << "Error opening file" << endl;
		}
	}
};

int main()
{
	Student student1;
	student1.AddStudent();
	student1.ShowStudent();

	student1.setGroup_number("CS-22");
	cout << "Updated group for student 2: " << student1.getGroup_number() << "\n";

	student1.ShowStudent();



	Point p1;

	p1.EnterPoint();
	cout << "\nYour point coordinates:" << endl;
	p1.ShowPoint();

	p1.SaveToFile("point_data.txt");

	p1.setX(100);
	p1.setY(200);
	p1.setZ(300);
	cout << "Modified point coordinates:" << endl;
	p1.ShowPoint();

	p1.LoadFromFile("point_data.txt");
	cout << "Point coordinates from file:" << endl;
	p1.ShowPoint();
}
