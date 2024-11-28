#pragma once
#include "Task.h"
#include "Student.h"

class Task10 : public Task
{
public:
    Task10(std::string headerValue);
    ~Task10();
    void manualItems();
	void randomItems();
    Student* initRandomStudent();
    Student* initManualStudent();
};