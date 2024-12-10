// maximum of three numbers
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int parth[] = {};
    int res;
    int size;
    cout << "Enter of the array:  ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> parth[i];
    }
    //{1,2,3}, {3,2,1}
    //{2,3,1},
    for (int i = 0; i < size; i++)
    {
        if (parth[i] > parth[i + 1])
        {
            res = max(res, parth[i]);
        }
        
    }
    cout << "Max of these " << res;
    return 0;
}
