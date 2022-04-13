#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Time
{
public:
	int hour;
	int minute;
	Time();
	Time(int h, int m);
	Time(Time& a);
	~Time();

	friend ostream& operator << (ostream& out, Time& a);
	friend istream& operator >> (istream& in, Time& a);

	Time& operator =(Time& a);

	friend bool operator == (Time& first, Time& second);
	friend bool operator > (Time& first, Time& second);
	friend bool operator < (Time& first, Time& second);
	friend bool operator != (Time& first, Time& second);


};

