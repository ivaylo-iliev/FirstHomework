#pragma once
#include "Task.h"
#include "Force.h"
class Task8 : public Task
{
private:
	Force force;

public:
	Task8(std::string header_value);
	~Task8();
	void manualItems();
	void randomItems();
};

