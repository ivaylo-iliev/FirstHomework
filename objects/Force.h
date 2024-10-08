#pragma once
#include "Point.h"
#include <iostream>
class Force
{
private:
	Point applicationPoint;
	double direction = 0;
	double magnitude = 0;

public:
	Force();
	Force(double, double, double, double);
	Force(Point, double, double);
	~Force();
	void setApplicationPoint(Point);
	void setApplicationPoint(double, double);
	Point getApplicationPoint();
	void setDirection(double);
	double getDirection();
	void setMagnitude(double);
	double getMagnitude();
	void rotate(double);
	Force& operator+=(const Force&);

	friend Force operator+(const Force&, const Force&);
	friend std::ostream& operator<<(std::ostream& stream, const Force& force);
	friend std::istream& operator>>(std::istream& stream, Force& force);
};

