
#include<vector>
#include<iostream>
using namespace std;
class Matrix {
public:
	vector<vector<int>> oneMatrix;
	Matrix transposing();
	Matrix operator+(const Matrix& matrix);
	Matrix operator-(const Matrix& matrix);
	Matrix operator*(const Matrix& matrix);
	void display();
};
 
 
int main()
{
	
	Matrix A;
	A.oneMatrix = { { 1,2 },{ 3,4 } };
	Matrix B;
	B.oneMatrix = { {1,3},{3,2} };
	Matrix C;
	C.oneMatrix = { {1,3,1},{3,2,2} };
 
	//A的装置矩阵
	cout << "A的转置矩阵为:" << endl;
	A.transposing().display();
 
	//C的装置矩阵
	cout << "\n\nC的转置矩阵为:" << endl;
	C.transposing().display();
	
	//A+A的装置
	cout << "\n\nA+A的装置:" << endl;
	Matrix res;
	res = A + A.transposing();
	res.display();
	//(A + A.transposing()).display();
 
	//A+C
	cout << "\n\nA+C:" << endl;
	(A + C).display();
 
	//A-B
	cout << "\n\nA-B:" << endl;
	(A - B).display();
 
	//CA
	cout << "\n\nCA:" << endl;
	if (C.oneMatrix[0].size() == A.oneMatrix.size()) {
		(C*A).display();
	}
	else {
		cout << "矩阵无法进行计算!" << endl;
	}
 
	//AC
	cout << "\n\nAC" << endl;
	(A*C).display();
 
	//C的装置乘以C
	cout << "\n\nC的装置乘以C" << endl;
	(C.transposing()*C).display();
    return 0;
}
 
 
Matrix Matrix::transposing() {
	Matrix res;
	vector<vector<int>> temp(oneMatrix[0].size(),vector<int>(oneMatrix.size()));
	res.oneMatrix = temp;
	for (int i = 0; i < oneMatrix.size(); i++)
	{
		for (int j = 0; j < oneMatrix[i].size(); j++) {
			res.oneMatrix[j][i] = oneMatrix[i][j];
		}
	}
	
	return res;
}
 
Matrix Matrix::operator+(const Matrix& matrix) {
	Matrix res;
	vector<vector<int>> temp(oneMatrix.size(), vector<int>(oneMatrix[0].size()));
	res.oneMatrix = temp;
	for (int i = 0; i < oneMatrix.size(); i++) {
		for (int j = 0; j < oneMatrix[i].size(); j++) {
			res.oneMatrix[i][j] = oneMatrix[i][j] + matrix.oneMatrix[i][j];
		}
	}
	return res;
}
 
Matrix Matrix::operator-(const Matrix& matrix) {
	Matrix res;
	vector<vector<int>> temp(oneMatrix.size(), vector<int>(oneMatrix[0].size()));
	res.oneMatrix = temp;
	for (int i = 0; i < oneMatrix.size(); i++) {
		for (int j = 0; j < oneMatrix[i].size(); j++) {
			res.oneMatrix[i][j] = oneMatrix[i][j] - matrix.oneMatrix[i][j];
		}
	}
	return res;
}
 
Matrix Matrix::operator*(const Matrix& matrix) {
	int row = oneMatrix.size();
	int col = matrix.oneMatrix[0].size();
	vector<vector<int>> temp(row, vector<int>(col));
	Matrix res;
	res.oneMatrix = temp;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			res.oneMatrix[i][j] = 0;
			for (int k = 0; k < oneMatrix[0].size(); k++) {
				res.oneMatrix[i][j] += oneMatrix[i][k] * matrix.oneMatrix[k][j];
			}
		}
	}
	return res;
}
 
void Matrix::display()
{
	for (int i = 0; i < oneMatrix.size(); i++) {
		for (int j = 0; j < oneMatrix[i].size(); j++) {
			cout << oneMatrix[i][j] << "\t";
		}
		cout << endl;
	}
}
