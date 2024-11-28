#include "Task7.h"
#include "Util.h"
#include <cmath>

Task7::Task7(std::string headerValue)
{
	this->initializeMenu(headerValue);
}

Task7::~Task7()
{
}

void Task7::manualItems()
{
	std::cin >> point;
	std::cout << "The distance from the point to the origin is: " << this->calculate_distance_to_start() << std::endl << std::endl;
	point++;
	std::cout << "Postfix incremented by (1,1) coordinates of the point are: " << point << std::endl;
	std::cout << "The distance from the point to the origin changed to: " << this->calculate_distance_to_start() << std::endl << std::endl;
	++point;
	std::cout << "Prefix Incremented by (1,1) coordinates of the point are: " << point << std::endl;
	std::cout << "The distance from the point to the origin changed to: " << this->calculate_distance_to_start() << std::endl << std::endl;
}

void Task7::randomItems()
{
	point.setX(Util::randomDouble(0, 100));
	point.setY(Util::randomDouble(0, 100));
	std::cout << std::endl << point << std::endl;
	std::cout << "The distance from the point to the origin is: " << this->calculate_distance_to_start() << std::endl << std::endl;
	point++;
	std::cout << "Postfix incremented by (1,1) coordinates of the point are: " << point << std::endl;
	std::cout << "The distance from the point to the origin changed to: " << this->calculate_distance_to_start() << std::endl << std::endl;
	++point;
	std::cout << "Prefix Incremented by (1,1) coordinates of the point are: " << point << std::endl;
	std::cout << "The distance from the point to the origin changed to: " << this->calculate_distance_to_start() << std::endl << std::endl;
}

double Task7::calculate_distance_to_start()
{
	return std::sqrt(std::pow(point.getX(), 2) + std::pow(point.getY(), 2));
}
