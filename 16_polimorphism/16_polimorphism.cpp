#include <iostream>
using namespace std;

class Shape {
protected:
	string name;
	string type;

public:
	Shape();
	Shape(string name, string type);
	virtual ~Shape() {}

	virtual void Show() const;
	virtual double GetArea() const;
};

class Rectangle : public Shape {
	double width;
	double height;
public:
	Rectangle();
	Rectangle(string name, double width, double height);
	void Show() const override;
	double GetArea() const override;
};

class Circle : public Shape {
	double radius;
public:
	Circle();
	Circle(string name, double radius);
	void Show() const override;
	double GetArea() const override;
};

class RightTriangle : public Shape {
	double legA;
	double legB;
public:
	RightTriangle();
	RightTriangle(string name, double legA, double legB);
	void Show() const override;
	double GetArea() const override;
};

class Triangle : public Shape {
	double sideA;
	double sideB;
	double sideC;
public:
	Triangle();
	Triangle(string name, double sideA, double sideB, double sideC);
	void Show() const override;
	double GetArea() const override;
};

class Trapezoid : public Shape {
	double baseA;
	double baseB;
	double height;
public:
	Trapezoid();
	Trapezoid(string name, double baseA, double baseB, double height);
	void Show() const override;
	double GetArea() const override;
};


Shape::Shape() {
	name = "Unknown";
	type = "Generic Shape";
}

Shape::Shape(string name, string type) {
	this->name = name;
	this->type = type;
}

void Shape::Show() const {
	cout << "Shape Name: " << name << " | Type: " << type << endl;
}

double Shape::GetArea() const {
	return 0.0;
}

Rectangle::Rectangle() : Shape("Rectangle", "Quadrilateral") {
	width = 0;
	height = 0;
}

Rectangle::Rectangle(string name, double width, double height)
	: Shape(name, "Rectangle") {
	this->width = width;
	this->height = height;
}

void Rectangle::Show() const {
	Shape::Show();
	cout << "Parameters: Width = " << width << ", Height = " << height << endl;
}

double Rectangle::GetArea() const {
	return width * height;
}

Circle::Circle() : Shape("Circle", "Round") {
	radius = 0;
}

Circle::Circle(string name, double radius)
	: Shape(name, "Circle") {
	this->radius = radius;
}

void Circle::Show() const {
	Shape::Show();
	cout << "Parameters: Radius = " << radius << endl;
}

double Circle::GetArea() const {
	const double PI = 3.141592653589793;
	return PI * radius * radius;
}

RightTriangle::RightTriangle() : Shape("Right Triangle", "Triangle") {
	legA = 0;
	legB = 0;
}

RightTriangle::RightTriangle(string name, double legA, double legB)
	: Shape(name, "Right Triangle") {
	this->legA = legA;
	this->legB = legB;
}

void RightTriangle::Show() const {
	Shape::Show();
	cout << "Parameters: Leg A = " << legA << ", Leg B = " << legB << endl;
}

double RightTriangle::GetArea() const {
	return 0.5 * legA * legB;
}

Triangle::Triangle() : Shape("Triangle", "Triangle") {
	sideA = 0;
	sideB = 0;
	sideC = 0;
}

Triangle::Triangle(string name, double sideA, double sideB, double sideC)
	: Shape(name, "Triangle") {
	this->sideA = sideA;
	this->sideB = sideB;
	this->sideC = sideC;
}

void Triangle::Show() const {
	Shape::Show();
	cout << "Parameters: Side A = " << sideA << ", Side B = " << sideB << ", Side C = " << sideC << endl;
}

double Triangle::GetArea() const {
	double p = (sideA + sideB + sideC) / 2.0;
	double val = p * (p - sideA) * (p - sideB) * (p - sideC);
	if (val <= 0) return 0.0;
	return sqrt(val);
}

Trapezoid::Trapezoid() : Shape("Trapezoid", "Quadrilateral") {
	baseA = 0;
	baseB = 0;
	height = 0;
}

Trapezoid::Trapezoid(string name, double baseA, double baseB, double height)
	: Shape(name, "Trapezoid") {
	this->baseA = baseA;
	this->baseB = baseB;
	this->height = height;
}

void Trapezoid::Show() const {
	Shape::Show();
	cout << "Parameters: Base A = " << baseA << ", Base B = " << baseB << ", Height = " << height << endl;
}

double Trapezoid::GetArea() const {
	return ((baseA + baseB) / 2.0) * height;
}


void TestShape(const Shape& shape) {
	cout << "\n--- Shape Info ---\n";
	shape.Show();
	cout << "Area: " << shape.GetArea() << endl;
	cout << "------------------\n";
}


int main() {
	Rectangle rect("Rect-1", 5.0, 10.0);
	Circle circle("Circle-1", 4.0);
	RightTriangle rightTri("RightTri-1", 3.0, 4.0);
	Triangle tri("Triangle-1", 5.0, 6.0, 7.0);
	Trapezoid trap("Trapezoid-1", 6.0, 10.0, 4.0);

	int choice;
	do {
		cout << "\n=== Shape Polymorphism Menu ===\n";
		cout << "1. Test Rectangle\n";
		cout << "2. Test Circle\n";
		cout << "3. Test Right Triangle\n";
		cout << "4. Test General Triangle\n";
		cout << "5. Test Trapezoid\n";
		cout << "6. Test All Shapes\n";
		cout << "7. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			TestShape(rect);
			break;
		case 2:
			TestShape(circle);
			break;
		case 3:
			TestShape(rightTri);
			break;
		case 4:
			TestShape(tri);
			break;
		case 5:
			TestShape(trap);
			break;
		case 6:
			TestShape(rect);
			TestShape(circle);
			TestShape(rightTri);
			TestShape(tri);
			TestShape(trap);
			break;
		case 7:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice\n";
			break;
		}
	} while (choice != 7);

	return 0;
}
