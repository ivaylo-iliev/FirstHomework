#include "Task3.h"
#include "Util.h"
#include <vector>

void Task3::manualItems()
{
	Matrix* matrix1 = new Matrix(2,3);
	Matrix* matrix2 = new Matrix(2,3);

	std::cin >> *matrix1;
	std::cout << *matrix1 << std::endl;
	std::cin >> *matrix2;
	std::cout << *matrix2 << std::endl;
	doCalculations(*matrix1, *matrix2);

	delete matrix1;
	delete matrix2;
}

void Task3::randomItems()
{
	Matrix* matrix1 = new Matrix(2,3);
	Matrix* matrix2 = new Matrix(2,3);
	matrix1->initValues(true);
	std::cout << *matrix1 << std::endl;
	matrix2->initValues(true);
	std::cout << *matrix2 << std::endl;
	doCalculations(*matrix1, *matrix2);

	delete matrix1;
	delete matrix2;
}


void Task3::gaussianElimination(Matrix& matrix) {
	int n = matrix.getRowCount();
	int m = matrix.getColumnCount();
	int** matrix_values = matrix.getMatrixValues();

	for (int i = 0; i < n; i++) {
		// Find pivot row
		int maxRow = i;
		for (int j = i + 1; j < n; j++) {
			
			if (abs(matrix_values[j][i]) > abs(matrix_values[maxRow][i])) {
				maxRow = j;
			}
		}

		// Swap rows
		std::swap(matrix_values[i], matrix_values[maxRow]);

		// Check if matrix is singular
		if (matrix_values[i][i] == 0) {
			return;
		}

		// Normalize pivot row
		for (int j = i + 1; j < n; j++) {
			int ratio = matrix_values[j][i] / matrix_values[i][i];
			for (int k = i; k < m; k++) {
				matrix_values[j][k] -= ratio * matrix_values[i][k];
			}
		}
	}
}


int Task3::calculateRank(Matrix& matrix)
{
	gaussianElimination(matrix);
	int rank = 0;
	for (int i = 0; i < matrix.getRowCount(); i++) {
		bool isZeroRow = true;
		for (int j = 0; j < matrix.getColumnCount(); j++) {
			if (matrix.getMatrixValues()[i][j] != 0) {
				isZeroRow = false;
				break;
			}
		}
		if (!isZeroRow) {
			rank++;
		}
	}
	return rank;
}

void Task3::doCalculations(Matrix& matrix1, Matrix& matrix2)
{
	if (matrix1.getRowCount() != matrix1.getColumnCount()) {
		std::cout << "Rank: " << calculateRank(matrix1) << std::endl;
	}
	if (matrix1.getRowCount() != matrix1.getColumnCount()) {
		std::cout << "Rank: " << calculateRank(matrix2) << std::endl;
	}

	std::cout << std::endl << "The sum of the matrices is:" << std::endl;
	Matrix sum_matrix = matrix1 + matrix2;
	std::cout << sum_matrix;
	std::cout << "Rank: " << calculateRank(sum_matrix) << std::endl;
}



Task3::Task3(std::string headerValue)
{
	this->initializeMenu(headerValue);
}

Task3::~Task3()
{
}
