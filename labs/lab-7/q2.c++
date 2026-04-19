#include <iostream>
using namespace std;

class Matrix
{
private:
    int **arr, rows, cols;

public:
    Matrix() : rows(0), cols(0), arr(nullptr) {}
    Matrix(int r, int c) : rows(r), cols(c)
    {
        arr = new int *[rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new int[cols]();
    }

    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
    { // deep copy
        arr = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                arr[i][j] = other.arr[i][j];
        }
    }

    void operator=(const Matrix &other)
    { // deep copy assignment
        if (this == &other)
            return; // self-assignment check

        for (int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;

        rows = other.rows;
        cols = other.cols;
        arr = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                arr[i][j] = other.arr[i][j];
        }
    }

    Matrix operator+(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrices must have the same dimensions for addition." << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.arr[i][j] = arr[i][j] + other.arr[i][j];
        return result;
    }

    Matrix operator-(const Matrix &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            cout << "Matrices must have the same dimensions for subtraction." << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.arr[i][j] = arr[i][j] - other.arr[i][j];
        return result;
    }

    Matrix operator*(const Matrix &other)
    {
        if (cols != other.rows)
        {
            cout << "Number of columns of first matrix must equal number of rows of second matrix for multiplication." << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.arr[i][j] += arr[i][k] * other.arr[k][j];
        return result;
    }

    int *operator[](int index)
    {
        return arr[index];
    }
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

    void input()
    {
        cout << "Enter elements for a " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> arr[i][j];
    }
    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    friend bool search(const Matrix&, int);
};

bool search(const Matrix &mat, int target)
{
    int left = 0, right = mat.rows * mat.cols -1;
    while (left <= right) {
        int middle = (left+right) / 2;
        int r = middle / mat.cols;
        int c = middle % mat.cols;

        if (target == mat.arr[r][c])
            return true;
        else if (target < mat.arr[r][c])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return false;
}

int main() {
    int m, n, target;
    cout << "Enter dimension (m x n):" << endl;
    cout << "m: ";
    cin >> m;
    cout << "n: ";
    cin >> n;
    Matrix A(m, n);
    A.input();
    cout << "Enter the element u want to search: ";
    cin >> target;
    cout << "target in matrix? " << (search(A, target) ? "true :)" : "false :(") << endl;
    return 0;
}