#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

template <typename T>
class Matrix {
private:
    int rows;
    int cols;
    static int objectCount;
public:
    Matrix(int numRows, int numCols);
    ~Matrix();

     static int getObjectCount() {
        return objectCount;
    }

    void fillFromKeyboard();
    void fillWithRandom();
    void printMatrix() const;

 Matrix<T> operator+(const Matrix<T>&) const;
Matrix<T> operator-(const Matrix<T>&) const;
Matrix<T> operator*(const Matrix<T>&) const;
Matrix<T> operator/(const Matrix<T>&) const;

template <typename T>
int Matrix<T>::objectCount = 0;


    T findMax() const;
    T findMin() const;
};

#endif
