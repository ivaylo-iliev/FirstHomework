#pragma once
#include <vector>
#include "Circle.h"

class Util
{
public:
	static bool choiceIsValid(int choice);
	static std::vector<std::string> readTaskDefinitions();

	static int randomInt(int low, int high);
	static double randomDouble(double low, double high);

	static double findLineSlope(Point p1, Point p2);
	static double findLineSlopeInDegrees(Point p1, Point p2);
	static double findLineSlopeInDegrees(double slope_in_radians);
	static double radiansToDegrees(double radians);
	static Point calculateCircleToLineIntersect_pt(double radius, Point center, double slope_in_degrees);
	static Circle minimumEnclosingCircle(const std::vector<Point>& points);
	static Circle circleFrom(const Point& point1, const Point& point2, const Point& point3);
	static Point getCircleCenter(double x1, double y1, double x2, double y2);
	static Circle circleFrom(const Point& point1, const Point& point2);
	static double euclideanDistance(const Point& point1, const Point& point2);
	static bool isValidCircle(const Circle& circle, const std::vector<Point>& points);
	static bool pointInsideCircle(const Circle& circle, const Point& point);
	static double degreesToRadians(double degrees);
	static int greatestCommonDivisor(int a, int b);
	static std::string stringJoin(const std::vector<std::string>& lst, const std::string& delim);

	static int getCurrentYear();

	static void clearScreen();
	static void pause(bool);
	static std::string toLower(const std::string& s);
	static std::string trim(const std::string& s);
	static std::vector<std::string> splitString(std::string &value, char delimiter);
};

