#pragma once
#include "Task.h"
#include "SimpleFraction.h"

class Task5 : public Task
{
private:
	SimpleFraction fraction;
public:
	Task5(std::string header_value);
	~Task5();
	void manualItems();
	void randomItems();
};

