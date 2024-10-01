#pragma once
#include "Task.h"
#include "Circle.h"

class Task1 : public Task
{
private:
	Circle c1;
	Circle c2;
	
	void manualItems();
	void randomItems();
	void doCalculations();
public:
	Task1(std::string header_value);
	void calculateCircleIntersectionPoints(double distanceBetweenCircles);
	static double calculateDistanceBetweenCircleCenters(Circle& c1, Circle& c2);
};

