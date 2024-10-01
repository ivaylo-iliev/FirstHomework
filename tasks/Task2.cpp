#include "Task2.h"
#include "Matrix.h"
#include "Util.h"
#include <iostream>

void Task2::manualItems()
{
	matrix1.initValues(false);
	matrix2.initValues(false);
	doCalculations();
}

void Task2::randomItems()
{
	matrix1 = Matrix(2, 2);
	matrix1.initValues(true);

	matrix2 = Matrix(2, 2);
	matrix2.initValues(true);
	
	doCalculations();
}

void Task2::doCalculations()
{
	std::cout << matrix1;
	std::cout << matrix2;

	Matrix sum_matrix = matrix1 + matrix2;
	std::cout << sum_matrix;	
}

Task2::Task2(std::string header_value)
{
	this->initializeMenu(header_value);
}

Task2::~Task2()
{

}

