#include "Time.h"

Time::Time()
{
	hour = 0;
	minute = 0;
}

Time::Time(int h, int m)
{
	if (h > 24 || m > 59|| h < 0 || m < 0) {
		cerr << "Error";
		exit(1);
	}
	hour = h;
	minute = m;
}

Time::Time(Time& a)
{
	hour = a.hour;
	minute = a.minute;
}

Time::~Time()
{
}

Time& Time::operator=(Time& a)
{
	hour = a.hour;
	minute = a.minute;
	return *this;
	// TODO: вставьте здесь оператор return
}

ostream& operator<<(ostream& out, Time& a)
{
	out << a.hour << ":";
	if (a.minute > 9) {
		out << a.minute;
	}
	else {
		out << "0" << a.minute;
	}
	//out << a.hour << ":" << a.minute << endl;
	return out;
}

istream& operator>>(istream& in, Time& a)
{
	cout << "Hour: "; in >> a.hour;
	cout << "Minute: "; in >> a.minute;
	if (a.hour > 24 || a.minute > 59 || a.hour < 0 || a.minute < 0) {
		cerr << "Error";
		exit(1);
	}
	return in;
}

bool operator==(Time& first, Time& second)
{
	return (first.hour == second.hour && first.minute == second.minute);
}

bool operator>(Time& first, Time& second)
{
	return (first.hour > second.hour || (first.hour == second.hour && first.minute > second.minute));
}

bool operator<(Time& first, Time& second)
{
	return !(first > second)&& first != second;
}

bool operator!=(Time& first, Time& second)
{
	return !(first > second);
}
