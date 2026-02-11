#include <iostream>
using namespace std;

typedef struct
{
    int val;
    bool err;
} useless;

class DynamicArray
{
    int *arr, arraySize;

public:
    DynamicArray(int size) : arraySize(size) { this->arr = new int[size](); }
    void push(int val)
    {
        int *temp = new int[arraySize + 1];
        for (int i = 0; i < arraySize; i++)
            temp[i] = arr[i];
        temp[arraySize++] = val;
        delete[] arr;
        arr = temp;
    }
    int size() { return arraySize; }
    // just for fun
    useless pop()
    {
        useless idk = {0, false};
        if (arraySize != 0)
        {
            int *temp = new int[arraySize--];
            for (int i = 0; i < arraySize; i++)
                temp[i] = arr[i];
            idk.val = arr[arraySize];
            delete[] arr;
            arr = temp;
        }
        else
        {
            cout << "Array already empty." << endl;
            idk.err = true;
        }
        return idk;
    }
    useless get(int index)
    {
        useless result = {0, false};
        if (index < 0 || index >= arraySize)
        {
            cout << "Invalid index. Array size is " << this->size() << endl;
            result.err = true;
        }
        else
            result.val = arr[index];
        return result;
    }
    void printArray()
    {
        cout << "Your array: ";
        for (int i = 0; i < arraySize; i++)
            if (i != arraySize - 1)
                cout << arr[i] << ", ";
            else
                cout << arr[i];
        cout << endl
             << "Total elements: " << arraySize << endl;
    }
    // required functions and constructors because the given conditions were insufficient to access the initialy declared elements.
    DynamicArray(int *arr, int size) : arraySize(size)
    {
        this->arr = new int[size]();
        for (int i = 0; i < size; i++)
            this->arr[i] = arr[i];
    }
    bool set(int val, int index)
    {
        if (index < 0 || index >= arraySize)
        {
            cout << "Invalid index. Array size is " << this->size() << endl;
            return true;
        }
        else
            arr[index] = val;
        return false;
    }
    ~DynamicArray() { delete[] arr; }
};

int main()
{
    DynamicArray myArr(0);
    int choice, element, index;
    useless result;
    do
    {
        cout << "\n\nSelect options from below:" << endl;
        cout << "1. Print your array" << endl;
        cout << "2. Get size of array" << endl;
        cout << "3. Push" << endl;
        cout << "4. Pop" << endl;
        cout << "5. Get a specific element" << endl;
        cout << "6. Set value of an existing element" << endl;
        cout << "7. Exit the program" << endl;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            myArr.printArray();
            break;
        case 2:
            cout << "The size of your array is " << myArr.size() << endl;
            break;
        case 3:
            cout << "Enter the element: ";
            cin >> element;
            myArr.push(element);
            break;
        case 4:
            result = myArr.pop();
            if (!result.err)
                cout << "Element popped: " << result.val << endl;
            break;
        case 5:
            cout << "Enter the index: ";
            cin >> index;
            result = myArr.get(index);
            if (!result.err)
                cout << "Element at index " << index << " is " << result.val << endl;
            break;
        case 6:
            cout << "Enter the element: ";
            cin >> element;
            cout << "Enter the index: ";
            cin >> index;
            result = myArr.get(index);
            if (!result.err)
            {
                cout << "Current value at index " << index << " is " << result.val << " which is changed to " << element << endl;
                myArr.set(element, index);
            }
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    } while (choice != 7);
    return 0;
}