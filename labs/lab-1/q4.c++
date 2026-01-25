#include <iostream>
using namespace std;

void add_mat(int A[3][3], int B[3][3], int add[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            add[i][j] = A[i][j] + B[i][j];
}
void multi_mat(int A[3][3], int B[3][3], int mul[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
                mul[i][j] += A[i][k] * B[k][j];
        }
}

int main()
{
    int A[3][3], B[3][3], add[3][3], mul[3][3];
    cout << "Enter Mat A: " << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> A[i][j];
    cout << "Enter Mat B: " << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> B[i][j];
    add_mat(A, B, add);
    multi_mat(A, B, mul);

    cout << "Addition of Two Matrices is :" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << add[i][j] << " ";
        cout << endl;
    }

    cout << "Multiplication of Two Matrices is :" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << mul[i][j] << " ";
        cout << endl;
    }

    return 0;
}