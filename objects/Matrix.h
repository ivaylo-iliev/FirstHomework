#pragma once
#include <utility>
#include <iostream>



class Matrix
{
private:
	

	int** values;
	int determinant;
	int rank;
	int rows;
	int columns;
	int max_number_length;

	void initEmptyMatrix();
	void calculateMaxNumberLength();
	

public:
	Matrix();
	Matrix(int rows, int columns);
	~Matrix();

	void initValues(bool random);
	
	int getColumnCount();
	int getRowCount();
	int** getMatrixValues();
	void setValues();
	void setRandomValues(int maximum_value);
	void calculateDeterminant();
	void calculateRank();
	void calculateProperties();

	friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
	friend std::istream& operator>>(std::istream& stream, Matrix& matrix);
	friend Matrix operator+(const Matrix& m1, const Matrix& m2);
};

