#pragma once
#include "Task.h"
#include "Student.h"

class Task10 : public Task
{
public:
    Task10(std::string header_value);
    ~Task10();
    void manual_items();
	void random_items();
    Student* init_random_student();
    Student* init_manual_student();
};