#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Student {
private:
    string name;
    int age;
    int* marks;
    int marksCount;
    double averageMark;

    void SetAverageMark();

public:
    Student();
    Student(string name, int age);
    ~Student();

    void Print();
    void AddMark(int mark);
    void Save(string filename);
    void Load(string filename);

    string GetName();
    int GetAge();
    int GetMarksCount();
    double GetAverageMark();

    void SetName(string name);
    void SetAge(int age);
};

void Student::SetAverageMark() {
    if (marksCount == 0) {
        averageMark = 0.0;
        return;
    }
    int sum = 0;
    for (int i = 0; i < marksCount; ++i) {
        sum += marks[i];
    }
    averageMark = (double)sum / marksCount;
}

Student::Student() {
    name = "Unknown";
    age = 18;
    marks = nullptr;
    marksCount = 0;
    averageMark = 0.0;
}

Student::Student(string name, int age) {
    this->name = name;
    this->age = (age > 0) ? age : 18;
    marks = nullptr;
    marksCount = 0;
    averageMark = 0.0;
}

Student::~Student() {
    delete[] marks;
}

void Student::Print() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Marks count: " << marksCount << endl;
    cout << "Marks: ";
    if (marksCount == 0) {
        cout << "No marks yet";
    }
    else {
        for (int i = 0; i < marksCount; ++i) {
            cout << marks[i] << " ";
        }
    }
    cout << endl;
    cout << "Average mark: " << averageMark << endl;
    cout << "----------------------" << endl;
}

void Student::AddMark(int mark) {
    if (mark < 1 || mark > 12) {
        cout << "Error" << endl;
        return;
    }

    int* newMarks = new int[marksCount + 1];
    for (int i = 0; i < marksCount; ++i) {
        newMarks[i] = marks[i];
    }
    newMarks[marksCount] = mark;

    delete[] marks;
    marks = newMarks;
    marksCount++;

    SetAverageMark();
}

void Student::Save(string filename) {
    ofstream out(filename);
    if (!out.is_open()) {
        cout << "Error" << endl;
        return;
    }

    out << name << ":" << age << ":" << marksCount << ":";
    for (int i = 0; i < marksCount; ++i) {
        out << marks[i];
        if (i < marksCount - 1) {
            out << "|";
        }
    }
    out << ":" << averageMark << endl;
    out.close();
}

void Student::Load(string filename) {
    ifstream in(filename);
    if (!in.is_open()) {
        cout << "Error" << endl;
        return;
    }

    delete[] marks;
    marks = nullptr;
    marksCount = 0;

    string line;
    if (getline(in, line)) {
        string parts[5];
        int part_index = 0;
        string current_part = "";

        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ':') {
                parts[part_index] = current_part;
                part_index++;
                current_part = "";
            }
            else {
                current_part += line[i];
            }
        }
        parts[part_index] = current_part;

        name = parts[0];
        age = stoi(parts[1]);
        int savedCount = stoi(parts[2]);

        if (savedCount > 0) {
            marks = new int[savedCount];
            marksCount = savedCount;

            string markStr = "";
            int mark_index = 0;
            string Marks = parts[3];

            for (int i = 0; i < Marks.length(); ++i) {
                if (Marks[i] == '|') {
                    marks[mark_index] = stoi(markStr);
                    mark_index++;
                    markStr = "";
                }
                else {
                    markStr += Marks[i];
                }
            }
            marks[mark_index] = stoi(markStr);
        }

        averageMark = stod(parts[4]);
    }
    in.close();
}


string Student::GetName() {
    return name;
}

int Student::GetAge() {
    return age;
}

int Student::GetMarksCount() {
    return marksCount;
}

double Student::GetAverageMark() {
    return averageMark;
}

void Student::SetName(string name) {
     this->name = name;
}

void Student::SetAge(int age) {
        this->age = age;
}

int main() {
    Student student1("Serhii Tyrlych", 15);
    student1.AddMark(10);
    student1.AddMark(12);
    student1.AddMark(8);

    student1.Print();

    student1.Save("student.txt");

    Student student2;
    student2.Print();

    student2.Load("student.txt");
    student2.Print();
}
