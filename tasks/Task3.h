#pragma once
#include "Task.h"
#include "Matrix.h"

static const double EPS = 1E-9;

class Task3 : public Task
{
private:
	Matrix matrix1, matrix2;
	void manualItems();
	void randomItems();
	void gaussianElimination(Matrix& matrix);
	int calculateRank(Matrix& matrix);
	void doCalculations();

public:
	Task3(std::string header_value);
	~Task3();
};

