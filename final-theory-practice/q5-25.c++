#include <iostream>
using namespace std;

template <typename T=int, typename U>
int searchElement(T *arr, int size, T element)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == element)
            return mid;
        else if (element < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    throw runtime_error("Element not found.");
}

int main()
{
    int iarr[] = {-5, -4, -3, 5, 6, 8, 9, 11};
    float farr[] = {-0.5, -0.2, 0, 2.78, 3.14, 5.5, 9, 11};
    char carr[] = {'A', 'B', 'C', 'D', 'e', 'f', 'g', 'h'};
    int ii = searchElement<int, int>(iarr, sizeof(iarr)/sizeof(iarr[0]), 9);
    int fi = searchElement<float, int>(farr, sizeof(farr)/sizeof(farr[0]), 3.14);
    int ci = searchElement<char, int>(carr, sizeof(carr)/sizeof(carr[0]), 'e');
    cout << ii << " " << fi << " " << ci << endl;
    cout << iarr[ii] << " " << farr[fi] << " " << carr[ci] << endl;
    return 0;
}