// maximum of three numbers
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter value for a ";
    cin >> a;
    cout << "Enter value for b ";
    cin >> b;
    cout << "Enter value for c ";
    cin >> c;
    if (a > b && a > c)
    {
        cout << "max value :" << a;
    }
    if (b > a && b > c)
    {
        cout << "max value :" << b;
    }
    if (c > b && c > a)
    {
        cout << "max value :" << c;
    }
    return 0;
}
