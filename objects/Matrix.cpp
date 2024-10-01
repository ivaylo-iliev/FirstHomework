#include "Matrix.h"
#include "Util.h"
#include <iomanip>
#include <string>

void Matrix::initEmptyMatrix()
{
	this->values = new int* [rows];
	for (int i = 0; i < columns; i++)
	{
		this->values[i] = new int[columns];
	}
}

void Matrix::calculateRank()
{
	
}

void Matrix::calculateProperties()
{
	this->calculateDeterminant();
	this->calculateMaxNumberLength();
}


Matrix::Matrix()
{
	this->rows = 2;
	this->columns = 2;
	this->initEmptyMatrix();
	
}

Matrix::Matrix(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;	
	initEmptyMatrix();
}

Matrix::~Matrix(){}

void Matrix::initValues(bool random)
{
	if (random) 
	{
		this->setRandomValues(100);
	}
	else 
	{
		this->setValues();
	}
	
}

int Matrix::getColumnCount()
{
	return this->columns;
}

int Matrix::getRowCount()
{
	return this->rows;
}

int** Matrix::getMatrixValues()
{
	return this->values;
}

void Matrix::setValues()
{
	Matrix initMatrix(rows, columns);
	std::cin >> initMatrix;
	this->values = initMatrix.values;
	this->calculateProperties();
	
}

void Matrix::setRandomValues(int maximum_value)
{
	for (int row_iterator = 0; row_iterator < rows; row_iterator++)
	{
		for (int col_iterator = 0; col_iterator < columns; col_iterator++)
		{
			values[row_iterator][col_iterator] = Util::randomInt(0, maximum_value);
			calculateProperties();
		}
	}
}

void Matrix::calculateDeterminant()
{
	if (rows != columns)
	{
		// Non-square matrices do not have determinants.
		this->determinant = NULL;
		return;
	}

	int col_iterator = 0;
	int first_diagonal = 1;
	for (int row_iterator = 0; row_iterator < rows; row_iterator++)
	{
		first_diagonal = first_diagonal * values[row_iterator][col_iterator];
		
		if (col_iterator < columns) {
			col_iterator++;
		}
	}

	col_iterator = 0;
	int second_diagnoal = 1;	
	for (int row_iterator = rows -1; row_iterator >= 0; row_iterator--)
	{
		second_diagnoal = second_diagnoal * values[row_iterator][col_iterator];
		if (col_iterator < columns) {
			col_iterator++;
		}
	}
	
	this->determinant = first_diagonal - second_diagnoal;	
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix)
{
	stream << "Matrix: " << std::endl;

	for (int row_iterator = 0; row_iterator < matrix.rows; row_iterator++)
	{
		stream << std::setw(2) << std::setfill(' ') << '|';
		for (int col_iterator = 0; col_iterator < matrix.columns; col_iterator++)
		{
			stream << std::setw(matrix.max_number_length) << matrix.values[row_iterator][col_iterator];
		}
		stream << std::setw(2) << '|' << std::endl;
	}

	if (matrix.determinant != NULL)
	{
		stream << std::endl << "Determinant: " << matrix.determinant << std::endl;
	}

	return stream;
}

std::istream& operator>>(std::istream& stream, Matrix& matrix)
{
	std::cout << "Enter values for the matrix." << std::endl;
	for (int i = 0; i < matrix.getRowCount(); i++)
	{
		for (int j = 0; j < matrix.getColumnCount(); j++)
		{
			std::cout << "element[" << i + 1 << "][" << j + 1 << "] = ";
			stream >> matrix.values[i][j];
			std::cout << matrix.values[i][j] << std::endl;
		}
	}

	std::cout << matrix << std::endl;
	matrix.calculateProperties();

	return stream;
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	int rows = m1.rows;
	int columns = m1.columns;
	
	Matrix result(rows, columns);

	for (int row_iterator = 0; row_iterator < rows; row_iterator++) 
	{
		for (int col_iterator = 0; col_iterator < columns; col_iterator++)
		{
			result.values[row_iterator][col_iterator] = m1.values[row_iterator][col_iterator] + m2.values[row_iterator][col_iterator];
		}
	}

	result.calculateProperties();
	return result;
}

void Matrix::calculateMaxNumberLength()
{
	int length = 1;
	for (int row_iterator = 0; row_iterator < rows; row_iterator++)
	{
		for (int col_iterator = 0; col_iterator < columns; col_iterator++)
		{
			int val_size = std::to_string(values[row_iterator][col_iterator]).size();

			if (val_size > length)
			{
				length = val_size;
			}
		}
	}
	max_number_length = length + 1;
}