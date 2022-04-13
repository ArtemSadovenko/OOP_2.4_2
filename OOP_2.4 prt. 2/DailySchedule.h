#pragma once
#include "DailyItem.h"

class DailySchedule
{
private:
	DaylyItem* item;
	bool* done;
	int n;
public:
	void create();

	int get_n() { return n; }
	bool get_done(int i) { return item[i].isDone; }

	void display();

	DailySchedule();
	DailySchedule(DaylyItem* it, bool* d, int m);
	DailySchedule(DailySchedule& a);
	~DailySchedule();

	friend ostream& operator << (ostream& out, DailySchedule& a);
	friend istream& operator >> (istream& in, DailySchedule& a);

	DailySchedule& operator =(DailySchedule& a);

	bool check();
	bool check_2();

	void append();
	void del(int i);
	void show_free();
	void i_done(int i);
};

