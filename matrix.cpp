template <typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    void Keyboard() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void Random() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = static_cast<T>(rand() % 100); 
            }
        }
    }

    void printMatrix() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>&) const {
    Matrix<T> result(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }

    template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>&) const {
    Matrix<T> result(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>&) const {
    Matrix<T> result(rows, other.cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; k++) {
                result.data[i][j] += this->data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& ) const {
    Matrix<T> result(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (other.data[i][j] != 0) {
                result.data[i][j] = this->data[i][j] / other.data[i][j];
            } else {
                
                result.data[i][j] = 0;
            }
        }
    }

    return result;
}
}

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;

    T findMax() const {
        T maxElement = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] > maxElement) {
                    maxElement = data[i][j];
                }
            }
        }
        return maxElement;
    }

    // Поиск минимального элемента
    T findMin() const {
        T minElement = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] < minElement) {
                    minElement = data[i][j];
                }
            }
        }
        return minElement;
    }
};