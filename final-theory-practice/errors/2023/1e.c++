#include <iostream>
using namespace std;

int main()
{
        int var = 1;
        try
        {
            try
            {
                throw var;
            }
            catch (int ex)
            {
                ex += 10;
                cout << "Error handling :: Val :" << var << " Ex: " << ex << endl;
                throw;
            }
        } catch(int x) {
            cout << x << endl;
        }
    return 0;
}