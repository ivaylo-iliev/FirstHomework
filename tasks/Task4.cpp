
#define _USE_MATH_DEFINES

#include "Task4.h"
#include <cmath>
#include "Util.h"
#include "Point.h"

Task4::Task4(std::string header_value)
{
	this->initialize_menu(header_value);
}

void Task4::manual_items()
{
}

void Task4::random_items()
{
	Point pt = Point(Util::random_double(0, 100), Util::random_double(0, 100));
	double angle = Util::random_double(0, 90);
	this->line = new LineByPointAndAngle(pt, angle);
	this->line->calculateIntersectionWithXAxis();

}
 
Task4::~Task4()
{
	delete line;
}
