#include <iostream>
using namespace std;

class Time
{
	int h;
	int m;
	int s;
public:
	Time();
	Time(int h, int m, int s);
	explicit Time(int s);
	~Time();

	void PrintTime() const;
	void operator++();
	int ToS() const;
	Time operator+(const Time& other) const;
	Time operator-(const Time& other) const;
	Time operator*(int multiplier) const;
	Time operator/(int divisor) const;

	bool operator>(const Time& other) const;
	bool operator<(const Time& other) const;
	bool operator>=(const Time& other) const;
	bool operator<=(const Time& other) const;
	bool operator==(const Time& other) const;
	bool operator!=(const Time& other) const;
};

Time::Time()
{
	h = 0;
	m = 0;
	s = 0;
}

Time::Time(int h, int m, int s)
{
	this->h = h;
	this->m = m;
	this->s = s;
}

Time::Time(int s)
{
	this->h = s / 3600;
	this->m = s / 60 % 60;
	this->s = s % 60;
}

Time::~Time()
{
}

void Time::PrintTime() const {
	cout << h << ":" << m << ":" << s << "\n";
}

int Time::ToS() const {
	return h * 3600 + m * 60 + s;
}

void Time::operator++() {
	s++;
	if (s == 60) { s = 0; m++; }
	if (m == 60) { m = 0; h++; }
	if (h == 24) { h = 0; }
}

Time Time::operator+(const Time& other) const {
	int total_seconds = this->ToS() + other.ToS();
	return Time(total_seconds);
}

Time Time::operator-(const Time& other) const {
	int total_seconds = this->ToS() - other.ToS();
	return Time(total_seconds);
}

Time Time::operator*(int multiplier) const {
	int total_seconds = this->ToS() * multiplier;
	return Time(total_seconds);
}

Time Time::operator/(int divisor) const {
	int total_seconds = this->ToS() / divisor;
	return Time(total_seconds);
}

bool Time::operator>(const Time& other) const {
	return this->ToS() > other.ToS();
}

bool Time::operator<(const Time& other) const {
	return this->ToS() < other.ToS();
}

bool Time::operator>=(const Time& other) const {
	return this->ToS() >= other.ToS();
}

bool Time::operator<=(const Time& other) const {
	return this->ToS() <= other.ToS();
}

bool Time::operator==(const Time& other) const {
	return this->ToS() == other.ToS();
}

bool Time::operator!=(const Time& other) const {
	return this->ToS() != other.ToS();
}

int main()
{
	Time t1(15, 45, 30);
	Time t2(23, 59, 59);

	cout << "Time 1: "; t1.PrintTime();
	cout << "Time 2: "; t2.PrintTime();


	Time t_sum = t1 + t2;
	cout << "t1 + t2 = "; t_sum.PrintTime();

	Time t_sub = t1 - t2;
	cout << "t1 - t2 = "; t_sub.PrintTime();

	Time t_mul = t2 * 2;
	cout << "t2 * 2  = "; t_mul.PrintTime();

	Time t_div = t1 / 3;
	cout << "t1 / 3  = "; t_div.PrintTime();

	if (t1 > t2) {
		cout << "Time 1 is greater than Time 2\n";
	}

	if (t1 != t2) {
		cout << "Times are not equal\n";
	}

	++t2;
	cout << "New Time 2: "; t2.PrintTime();
}
