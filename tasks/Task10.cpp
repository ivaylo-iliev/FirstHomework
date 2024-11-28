#include "Task10.h"
#include "faker-cxx/person.h"
#include "faker-cxx/string.h"
#include "Util.h"
#include <cmath>    

Task10::Task10(std::string headerValue)
{
    this->initializeMenu(headerValue);
}

Task10::~Task10()
{
}

void Task10::manualItems()
{
    std::cout << "Enter details for the first student:" << std::endl;
    Student* student1 = initManualStudent();

    std::cout << "Enter details for the second student:" << std::endl;
    Student* student2 = initManualStudent();

    std::cout << "First student: " << std::endl;
    std::cout << *student1 << std::endl << std::endl;

    std::cout << "Second student: " << std::endl;
    std::cout << *student2 << std::endl << std::endl;

    std::cout << "Student " << (*student1 > *student2 ? 1 : 2) << " has greater GPA." << std::endl;

    delete student1;
    delete student2;
}

void Task10::randomItems()
{
    Student* student1 = initRandomStudent();
    std::cout << "First student: " << std::endl;
    std::cout << *student1 << std::endl << std::endl;
    
    Student* student2 = initRandomStudent();
    std::cout << "Second student: " << std::endl;
    std::cout << *student2 << std::endl << std::endl;

    std::cout << "Student " << (*student1 > *student2 ? 1 : 2) << " has greater GPA." << std::endl;

    delete student1;
    delete student2;
}

Student* Task10::initRandomStudent()
{
    const auto first_name =  faker::person::firstName();
    const auto middle_name = faker::person::lastName();
    const auto last_name = faker::person::lastName();
    const auto faculty_numer = faker::string::uuid();

    Student* student = new Student();
    student->setFirstName({first_name.begin(), first_name.end()});
    student->setMiddleName({middle_name.begin(), middle_name.end()});
    student->setLastName({last_name.begin(), last_name.end()});
    student->setFacultyNumber({faculty_numer.begin(), faculty_numer.end()});
    
    for(int i = 0; i < MAX_GRADES_COUNT; i++){
        double grade = std::ceil(Util::randomDouble(2, 6) * 100) / 100;
        student->grades.push_back(grade);
    }
    student->calculateGPA();

    return student;
}

Student* Task10::initManualStudent()
{
    Student* student = new Student();
    std::cin >> *student;
    student->calculateGPA();
    std::cout << std::endl;
    return student;
}