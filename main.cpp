#include <iostream>
#include <cstdlib> // For generating random numbers
#include "Matrix.h" // Include the header file for your Matrix class
using namespace std;
int main() {
    int rows = 3;
    int cols = 3;
    Matrix<int> matrix1(rows, cols);
    Matrix<int> matrix2(rows, cols);

    cout << "Enter values for matrix1:" << endl;
    matrix1.fillFromKeyboard();

    cout << "Enter values for matrix2:" << endl;
    matrix2.fillFromKeyboard();

    cout << "Matrix1:" << endl;
    matrix1.printMatrix();

    cout << "Matrix2:" << endl;
    matrix2.printMatrix();

    Matrix<int> sumMatrix = matrix1 + matrix2;
    cout << "Sum of matrices:" << endl;
    sumMatrix.printMatrix();

    int count = Matrix<int>::getObjectCount();



    int maxElement1 = matrix1.findMax();
    int minElement2 = matrix2.findMin();

    cout << "Max element in matrix1: " << maxElement1 << endl;
    cout << "Min element in matrix2: " << minElement2 << endl;

    return 0;
}
