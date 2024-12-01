#include "Task8.h"
#include "Util.h"
#include "Force.h"

Task8::Task8(std::string headerValue)
{
    this->initializeMenu(headerValue);
}

Task8::~Task8()
{
}

void Task8::manualItems()
{
    Force* force = new Force();
    std::cout << "Enter values to set the Force: ";
    std::cin >> *force;
    std::cout << "Initial force: " << *force << std::endl;
    
    double rotation_angle;
    std::cout << "Provide rotation angle: ";
    std::cin >> rotation_angle;
    force->rotate(rotation_angle);
    std::cout << "Rotated force: " << *force << std::endl;

    Force* second_force = new Force();
    std::cout << "Enter values to set the second Force";
    std::cin >> *second_force;
    std::cout << "Second force: " << *second_force << std::endl;

    Force summary_force = *force += *second_force;
    std::cout << "The sum of the two forces is: " << summary_force << std::endl;
    
    delete force;
    delete second_force;
}

void Task8::randomItems()
{
    Point application_point = Point(Util::randomDouble(0, 100), Util::randomDouble(0, 100));
    Force* force = new Force(application_point, Util::randomDouble(1, 100), Util::randomDouble(1, 100));
    std::cout << "Initial force: " << *force <<std::endl; 

    double rotation_angle = Util::randomDouble(0, 360);
    std::cout << "Changing direction of the force by " << rotation_angle << " degrees... "<< std::endl;
    force->rotate(rotation_angle);
    std::cout << "Rotated force: " << *force << std::endl; 

    Force* second_force = new Force(Point(Util::randomDouble(0, 100), Util::randomDouble(0, 100)), Util::randomDouble(1, 100), Util::randomDouble(1, 100));
    std::cout << "Second force: " << *second_force << std::endl;

    Force summary_force = *force += *second_force;
    std::cout << "The sum of the two forces is: " << summary_force << std::endl;

    delete force;
    delete second_force;
}
