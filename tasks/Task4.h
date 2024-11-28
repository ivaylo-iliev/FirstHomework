#pragma once
#include "Task.h"
#include "LineByPointAndAngle.h"

class Task4 : public Task
{
private:
	// LineByPointAndAngle line;

	void manualItems();
	void randomItems();

	Point calculateIntersection();


public:
	Task4(std::string header_value);
	~Task4();
};

