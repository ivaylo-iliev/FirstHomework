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

    std::string get_first_name();
    void set_first_name(std::string);
    std::string get_middle_name();
    void set_middle_name(std::string);
    std::string get_last_name();
    void set_last_name(std::string);
    std::string get_full_name();
    void set_full_name(std::string);

    friend std::ostream& operator<<(std::ostream& stream, const Person& person);
	friend std::istream& operator>>(std::istream& stream, Person& person);
};