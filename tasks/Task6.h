#pragma once
#include "Task.h"
#include "PointInSpace.h"
class Task6 : public Task
{
private:
	PointInSpace point;
public:
	Task6(std::string header_value);
	~Task6();
	void manualItems();
	void randomItems();

	double calculateDistanceToStart();
	PointInSpace operator-();
};

