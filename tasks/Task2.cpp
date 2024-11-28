#include "Task2.h"
#include "Matrix.h"
#include "Util.h"
#include <iostream>

void Task2::manualItems()
{
	Matrix* matrix1 = new Matrix();
	Matrix* matrix2 = new Matrix();
	matrix1->initValues(false);
	matrix2->initValues(false);
	doCalculations(*matrix1, *matrix2);

	delete matrix1;
	delete matrix2;
}

void Task2::randomItems()
{
	Matrix* matrix1 = new Matrix(2,2);
	Matrix* matrix2 = new Matrix(2,2);
	
	matrix1->initValues(true);
	matrix2->initValues(true);

	doCalculations(*matrix1, *matrix2);

	delete matrix1;
	delete matrix2;
}

void Task2::doCalculations(Matrix& matrix1, Matrix& matrix2)
{
	std::cout << matrix1;
	std::cout << matrix2;

	Matrix sum_matrix = matrix1 + matrix2;
	std::cout << sum_matrix;	
}

Task2::Task2(std::string headerValue)
{
	this->initializeMenu(headerValue);
}

Task2::~Task2()
{

}

