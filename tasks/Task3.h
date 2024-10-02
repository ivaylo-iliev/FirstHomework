#pragma once
#include "Task.h"
#include "Matrix.h"

static const double EPS = 1E-9;

class Task3 : public Task
{
private:
	void gaussianElimination(Matrix& matrix);
	int calculateRank(Matrix& matrix);
	
public:
	Task3(std::string headerValue);
	~Task3();

	void manualItems();
	void randomItems();
	void doCalculations(Matrix& matrix1, Matrix& matrix2);
};

