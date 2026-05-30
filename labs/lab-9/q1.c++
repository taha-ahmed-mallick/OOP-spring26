#include <iostream>
#include <vector>
using namespace std;

class ArrayMultiplier
{
public:
    virtual void calculate() = 0;
    ~ArrayMultiplier() {}
};

class ArrayMultiplier1D : public ArrayMultiplier
{
private:
    vector<int> arr1, arr2;

public:
    ArrayMultiplier1D(const vector<int> v1, const vector<int> v2) : arr1(v1), arr2(v2) {}
    void calculate() override
    {
        if (arr1.size() != arr2.size())
        {
            cout << "Size mismatch\n";
            return;
        }
        long dot_product = 0;
        for (int i = 0; i < arr1.size(); i++)
            dot_product += static_cast<long>(arr1[i]) * arr2[i];
        cout << "The dot product is : " << dot_product << endl;
    }
};

class ArrayMultiplier2D : public ArrayMultiplier
{
private:
    vector<vector<int>> mat1, mat2;

public:
    ArrayMultiplier2D(const vector<vector<int>> v1, const vector<vector<int>> v2) : mat1(v1), mat2(v2) {}
    void calculate() override
    {
        if (mat1.empty() || mat2.empty() || mat1[0].size() != mat2.size())
        {
            cout << "Some error\n";
            return;
        }

        int rows1 = mat1.size();
        int cols1 = mat1[0].size();
        int cols2 = mat2[0].size();

        vector<vector<int>> result(rows1, vector<int>(cols2, 0));

        for (int i = 0; i < rows1; i++)
            for (int j = 0; j < cols2; j++)
                for (int k = 0; k < cols1; k++)
                    result[i][j] += mat1[i][k] * mat2[k][j];

        cout << "RESULT:\n";
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols2; j++)
                cout << result[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6};

    vector<vector<int>> m1 = {{1, 2},
                              {3, 4}};
    vector<vector<int>> m2 = {{1}, {2}};

    ArrayMultiplier *mul[2];
    mul[0] = new ArrayMultiplier1D(v1, v2);
    mul[1] = new ArrayMultiplier2D(m1, m2);

    for (int i = 0; i < 2; i++)
    {
        mul[i]->calculate();
        delete mul[i];
    }
    return 0;
}