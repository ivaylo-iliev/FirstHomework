#define _USE_MATH_DEFINES

#include "Util.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <random>
#include <climits>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <ranges>


bool Util::choiceIsValid(int choice)
{
	return (choice > 0 && choice < 26) ? true : false;
}

std::vector<std::string> Util::readTaskDefinitions()
{
	std::vector<std::string> task_definitions;
	std::fstream data_file;
	data_file.open("TaskDefinitions.txt", std::ios::in);
	std::string line;

	if (data_file.is_open()) {
		while (std::getline(data_file, line))
		{
			task_definitions.push_back(line);
		}
		data_file.close();
	}

	return task_definitions;
}

int Util::randomInt(int low, int high)
{
    static std::random_device rd;        // Random device for seed
    static std::mt19937 generator(rd()); // Initialize the generator with the seed
    std::uniform_int_distribution<int> distribution(low, high);
    return distribution(generator);
}

double Util::randomDouble(double low, double high)
{
    static std::random_device rd;         // Random device for seeding
    static std::mt19937 generator(rd());  // Mersenne Twister generator seeded by rd
    std::uniform_real_distribution<double> distribution(low, high);
    return distribution(generator);
}


double Util::findLineSlope(Point p1, Point p2)
{
	if (p2.getX() - p1.getX() != 0)
	{
		double raise = p2.getY() - p1.getY();
		double run = p2.getX() - p1.getX();
		double rise_over_run = raise / run;
		return std::atan(rise_over_run);
	}

	return INT_MAX;
}

double Util::findLineSlopeInDegrees(Point p1, Point p2)
{
	double slope_in_radians = Util::findLineSlope(p1, p2);
	return Util::findLineSlopeInDegrees(slope_in_radians);
}

double Util::findLineSlopeInDegrees(double slope_in_radians)
{
	return Util::radiansToDegrees(std::atan(slope_in_radians));
}

double Util::radiansToDegrees(double radians)
{
	return radians * (180 / M_PI);
}

Point Util::calculateCircleToLineIntersect_pt(double radius, Point center, double slope_in_radians)
{
	
	double x = radius * std::cos(slope_in_radians) + center.getX();
	double y = radius * std::sin(slope_in_radians) + center.getY();

	return Point(x, y);
}

// Helper method to get a circle defined by 3 points
Point Util::getCircleCenter(double x1, double y1, double x2, double y2)
{
	double A = std::pow(x1, 2) + std::pow(y1, 2);
	double B = std::pow(x2, 2) + std::pow(y2, 2);
	double C = x1 * y1 - y2 * x1;
	double x_result = (y2 * A - y1 * B) / (2 * C);
	double y_result = (x1 * B - x2 * A) / (2 * C);

	return Point(x_result, y_result);
}

// Function to return the euclidean distance between two points
double Util::euclideanDistance(const Point& point1, const Point& point2)
{
	double A = std::pow(point1.getX() - point2.getX(), 2);
	double B = std::pow(point1.getY() - point2.getY(), 2);

	return std::sqrt( A + B);
}

// Function to return the smallest circle that intersects 2 points
Circle Util::circleFrom(const Point& point1, const Point& point2)
{
	// Set the center to be the midpoint of point1 and point2
	double x_center = (point1.getX() + point2.getX()) / 2.0;
	double y_center = (point1.getY() + point2.getY()) / 2.0;
	Point center(x_center, y_center);

	// Set the radius to be half the distance between the two points
	double radius = euclideanDistance(point1, point2) / 2.0;
	return Circle(center, radius);
}

// Function to return a unique circle that intersects three points
Circle Util::circleFrom(const Point& point1, const Point& point2, const Point& point3)
{
	Point center = getCircleCenter(point2.getX() - point1.getX(), point2.getY() - point1.getY(), point3.getX() - point1.getX(), point3.getY() - point1.getY());
	double x_center = center.getX() + point1.getX();
	double y_center = center.getY() + point1.getY();

	center.setX(x_center);
	center.setY(y_center);

	return Circle(center, euclideanDistance(center, point1));
}

Circle Util::minimumEnclosingCircle(const std::vector<Point>& points)
{
	// Find the number of points
	int point_count = (int)points.size();

	if (point_count == 0)
		return Circle(Point(0,0), 0);
	if (point_count == 1)
		return Circle(points[0], 0);

	// Initialize a circle with center 0,0 and radius INT_MAX
	Circle result(Point(0, 0), INT_MAX);

	// Go over all pair of points
	for (int i = 0; i < point_count; i++) {
		for (int j = i + 1; j < point_count; j++) {
			// Get the smallest circle that intersects P[i] and P[j]
			Circle temp = circleFrom(points[i], points[j]);

			// Update the result if the circle encloses all points and has a smaller radius
			if (temp.getRadius() < result.getRadius() && isValidCircle(temp, points))
			{
				result = temp;
			}
		}
	}

	// Go over all triples of points

	for (int i = 0; i < point_count; i++)
	{
		for (int j = i + 1; j < point_count; j++)
		{
			for (int k = j + 1; k < point_count; k++)
			{
				// Get the circle that intersects all three points
				Circle temp = circleFrom(points[i], points[j], points[k]);

				// Update the result if the circle encloses all points and has a smaller radius
				if (temp.getRadius() < result.getRadius() && isValidCircle(temp, points))
				{
					result = temp;
				}
			}
		}
	}


	return result;
}

bool Util::isValidCircle(const Circle& circle, const std::vector<Point>& points)
{
	for (size_t i = 0; i < points.size(); i++)
	{
		if (!pointInsideCircle(circle, points[i]))
		{
			return false;
		}
	}

	return true;
}

bool Util::pointInsideCircle(const Circle& circle, const Point& point)
{
	// Due to issue in calculation with double values caused by high percision cast to int
	return (int) euclideanDistance(circle.getCenter(), point) <= (int) circle.getRadius();
	//return euclidean_distance(circle.getCenter(), point) <= circle.getRadius();
}

double Util::degreesToRadians(double degrees) {
	return degrees * M_PI / 180.0;
}

int Util::greatestCommonDivisor(int a, int b)
{
	if (b == 0) {
		return a;
	}

	return greatestCommonDivisor(b, a % b);
}

std::string Util::stringJoin(const std::vector<std::string>& lst, const std::string& delim)
{
	std::string result;
	for (size_t i = 0; i < lst.size(); i++) 
	{
		if (!result.empty())
			result += delim;
		result += lst[i];
	}
	return result;
}

int Util::getCurrentYear()
{
	std::time_t t = std::time(nullptr);
	std::tm *const pTInfo = std::localtime(&t);
	return 1900 + pTInfo->tm_year;
}

void Util::clearScreen()
{
	#if defined _WIN32
    system("cls");
		//clrscr(); // including header file : conio.h
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
		system("clear");
		//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
	#elif defined (__APPLE__)
		system("clear");
	#endif
}

void Util::pause(bool show_message)
{
	
	#if defined _WIN32 || defined(_WIN64)
    	system("pause");
	#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
		if (show_message) {
			std::cout << "Press Enter to continue...";
			std::cout.flush();
		}

		system("read");
	#endif
}

std::string Util::toLower(const std::string& s)
{
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}


std::string Util::trim(const std::string& s)
{
    auto start = s.begin();
    while (start != s.end() && std::isspace(static_cast<unsigned char>(*start))) {
        ++start;
    }

    auto end = s.end();
    do {
        --end;
    } while (end != start && std::isspace(static_cast<unsigned char>(*end)));

    return std::string(start, end + 1);
}

std::vector<std::string> Util::splitString(std::string &value, char delimiter)
{
	std::vector<std::string> items;
	std::stringstream value_stream(value);
	std::string item;

	while(getline(value_stream, item, delimiter))
	{
		items.push_back(item);
	}

	return items;
}
