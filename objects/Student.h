#pragma once
#include "Person.h"
#include <vector>

const int MAX_GRADES_COUNT = 5;

class Student : public Person
{
private:
    std::string facultyNumber;
    double gpa = 0;
public:
    Student();
    ~Student();
    
    std::vector<double> grades;
    std::string getFacultyNumber();
    void setFacultyNumber(std::string);

    void calculateGPA();

    friend bool operator>(const Student& rhs, const Student& lhs);
    friend std::ostream& operator<<(std::ostream& stream, const Student& student);
	friend std::istream& operator>>(std::istream& stream, Student& student);
};