#include "Task6.h"
#include "Util.h"
#include <cmath>

Task6::Task6(std::string header_value)
{
	this->initializeMenu(header_value);
}

Task6::~Task6()
{
}

void Task6::manualItems()
{
	std::cout << "Enter point's coordinates:" << std::endl;
	std::cin >> point;
	std::cout << point << std::endl;
	std::cout << "The distance from the point to the origin is: " << this->calculateDistanceToStart() << std::endl;
	std::cout << "Symetric point is:" << -point << std::endl;
}

void Task6::randomItems()
{
	point.setX(Util::randomDouble(0, 100));
	point.setY(Util::randomDouble(0, 100));
	point.setZ(Util::randomDouble(0, 100));

	std::cout << point << std::endl;
	std::cout << "The distance from the point to the origin is: " << this->calculateDistanceToStart() << std::endl;
	std::cout << "Symetric point is:" << -point << std::endl;
}

double Task6::calculateDistanceToStart()
{
	return std::sqrt(std::pow(this->point.getX(), 2) + std::pow(this->point.getY() , 2) + std::pow(this->point.getZ(), 2));
}
