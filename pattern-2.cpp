#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count;
    cout << "Input the pattern count: ";
    cin >> count;
    int increase = 1;
    int dec = count;
    int start = 0;
    int end = count;
   
    while (start < count)
    {
        for (int j = 0; j < increase; j++)
        {
            cout << "*";
            
        }
        start++;
        increase++;
        cout << endl;
    }
    
    while (end >0)
    {
        for (int j = 0; j < dec-1; j++)
        {
            cout << "*";
            
        }
        end--;
        dec--;
        cout << endl;
    }
    // while(end>0)
    // for (int i = count - 1; i > 0; i--)
    // {
    //     cout << "*";
    // }
    // cout << endl;

    return 0;
}
