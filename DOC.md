# class Matrix
## Attribute
- vector<vector<int>> _matrix: the data structure which can store the matrix values
## Method
- transpose(): return the transpose of the matrix, no in-place changed
- operator*(const Matrix &matrix): return the result by multiplying two matrices, if the size mismatch, will return a empty matrix
- equals(const Matrix& matrix): return the boolean value whether the two matrices are of the same
- display(): print the value of the matrix on the screen

# Other functions:
- testTranspose(): function that contains several test for the tranpose() method in class Matrix
- testMultiplication: function that contains several test for the matrix multiplications
- Main(): In the main function, first of all two test method has been called and the results will be displayed. Then, some example code has illustrated how to declare the matrices and how to use the tranpose and multiplication method.   
