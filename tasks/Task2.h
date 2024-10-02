#pragma once
#include "Task.h"
#include "Matrix.h"

class Task2 : public Task
{
private:
	void manualItems();
	void randomItems();
	void doCalculations(Matrix& matrix1,Matrix& matrix2);

public:
	Task2(std::string headerValue);
	~Task2();
};

