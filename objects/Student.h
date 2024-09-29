#pragma once
#include "Person.h"
#include <vector>

constexpr int MAX_GRADES_COUNT = 5;

class Student : public Person
{
private:
    std::string faculty_number;
    double gpa = 0;
public:
    Student();
    ~Student();
    
    std::vector<double> grades;
    std::string get_faculty_number();
    void set_faculty_number(std::string);

    void calculate_gpa();

    friend bool operator>(const Student& rhs, const Student& lhs);
    friend std::ostream& operator<<(std::ostream& stream, const Student& student);
	friend std::istream& operator>>(std::istream& stream, Student& student);
};