#include <iostream>
using namespace std;

template <typename T>
double meadian(const T *arr, size_t size)
{
    T *sorted = new T[size];
    for (int i = 0; i < size; i++)
        sorted[i] = arr[i];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (sorted[j] > sorted[j + 1])
            {
                T temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
    double result;
    if (size % 2 == 0)
    {
        int med = size / 2;
        result = (static_cast<double>(sorted[med - 1]) + sorted[med]) / 2;
    }
    else
    {
        result = sorted[size / 2];
    }
    delete[] sorted;
    return result;
}

int main()
{
    int arr[] = {8, 3, 5, 2, 9};
    cout << meadian<int>(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}