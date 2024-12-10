#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count;
    cout<<"Input the pattern count: ";
    cin>>count;
    int space = 0;
    while (count > 0)
    {
        for (int j = 0; j < count; j++)
        {
            cout << "*";
        }
        count--;
        cout << endl;
        space= space +2;
        for (int i = 0; i < space; i++)
        {
            cout << " ";
            
            
        }
    }

    return 0;
}
