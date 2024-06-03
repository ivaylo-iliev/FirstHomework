#define _USE_MATH_DEFINES

#include "LineByPointAndAngle.h"
#include <cmath>
#include <iomanip>
#include <Util.h>

LineByPointAndAngle::LineByPointAndAngle()
{
	this->setPoint(0, 0);
	this->angle = 0;
}

LineByPointAndAngle::LineByPointAndAngle(Point pt, double angle)
{
	this->setPoint(pt);
	this->setAngle(angle);
}

LineByPointAndAngle::~LineByPointAndAngle()
{
}

void LineByPointAndAngle::setPoint(Point pt)
{
	this->pt = pt;
}

void LineByPointAndAngle::setPoint(double x, double y)
{
	this->pt.setX(x);
	this->pt.setY(y);
}

void LineByPointAndAngle::setAngle(double angle)
{
	this->angle = angle;
}

Point LineByPointAndAngle::getPoint()
{
	return this->pt;
}

double LineByPointAndAngle::getAngle()
{
	return this->angle;
}

double LineByPointAndAngle::calculateIntersectionWithXAxis()
{
	double angleInRadians = Util::degrees_to_radians(angle);
	if (std::tan(angleInRadians) == 0)
	{
		std::cerr << "The line is parallel to the x-axis and does not intersect it." << std::endl;
		return pt.getX(); // In this case, it intersects at the original point's x value
	}
	return pt.getX() - pt.getY() / std::tan(angle);
}

LineByPointAndAngle operator*(const std::pair<std::pair<Point, Point>, std::pair<double, double>>& rotationParams)
{
	Point originalPoint = rotationParams.first.second;
	Point rotationPoint = rotationParams.first.second;

	double originalAngle = rotationParams.second.first;
	double rotationAngle = rotationParams.second.second;;

	double rotationAngleInRadians = Util::degrees_to_radians(rotationAngle);
	double originalAngleInRadians = Util::degrees_to_radians(originalAngle);

	double newAngleInRadians = originalAngleInRadians + rotationAngleInRadians;

	double dx = originalPoint.getX() - rotationPoint.getX();
	double dy = originalPoint.getY() - rotationPoint.getY();

	double cosAngle = std::cos(rotationAngleInRadians);
	double sinAngle = std::sin(rotationAngleInRadians);

	double newX = rotationPoint.getX() + dx * cosAngle - dy * sinAngle;
	double newY = rotationPoint.getY() + dx * sinAngle + dy * cosAngle;

	double angleInDegrees = Util::radians_to_degrees(newAngleInRadians);
	return LineByPointAndAngle(Point(newX, newY), angleInDegrees);
}

std::ostream &operator<<(std::ostream &stream, const LineByPointAndAngle &line)
{
	stream << line.pt << std::endl;
	stream << "Angle with the abscissa : " << std::setprecision(5) << line.angle << std::endl;
	return stream;
}

std::istream &operator>>(std::istream &stream, LineByPointAndAngle &line)
{
	return stream;
}
