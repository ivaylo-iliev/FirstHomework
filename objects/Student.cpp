#include "Student.h"
#include <iostream>
#include <iomanip>

Student::Student(){
}

Student::~Student()
{
}

std::string Student::getFacultyNumber()
{
    return this->facultyNumber;
}

void Student::setFacultyNumber(std::string value)
{
    this->facultyNumber = value;
}

std::ostream& operator<<(std::ostream& stream, const Student& student)
{
    stream << static_cast<const Person&>(student);
    stream << "Faculty number: " << student.facultyNumber << std::endl;
    stream << "Grades: [ ";
    for(int i = 0; i < MAX_GRADES_COUNT; i++){
        stream << std::setprecision(5) <<  student.grades[i];
        if(i < 4)
        {
            stream << ", ";
        }
    }
    stream << " ]" << std::endl;
    stream << "Student's GPA is: " << student.gpa;
    return stream;
}

std::istream& operator>>(std::istream& stream, Student& student)
{
    stream >> static_cast<Person&>(student);

    std::cout << "Enter faculty number: ";
    stream >> student.facultyNumber;
    
    for(int i = 0; i < MAX_GRADES_COUNT; i++ )
    {
        std::cout << "Enter grade number " << i + 1 << ": ";
        double grade = 0;
        stream >> grade;
        student.grades.push_back(grade);
    }

    return stream;
}

void Student::calculateGPA(){
    double grades_sum = 0;
    for(int i = 0; i < MAX_GRADES_COUNT; i++){
        grades_sum += this->grades[i];
    }

    std::cout << grades_sum;
    this->gpa = grades_sum/MAX_GRADES_COUNT;
}

bool operator>(const Student& rhs, const Student& lhs)
{
    return rhs.gpa > lhs.gpa;
}