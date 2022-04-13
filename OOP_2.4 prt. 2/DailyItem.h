#pragma once
#include "Time.h"

struct DaylyItem
{
	string name;
	string toDo;
	Time start;
	Time finish;
	bool isDone;
};