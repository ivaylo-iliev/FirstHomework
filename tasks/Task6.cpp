#include "Task6.h"
#include "Util.h"

#include <cmath>

Task6::Task6(std::string headerValue)
{
	this->initializeMenu(headerValue);
}

Task6::~Task6()
{
}

void Task6::manualItems()
{
	PointInSpace* point = new PointInSpace();
	std::cout << "Enter point's coordinates:" << std::endl;
	std::cin >> *point;
	std::cout << *point << std::endl;
	std::cout << "The distance from the point to the origin is: " << calculateDistanceToStart(point) << std::endl;
	std::cout << "Symetric point is:" << -*point << std::endl;

	delete point;
}

void Task6::randomItems()
{
	PointInSpace* point = new PointInSpace();
	point->setX(Util::randomDouble(0, 100));
	point->setY(Util::randomDouble(0, 100));
	point->setZ(Util::randomDouble(0, 100));

	std::cout << *point << std::endl;
	std::cout << "The distance from the point to the origin is: " << calculateDistanceToStart(point) << std::endl;
	std::cout << "Symetric point is:" << -*point << std::endl;

	delete point;
}

double Task6::calculateDistanceToStart(PointInSpace* point)
{
	return std::sqrt(std::pow(point->getX(), 2) + std::pow(point->getY() , 2) + std::pow(point->getZ(), 2));
}
