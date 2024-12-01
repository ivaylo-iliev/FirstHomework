#pragma once
#include "Task.h"
#include "PointInSpace.h"

class Task6 : public Task
{
public:
	Task6(std::string headerValue);
	~Task6();
	void manualItems();
	void randomItems();

	double calculateDistanceToStart(PointInSpace* point);
	PointInSpace operator-();
};

