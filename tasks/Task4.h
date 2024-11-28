#pragma once
#include "Task.h"
#include "LineByPointAndAngle.h"

class Task4 : public Task
{
private:
	void manualItems();
	void randomItems();

	Point calculateIntersection(LineByPointAndAngle*);

public:
	Task4(std::string header_value);
	~Task4();
};

