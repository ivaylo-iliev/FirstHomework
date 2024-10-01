#include "Person.h"
#include <vector>
#include <iomanip>
#include "Util.h"

Person::Person()
{

}

Person::~Person()
{

}

std::string Person::getFirstName()
{
    return this->first_name;
}

void Person::setFirstName(std::string value)
{
    this->first_name = value;
}

std::string Person::getMiddleName()
{
    return this->middle_name;
}

void Person::setMiddleName(std::string value){
    this->middle_name = value;
}

std::string Person::getLastName()
{
    return this->last_name;
}

void Person::setLastName(std::string value){
    this->last_name = value;
}

std::string Person::getFullName()
{
    std::string full_name = "";
    if(this->first_name != "")
    {
        full_name += (full_name != "" ? " " : "") + this->first_name;
    }

    if(this->middle_name != "")
    {
        full_name += (full_name != "" ? " " : "") + this->middle_name;
    }

    if(this->last_name != "")
    {
        full_name += (full_name != "" ? " " : "") + this->last_name;
    }

    return full_name;
}

void Person::setFullName(std::string value)
{
    std::vector<std::string> split_value = Util::splitString(value, ' ');
    switch(split_value.size())
    {
        case 1:
            this->first_name = split_value[0];
            break;
        case 2:
            this->first_name = split_value[0];
            this->last_name = split_value[1];
            break;
        case 3:
            this->first_name = split_value[0];
            this->middle_name = split_value[1];
            this->last_name = split_value[2];
            break;
        default:
            break;
    }
}

std::ostream& operator<<(std::ostream& stream, const Person& person)
{
    stream << "First name: " << person.first_name << std::endl;
    stream << "Middle name: " << person.middle_name << std::endl;
    stream << "Last name: " << person.last_name << std::endl;
    stream << std::right;
    return stream;
}

std::istream& operator>>(std::istream& stream, Person& person)
{
    std::string first_name;
    std::string middle_name;
    std::string last_name;

    std::cout << "Enter first name: ";
    stream >> first_name;
    std::cout << "Enter middle name: ";
    stream >> middle_name;
    std::cout << "Enter last name: ";
    stream >> last_name;

    person.setFirstName(first_name);
    person.setMiddleName(middle_name);
    person.setLastName(last_name);

    return stream;
}