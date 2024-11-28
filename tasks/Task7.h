#pragma once
#include "Task.h"
#include "Point.h"

class Task7 : public Task
{
private:
	Point point;

public:
	Task7(std::string headerValue);
	~Task7();
	void manualItems();
	void randomItems();

	double calculate_distance_to_start();
};

