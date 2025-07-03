
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
   int a;
   //int b;
   cin >> a;
   bool iseven;
   iseven = a & 1;
   cout << iseven << "  Если 0-четное, 1-нечетное";
    return 0;
}