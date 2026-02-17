#include <iostream>
using namespace std;

class DynamicArray
{
    int *arr, arraySize;

public:
    DynamicArray(int size) : arraySize(size) { this->arr = new int[size](); }

    ~DynamicArray() { delete[] arr; }

    void push(int val)
    {
        int *temp = new int[arraySize + 1];
        for (int i = 0; i < arraySize; i++)
            temp[i] = arr[i];
        temp[arraySize++] = val;
        delete[] arr;
        arr = temp;
    }

    void printArray() const
    {
        cout << "Your array: ";
        for (int i = 0; i < arraySize; i++)
            cout << arr[i] << (i == arraySize - 1 ? "" : ", ");
        cout << endl
             << "Total elements: " << arraySize << endl;
    }

    int size() const { return arraySize; }
};

int main()
{
    DynamicArray myArray(3);
    cout << "Initial array: ";
    myArray.printArray();

    myArray.push(5);
    myArray.push(10);

    cout << "After push operations: ";
    myArray.printArray();

    cout << "Size of array: " << myArray.size() << endl;
    return 0;
}