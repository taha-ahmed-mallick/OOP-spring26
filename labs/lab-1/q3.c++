#include <iostream>
using namespace std;

int main()
{
  float fah, cel;

  cout << "Convertor (Fahrenhet to Celsius):-" << endl;
  cout << "Enter Temp in Fahrenheit:";
  cin >> fah;
  cel = (fah - 32) / 1.8;
  cout << "Temp in Celsius: " << cel;

  return 0;
}