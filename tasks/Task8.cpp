#include "Task8.h"
#include "Util.h"

Task8::Task8(std::string header_value)
{
    this->initialize_menu(header_value);
}

Task8::~Task8()
{
}

void Task8::manual_items()
{
    std::cout << "Enter values to set the Force: ";
    std::cin >> this->force;
    std::cout << "Initial force: " << this->force << std::endl;
    
    double rotation_angle;
    std::cout << "Provide rotation angle: ";
    std::cin >> rotation_angle;
    this->force.rotate(rotation_angle);
    std::cout << "Rotated force: " << this->force << std::endl;

    Force second_force;
    std::cout << "Enter values to set the second Force";
    std::cin >> second_force;
    std::cout << "Second force: " << second_force << std::endl;

    Force summary_force = this->force += second_force;
    std::cout << "The sum of the two forces is: " << summary_force << std::endl;
}

void Task8::random_items()
{
    Point application_point = Point(Util::random_double(0, 100), Util::random_double(0, 100));
    this->force = Force(application_point, Util::random_double(1, 100), Util::random_double(1, 100));
    std::cout << "Initial force: " << this->force <<std::endl; 

    double rotation_angle = Util::random_double(0, 360);
    std::cout << "Changing direction of the force by " << rotation_angle << " degrees... "<< std::endl;
    this->force.rotate(rotation_angle);
    std::cout << "Rotated force: " << this->force << std::endl; 

    Force second_force = Force(Point(Util::random_double(0, 100), Util::random_double(0, 100)), Util::random_double(1, 100), Util::random_double(1, 100));
    std::cout << "Second force: " << second_force << std::endl;

    Force summary_force = this->force += second_force;
    std::cout << "The sum of the two forces is: " << summary_force << std::endl;
}
