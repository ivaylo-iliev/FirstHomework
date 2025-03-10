
#define _USE_MATH_DEFINES

#include "Task4.h"
#include <cmath>
#include "Util.h"
#include "Point.h"

Task4::Task4(std::string header_value)
{
	this->initializeMenu(header_value);
}

void Task4::manualItems()
{
	LineByPointAndAngle *line = new LineByPointAndAngle();
	std::cin >> *line;
	std::cout << *line;
	Point intersectionPoint = this->calculateIntersection(line);
	std::cout << "Abscissa intersection point before retoation is: " << intersectionPoint << std::endl;

	intersectionPoint = this->calculateIntersection(line);

	*line = *line * 90;
	std::cout << *line;
	intersectionPoint = calculateIntersection(line);
	std::cout << "Abscissa intersection point is: " << intersectionPoint << std::endl;

	delete line;
}

void Task4::randomItems()
{
	Point pt = Point(Util::randomDouble(0, 100), Util::randomDouble(0, 100));
	double angle = Util::randomDouble(0, 90);
	LineByPointAndAngle* line = new LineByPointAndAngle(pt, angle);

	std::cout << *line;
	Point intersectionPoint = this->calculateIntersection(line);
	std::cout << "Abscissa intersection point before retoation is: " << intersectionPoint << std::endl;

	intersectionPoint = this->calculateIntersection(line);
	
	*line = *line * 90;
	std::cout << *line;
	intersectionPoint = calculateIntersection(line);
	std::cout << "Abscissa intersection point is: " << intersectionPoint << std::endl;
}
 
Task4::~Task4()
{
}

Point Task4::calculateIntersection(LineByPointAndAngle* line)
{
	Point pt = line->getPoint();
	double angle = line->getAngle();

	double slope = tan(angle * M_PI / 180);
	double y_intercept = pt.getY() - slope * pt.getX();
	double x_intercect = -y_intercept / slope;
	double y_intercect = 0;

	return Point(x_intercect, y_intercect);
}
