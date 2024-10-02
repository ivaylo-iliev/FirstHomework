#pragma once
#include "Task.h"
#include "Circle.h"

class Task1 : public Task
{
private:
	void manualItems();
	void randomItems();
	void doCalculations(const Circle& c1, const Circle& c2);
	void calculateIntersectionPoints(const Circle& c1, const Circle& c2, double distance);
	static double calculateDistanceBetweenCircleCenters(const Circle& c1, const Circle& c2);
public:
	Task1(std::string headerValue);
	~Task1();
};

