#pragma once
#include "Task.h"
#include "Matrix.h"

class Task2 : public Task
{
private:
	Matrix matrix1, matrix2;
	void manualItems();
	void randomItems();
	void doCalculations();

public:
	Task2(std::string header_value);
	~Task2();
};

