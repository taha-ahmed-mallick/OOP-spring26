#include <iostream>
using namespace std;

struct PrintJob
{
    string clientName, fileName;
    int pages;

    PrintJob(string clientName, string fileName, int pages) : clientName(clientName), fileName(fileName), pages(pages) {}
    
    PrintJob() : clientName(""), fileName(""), pages(0) {}
};

void print(const PrintJob &job)
{
    cout << "Printing..." << endl
         << "Client Name: " << job.clientName << endl
         << "File Name: " << job.fileName << endl
         << "No. of Pages: " << job.pages << endl;
}

int main()
{
    // it would be almost same i am not making this again
    PrintJob print1 = {"Taha Ahmed", "Climate Change", 2};
    print(print1);
    PrintJob print2("Taha Ahmed", "Climate Change", 3);
    print(print2);
    return 0;
}