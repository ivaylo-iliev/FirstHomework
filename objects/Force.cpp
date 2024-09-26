#define _USE_MATH_DEFINES

#include "Force.h"
#include <cmath>

Force::Force()
{
	applicationPoint = Point(0,0);
	direction = 0;
	magnitude = 0;
}

Force::Force(double x, double y, double direction, double magnitude) 
{
	this->setApplicationPoint(Point(x, y));
	this->setDirection(direction);
	this->setMagnitude(magnitude);
}

Force::Force(Point point, double direction, double magnitude)
{
	this->setApplicationPoint(point);
	this->setDirection(direction);
	this->setMagnitude(magnitude);
}

Force::~Force()
{
}

void Force::setApplicationPoint(Point value)
{
	this->applicationPoint = value;
}

void Force::setApplicationPoint(double x, double y)
{
	this->applicationPoint = Point(x, y);
}

Point Force::getApplicationPoint()
{
	return this->applicationPoint;
}

void Force::setDirection(double value)
{
	this->direction = value;
}

double Force::getDirection()
{
	return this->direction;
}

void Force::setMagnitude(double value)
{
	this->magnitude = value;
}

double Force::getMagnitude()
{
	return this->magnitude;
}

void Force::rotate(double angle)
{
	direction += angle;;
    // Ensure direction stays within 0 to 360 degrees
    direction = fmod(direction, 360);
    if (direction < 0) direction += 360;
}

Force& Force::operator+=(const Force& rhs)
{
	// Decompose forces into x and y components
	double rad1 = this->direction * M_PI / 180;  // Convert degrees to radians
	double rad2 = rhs.direction * M_PI / 180;  // Convert degrees to radians

	double f1x = this->magnitude * cos(rad1);
	double f1y = this->magnitude * sin(rad1);
	double f2x = rhs.magnitude * cos(rad2);
	double f2y = rhs.magnitude * sin(rad2);

	// Parallelogram rule: Add components
	double result_x = f1x + f2x;
	double result_y = f1y + f2y;

	// Calculate the new magnitude and direction
	this->magnitude = sqrt(result_x * result_x + result_y * result_y);
	this->direction = atan2(result_y, result_x) * 180 / M_PI;  // Convert back to degrees
	return *this;
}

Force operator+(const Force& lhs, const Force& rhs)
{
	// Decompose forces into x and y components
	double rad1 = lhs.direction * M_PI / 180;  // Convert degrees to radians
	double rad2 = rhs.direction * M_PI / 180;  // Convert degrees to radians

	double f1x = lhs.magnitude * std::cos(rad1);
	double f1y = lhs.magnitude * std::sin(rad1);
	double f2x = rhs.magnitude * std::cos(rad2);
	double f2y = rhs.magnitude * std::sin(rad2);

	// Parallelogram rule: Add components
	double result_x = f1x + f2x;
	double result_y = f1y + f2y;

	// Calculate the new magnitude and direction
	double new_magnitude = std::sqrt(result_x * result_x + result_y * result_y);
	double new_direction = std::atan2(result_y, result_x) * 180 / M_PI;  // Convert back to degrees

	return Force(lhs.applicationPoint, new_direction, new_magnitude);
}

std::ostream& operator<<(std::ostream& stream, const Force& force)
{
	stream << force.applicationPoint << ", direction: " << force.direction << ", magnitude: " << force.magnitude << std::endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, Force& force)
{
	stream >> force.applicationPoint;
	std::cout << "Enter direction: ";
	stream >> force.direction;
	std::cout << "Enter magnitude: ";
	stream >> force.magnitude;

	return stream;
}

//Force& operator+=(const Force& other) 
//{
//	// Decompose forces into x and y components
//	double rad1 = direction * PI / 180;  // Convert degrees to radians
//	double rad2 = other.direction * PI / 180;  // Convert degrees to radians
//
//	double f1x = magnitude * cos(rad1);
//	double f1y = magnitude * sin(rad1);
//	double f2x = other.magnitude * cos(rad2);
//	double f2y = other.magnitude * sin(rad2);
//
//	// Parallelogram rule: Add components
//	double result_x = f1x + f2x;
//	double result_y = f1y + f2y;
//
//	// Calculate the new magnitude and direction
//	magnitude = sqrt(result_x * result_x + result_y * result_y);
//	direction = atan2(result_y, result_x) * 180 / PI;  // Convert back to degrees
//
//	return *this;
//}
