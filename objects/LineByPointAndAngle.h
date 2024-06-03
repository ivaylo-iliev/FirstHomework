#pragma once

#include "Point.h"

class LineByPointAndAngle
{
private:
	Point pt;
	double angle;
	Point lineTroughPoint;

public:
	LineByPointAndAngle();
	LineByPointAndAngle(Point pt, double angle);
	~LineByPointAndAngle();

	void setPoint(Point pt);
	void setPoint(double x, double y);
	void setAngle(double angle);
	Point getPoint();
	double getAngle();
	double calculateIntersectionWithXAxis();

	LineByPointAndAngle operator*(const std::pair<Point, std::pair<double, double>>& rotationParams);
	friend std::ostream& operator<<(std::ostream& stream, const LineByPointAndAngle& line);
	friend std::istream& operator>>(std::istream& stream, LineByPointAndAngle& line);
};

