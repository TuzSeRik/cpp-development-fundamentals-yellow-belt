#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {
        Reset(0, 0);
    }

    Matrix(const int& rows, const int& cols) {
        Reset(rows, cols);
    }
    // Creating the generating method replacing the constructors
    void Reset(int rows, int cols) {
        if (rows < 0 || cols < 0)
            throw out_of_range("Reset");
        // Preventing the problem of equality of different "null" matrices
        if (rows == 0 || cols == 0)
            rows = cols = 0;
        matrix.assign(rows, vector<int>(cols));
    }

    [[nodiscard]] int At(int row, int col) const {
        checkNums(row, col);
        return matrix[row][col];
    }

    int& At(int row, int col) {
        checkNums(row, col);
        return matrix[row][col];
    }

    [[nodiscard]] int GetNumRows() const {
        return matrix.size();
    }

    [[nodiscard]] int GetNumColumns() const {
        if (matrix.empty())
            return 0;
        return matrix[0].size();
    }

private:
    void checkNums(const int& row, const int& col) const {
        if (matrix.empty() || row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size())
            throw out_of_range("At");
    }

    vector<vector<int>> matrix;
};

istream& operator >>(istream& input, Matrix& matrix) {
    int r, c, item;
    input >> r >> c;
    matrix = Matrix(r, c);
    // Going through every element in matrix and assigning values from input
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            input >> item;
            matrix.At(i, j) = item;
        }
    }

    return input;
}

ostream& operator <<(ostream& output, const Matrix& matrix) {
    output << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;

    for (int i = 0; i < matrix.GetNumRows(); ++i) {
        for (int j = 0; j < matrix.GetNumColumns(); ++j) {
            output << matrix.At(i, j) << " ";
        }
        output << endl;
    }

    return output;
}

Matrix operator +(const Matrix& a, const Matrix& b) {
    if (a.GetNumRows() != b.GetNumRows() || a.GetNumColumns() != b.GetNumColumns())
        throw invalid_argument("+");
    Matrix result(a.GetNumRows(), b.GetNumColumns());

    for (int i = 0; i < result.GetNumRows(); ++i) {
        for (int j = 0; j < result.GetNumColumns(); ++j) {
            result.At(i, j) = a.At(i, j) + b.At(i, j);
        }
    }

    return result;
}

bool operator ==(const Matrix& a, const Matrix& b) {
    // If matrices have same size, check if any of elements is different
    if (a.GetNumRows() == b.GetNumRows() && a.GetNumColumns() == b.GetNumColumns()) {
        for (int i = 0; i < a.GetNumRows(); ++i)
            for (int j = 0; j < a.GetNumColumns(); ++j)
                if (a.At(i, j) != b.At(i, j))
                    return false;
    }
    // If matrices have different size
    else
        return false;

    // If matrices have same size and we not found any different elements
    return true;
}
