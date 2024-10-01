#include <iostream>
#include "Task1.h"
#include <cmath>
#include "Util.h"

Task1::Task1(std::string header_value)
{
	this->initializeMenu(header_value);
}

void Task1::manualItems()
{
	std::cin >> c1;
	std::cin >> c2;
	std::cout << c1 << c2;
	doCalculations();
}

void Task1::randomItems()
{
	Point c1_center;
	int max_random_value = 100;
	c1_center.setX(Util::randomDouble(0, max_random_value));
	c1_center.setY(Util::randomDouble(0, max_random_value));
	c1.setCenter(c1_center);
	c1.setRadius(Util::randomDouble(0, max_random_value));

	Point c2_center;
	c2_center.setX(Util::randomDouble(0, max_random_value));
	c2_center.setY(Util::randomDouble(0, max_random_value));
	c2.setCenter(c2_center);
	c2.setRadius(Util::randomDouble(0, max_random_value));

	std::cout << c1 << c2 << std::endl;

	doCalculations();
}

void Task1::doCalculations()
{
	double distance = calculateDistanceBetweenCircleCenters(c1, c2);

	calculateCircleIntersectionPoints(distance);
	if ((distance < abs(c1.getRadius() - c2.getRadius())))
	{
		if (c1.getRadius() < c2.getRadius())
			std::cout << "Minimum enclosing circle: " << c2 << std::endl;
		else
			std::cout << "Minimum enclosing circle: " << c1 << std::endl;
		return;
	} 

	if (distance == 0 && c1.getRadius() == c2.getRadius())
	{
		std::cout << "Minimum enclosing circle: " << c1 << std::endl;
		return;
	}
	
	Circle minimum_enclosing_circle = c1 + c2;
	std::cout << "Minimum enclosing circle: " << minimum_enclosing_circle << std::endl;
}

void Task1::calculateCircleIntersectionPoints(double distance_between_circles)
{
	if (distance_between_circles > (c1.getRadius() + c2.getRadius()))
	{
		std::cout << "The circles are too far apart and do not intersect." << std::endl;
		return;
	}

	if (distance_between_circles < abs(c1.getRadius() - c2.getRadius()))
	{
		std::cout << "One circle is inside the other and do not intersect." << std::endl;
		return;
	}

	if (distance_between_circles == 0 && c1.getRadius() == c2.getRadius())
	{
		std::cout << "The circles are merged and there are infinite number of intersection points." << std::endl;
		return;
	}


	double x1 = c1.getCenter().getX();
	double y1 = c1.getCenter().getY();
	double r1 = c1.getRadius();

	double x2 = c2.getCenter().getX();
	double y2 = c2.getCenter().getY();
	double r2 = c2.getRadius();

	double a = (std::pow(r1, 2) - std::pow(r2, 2) + std::pow(distance_between_circles, 2)) / (2 * distance_between_circles);
	double b = (std::pow(r2, 2) - std::pow(r1, 2) + std::pow(distance_between_circles, 2)) / (2 * distance_between_circles);

	double h = std::sqrt(std::pow(r1, 2) - std::pow(a, 2));

	// Calculate P5
	double x5 = x1 + (a / distance_between_circles) * (x2 - x1);
	double y5 = y1 + (a / distance_between_circles) * (y2 - y1);


	// Calculate intersection points P3 and P4
	Point P3;
	P3.setX(x5 - ((h * (y2 - y1)) / distance_between_circles));
	P3.setY(y5 + ((h * (x2 - x1)) / distance_between_circles));

	Point P4;
	P4.setX(x5 + ((h * (y2 - y1)) / distance_between_circles));
	P4.setY(y5 - ((h * (x2 - x1)) / distance_between_circles));

	if (distance_between_circles == r1 + r2) {
		std::cout << "The circles touch and there is a single intersection point." << std::endl;
		std::cout << P3 << std::endl;
		return;
	}

	std::cout << "There are two intersection points:" << std::endl;
	std::cout << P3 << std::endl;
	std::cout << P4 << std::endl;
}

double Task1::calculateDistanceBetweenCircleCenters(Circle& circle1, Circle& circle2)
{
	Point center1 = circle1.getCenter();
	Point center2 = circle2.getCenter();

	double x2x1 = std::pow((center2.getX() - center1.getX()), 2);
	double y2y1 = std::pow((center2.getY() - center1.getY()), 2);
	double distance = std::sqrt(x2x1 + y2y1);

	return distance;
}
