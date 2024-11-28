#pragma once
#include "Task.h"
#include "SimpleFraction.h"

class Task5 : public Task
{
private:
	SimpleFraction fraction;
public:
	Task5(std::string headerValue);
	~Task5();
	void manualItems();
	void randomItems();
};

