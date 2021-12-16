//

#include "MTX.h"


using namespace std;
class Matrix {
public:
	vector<vector<int>> _matrix;//store the data
	Matrix transpose();//transpose method
	Matrix operator*(const Matrix& matrix);//multiplication method
	bool equals(const Matrix& matrix);//method that check whether two methods are of the same
	void display();//print out the matrix on the screen
};

//transpose method, return the transposed matrix
Matrix Matrix::transpose() {

	vector<vector<int>> temp(_matrix[0].size(), vector<int>(_matrix.size()));
	Matrix res;
	res._matrix = temp;
	//Change the i,j entry with j,i 
	for (int i = 0; i < _matrix.size(); i++)
	{
		for (int j = 0; j < _matrix[i].size(); j++) {
			res._matrix[j][i] = _matrix[i][j];
		}
	}
	return res;
}

//matrix multiplication
Matrix Matrix::operator*(const Matrix& matrix) {
	// if the column size of the first matrix is not the same as the row size of the second one 
	if (_matrix[0].size() != matrix._matrix.size())
	{
		cout << "Matrices size mismatch!" << endl;
		Matrix res;
		res.display();
		return res;
	}

	vector<vector<int>> temp(_matrix.size(), vector<int>(matrix._matrix[0].size()));
	Matrix res;
	res._matrix = temp;

	//Matrix multiplication
	for (int i = 0; i < _matrix.size(); i++)
	{
		for (int j = 0; j < matrix._matrix[0].size(); j++)
		{
			res._matrix[i][j] = 0;
			for (int k = 0; k < _matrix[0].size(); k++) {
				res._matrix[i][j] += _matrix[i][k] * matrix._matrix[k][j];
			}
		}
	}
	return res;
}

// method that can check whether the two matrices are of the same
bool Matrix::equals(const Matrix& matrix) {
	// If both empty matrices, return true
	if (_matrix.size() == 0 && matrix._matrix.size() == 0)
	{
		return true;
	}

	// If the shape is not the same, return false
	if (_matrix.size() != matrix._matrix.size() || _matrix[0].size() != matrix._matrix[0].size())
	{
		return false;
	}

	// If any entry is not match, return false
	for (int i = 0; i < _matrix.size(); i++)
	{
		for (int j = 0; j < _matrix[0].size(); j++)
		{
			if (_matrix[i][j] != matrix._matrix[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

void Matrix::display()
{
	//print out all the values on the screen
	for (int i = 0; i < _matrix.size(); i++) {
		for (int j = 0; j < _matrix[i].size(); j++) {
			cout << _matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

//functions that test the transpose
void testTranspose() {
	cout << "Transpose Test: " << endl;

	Matrix A;
	A._matrix = { { 1,2 },{ 3,4 } };
	Matrix B;
	B._matrix = { {1,3},{2,4} };
	Matrix C;
	C._matrix = { {1,4,7},{2,5,8},{3,6,9} };
	Matrix D;
	D._matrix = { {1,2,3},{4,5,6},{7,8,9} };

	if (A.transpose().equals(B))
	{
		cout << "Test 1 pass!" << endl;
	}
	else
	{
		cout << "Test 1 fail!\n" << endl;
	}


	if (!A.transpose().equals(A))
	{
		cout << "Test 2 pass!" << endl;
	}
	else
	{
		cout << "Test 2 fail!" << endl;
	}

	if (C.transpose().equals(D))
	{
		cout << "Test 3 pass!\n" << endl;
	}
	else
	{
		cout << "Test 3 fail!\n" << endl;
	}

}


void testMultiplication() {
	cout << "Multiplication Test: " << endl;

	Matrix A;
	A._matrix = { {1,2},{3,4} };
	Matrix B;
	B._matrix = { {1,3},{2,4} };
	Matrix C;
	C._matrix = { {5,11},{11,25} };
	Matrix D;
	D._matrix = { {1,2,3},{4,5,6},{7,8,9} };
	Matrix D1;
	Matrix E;
	E._matrix= { {1,2,3}, {4,5,6} };
	Matrix F;
	F._matrix = { {9,12,15},{19,26,33} };

	if ((A * B).equals(C))
	{
		cout << "Test 1 pass!" << endl;
	}
	else
	{
		cout << "Test 2 fail!" << endl;
	}

	if ((A*D).equals(D1))
	{
		cout << "Test 2 pass!" << endl;
	}
	else
	{
		cout << "Test 2 fail!" << endl;
	}

	if ((A * E).equals(F))
	{

		cout << "Test 3 pass!\n" << endl;
	}
	else
	{
		cout << "Test 3 fail!\n" << endl;
	}
	return;
}


int main()
{
	testTranspose();
	testMultiplication();
	Matrix A;
	A._matrix = { { 1,2 },{ 3,4 } };
	Matrix B;
	B._matrix = { {2,3},{4,5} };
	Matrix C;
	C._matrix = { {1,2,3},{4,5,6} };

	//Transpose of A
	cout << "Transpose matrix of A: " << endl;
	A.transpose().display();

	//Transpose of B
	cout << "Transpose matrix of B: " << endl;
	A.transpose().display();

	//Transpose of C
	cout << "\n\nTranspose matrix of C: " << endl;
	C.transpose().display();

	//CA
	cout << "\n\nCA:" << endl;
	(C * A).display();

	//AC
	cout << "\n\nAC" << endl;
	(A * C).display();

	//C^T * C
	cout << "\n\nTranspose of C multiply by C: " << endl;
	(C.transpose() * C).display();
	return 0;
}


