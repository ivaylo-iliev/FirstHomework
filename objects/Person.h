#pragma once
#include <string>

class Person
{
private:
    std::string first_name;
    std::string middle_name;
    std::string last_name;
public:
    Person();
    ~Person();

    std::string getFirstName();
    void setFirstName(std::string);
    std::string getMiddleName();
    void setMiddleName(std::string);
    std::string getLastName();
    void setLastName(std::string);
    std::string getFullName();
    void setFullName(std::string);

    friend std::ostream& operator<<(std::ostream& stream, const Person& person);
	friend std::istream& operator>>(std::istream& stream, Person& person);
};