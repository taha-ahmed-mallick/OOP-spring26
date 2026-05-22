#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

class Sorter
{
private:
    int *arr, *myarr;
    const size_t n;

public:
    Sorter(size_t n) : n(n)
    {
        arr = new int[n]();
        myarr = new int[n]();
    }

    void input()
    {
        int input;
        cout << "Enter the elements: \n";
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            arr[i] = input;
            myarr[i] = input;
        }
    }

    void libSort()
    {
        auto start = chrono::high_resolution_clock::now();
        sort(arr, arr + n);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "\e[1;32mTime took to sort: " << duration << "micro secs\e[0m\n";
    }

    void mySort()
    {
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (myarr[j] > myarr[j + 1])
                {
                    int temp = myarr[j];
                    myarr[j] = myarr[j + 1];
                    myarr[j + 1] = temp;
                }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
        cout << "\e[1;32mTime took to sort: " << duration << "micro secs\e[0m\n";
    }

    void display()
    {
        cout << "Your array: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }

    void myDisplay()
    {
        cout << "Your array: ";
        for (int i = 0; i < n; i++)
        {
            cout << myarr[i] << "  ";
        }
        cout << endl;
    }

    ~Sorter()
    {
        delete[] arr;
        delete[] myarr;
    }
};

int main()
{
    size_t n;
    cout << "Enter the number of elements: ";
    cin >> n;
    Sorter arr(n);

    arr.input();

    cout << "\n\n------Before Sort-------\n\n";
    arr.display();

    cout << "\n\n-------After my bubble Sort--------\n\n";
    arr.mySort();
    arr.myDisplay();

    cout << "\n\n-------After algorithm Sort--------\n\n";
    arr.libSort();
    arr.display();

    return 0;
}