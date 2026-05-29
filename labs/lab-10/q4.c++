#include <iostream>
using namespace std;

template <typename T>
class DynamicArr
{
protected:
    T *arr;
    int cap;

public:
    DynamicArr(int cap) : cap(cap)
    {
        arr = new T[cap]();
    }

    virtual ~DynamicArr()
    {
        delete[] arr;
    }

    virtual void resize() = 0;
};

template <typename T>
class Queue : public DynamicArr<T>
{
protected:
    int frontIdx, rearIdx, total;

public:
    Queue(int cap = 4) : DynamicArr<T>(cap), frontIdx(0), rearIdx(-1), total(0) {}
    ~Queue() {}

    bool isFull() const { return total == this->cap; }
    bool isEmpty() const { return total == 0; }
    int size() const { return total; }

    T front() const
    {
        if (isEmpty())
            throw runtime_error("The Queue is empty.");
        return this->arr[frontIdx];
    }
    T rear() const
    {
        if (isEmpty())
            throw runtime_error("The Queue is empty.");
        return this->arr[rearIdx];
    }

    void enqueue(T obj)
    {
        if (isFull())
            resize();
        rearIdx = (rearIdx + 1) % this->cap;
        this->arr[rearIdx] = obj;
        total++;
    }

    T dequeue()
    {
        if (isEmpty())
            throw runtime_error("The Queue is empty.");
        T ejected = this->arr[frontIdx];
        frontIdx = (frontIdx + 1) % this->cap;
        total--;
        return ejected;
    }

    void resize() override
    {
        int oldCap = this->cap;
        int newCap = oldCap * 2;
        T *newArr = new T[newCap]();

        int curFront = this->frontIdx;
        for (int i = 0; i < total; i++)
        {
            newArr[i] = this->arr[curFront];
            curFront = (curFront + 1) % oldCap;
        }

        delete[] this->arr;

        this->arr = newArr;
        this->cap = newCap;
        this->frontIdx = 0;
        this->rearIdx = total - 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "The Queue is Empty." << endl;
            return;
        }
        cout << "------The Contents------\n";
        if (frontIdx > rearIdx)
        {
            for (int i = 0; i <= rearIdx; i++)
                cout << this->arr[i] << ", ";
            for (int i = rearIdx; i < frontIdx - 1; i++)
                cout << "_, ";
            for (int i = frontIdx; i < this->cap; i++)
            {
                cout << this->arr[i];
                cout << ((i == this->cap - 1) ? "\n" : ", ");
            }
        }
        else
        {
            for (int i = 0; i < frontIdx; i++)
                cout << "_, ";
            for (int i = frontIdx; i <= rearIdx; i++)
                cout << this->arr[i] << ((i == this->cap - 1) ? "\n" : ", ");
            for (int i = rearIdx + 1; i < this->cap; i++)
                cout << ((i == this->cap - 1) ? "_\n" : "_, ");
        }
        cout << "Size: " << total << ", Capacity: " << this->cap << endl;
    }
};

int main()
{
    Queue<int> queue;
    int num;
    do
    {
        int choice;
        cout << "Select from the options below:" << endl
             << "1. Enqueue" << endl
             << "2. Dequque" << endl
             << "3. Get Front Element" << endl
             << "4. Get Rear Element" << endl
             << "5. Get Size" << endl
             << "6. Display Contents" << endl
             << "7. EXIT" << endl;
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "Enter a number u wanna enqueue: ";
            cin >> num;
            queue.enqueue(num);
            cout << "The number: " << num << ", is successfully enqueued.\n";
            break;
        case 2:
            try
            {
                num = queue.dequeue();
                cout << "The dequeued element was: " << num << endl;
            }
            catch (runtime_error e)
            {
                cout << e.what() << endl;
            }
            break;
        case 3:
            try
            {
                num = queue.front();
                cout << "The element in the front was: " << num << endl;
            }
            catch (runtime_error e)
            {
                cout << e.what() << endl;
            }
            break;
        case 4:
            try
            {
                num = queue.rear();
                cout << "The element in the rear was: " << num << endl;
            }
            catch (runtime_error e)
            {
                cout << e.what() << endl;
            }
            break;
        case 5:
            num = queue.size();
            cout << "The size of the queue is " << num << endl;
            break;
        case 6:
            queue.display();
            break;
        case 7:
            cout << "EXITING..." << endl;
            return 0;
            break;

        default:
            cout << "\e[1;31mINVALID CHOICE\e[0m\n";
            break;
        }
    } while (true);
    return 0;
}