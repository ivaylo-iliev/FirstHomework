#include "Task10.h"
#include "faker-cxx/person.h"
#include "faker-cxx/string.h"
#include "Util.h"
#include <cmath>    

Task10::Task10(std::string header_value)
{
    this->initialize_menu(header_value);
}

Task10::~Task10()
{
}

void Task10::manual_items()
{
    std::cout << "Enter details for the first student:" << std::endl;
    Student* student1 = init_manual_student();

    std::cout << "Enter details for the second student:" << std::endl;
    Student* student2 = init_manual_student();

    std::cout << "First student: " << std::endl;
    std::cout << *student1 << std::endl << std::endl;

    std::cout << "Second student: " << std::endl;
    std::cout << *student2 << std::endl << std::endl;

    std::cout << "Student " << (*student1 > *student2 ? 1 : 2) << " has greater GPA." << std::endl;

    delete student1;
    delete student2;
}

void Task10::random_items()
{
    Student* student1 = init_random_student();
    std::cout << "First student: " << std::endl;
    std::cout << *student1 << std::endl << std::endl;
    
    Student* student2 = init_random_student();
    std::cout << "Second student: " << std::endl;
    std::cout << *student2 << std::endl << std::endl;

    std::cout << "Student " << (*student1 > *student2 ? 1 : 2) << " has greater GPA." << std::endl;

    delete student1;
    delete student2;
}

Student* Task10::init_random_student()
{
    const auto first_name =  faker::person::firstName();
    const auto middle_name = faker::person::lastName();
    const auto last_name = faker::person::lastName();
    const auto faculty_numer = faker::string::uuid();

    Student* student = new Student();
    student->set_first_name({first_name.begin(), first_name.end()});
    student->set_middle_name({middle_name.begin(), middle_name.end()});
    student->set_last_name({last_name.begin(), last_name.end()});
    student->set_faculty_number({faculty_numer.begin(), faculty_numer.end()});
    
    for(int i = 0; i < MAX_GRADES_COUNT; i++){
        double grade = std::ceil(Util::random_double(2, 6) * 100) / 100;
        student->grades.push_back(grade);
    }
    student->calculate_gpa();

    return student;
}

Student* Task10::init_manual_student()
{
    Student* student = new Student();
    std::cin >> *student;
    student->calculate_gpa();
    std::cout << std::endl;
    return student;
}