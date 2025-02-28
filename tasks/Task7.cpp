#include "Task7.h"
#include "Util.h"
#include <cmath>
#include <iostream>

Task7::Task7(std::string headerValue)
{
	this->initializeMenu(headerValue);
}

Task7::~Task7()
{
}

void Task7::manualItems()
{
	Point* point = new Point();
	
	std::cin >> *point;
	std::cout << "The distance from the point to the origin is: " << calculate_distance_to_start(point) << std::endl << std::endl;
	*point++;

	std::cout << "Postfix incremented by (1,1) coordinates of the point are: " << *point << std::endl;
	std::cout << "The distance from the point to the origin changed to: " << calculate_distance_to_start(point) << std::endl << std::endl;
	++*point;
	std::cout << "Prefix Incremented by (1,1) coordinates of the point are: " << *point << std::endl;
	std::cout << "The distance from the point to the origin changed to: " << calculate_distance_to_start(point) << std::endl << std::endl;

	delete point;
}

void Task7::randomItems()
{
	Point* point = new Point();
	point->setX(Util::randomDouble(0, 100));
	point->setY(Util::randomDouble(0, 100));
	std::cout << std::endl << *point << std::endl;
	std::cout << "The distance from the point to the origin is: " << calculate_distance_to_start(point) << std::endl << std::endl;
	*point++;
	std::cout << "Postfix incremented by (1,1) coordinates of the point are: " << *point << std::endl;
	std::cout << "The distance from the point to the origin changed to: " << calculate_distance_to_start(point) << std::endl << std::endl;
	++*point;
	std::cout << "Prefix Incremented by (1,1) coordinates of the point are: " << *point << std::endl;
	std::cout << "The distance from the point to the origin changed to: " << calculate_distance_to_start(point) << std::endl << std::endl;

	delete point;
}

double Task7::calculate_distance_to_start(Point* point)
{
	return std::sqrt(std::pow(point->getX(), 2) + std::pow(point->getY(), 2));
}
