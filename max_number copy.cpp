#include <bits/stdc++.h>
using namespace std;

void giveMax(int parth[], int size)
{
    int res = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        res = max(res, parth[i]);
    }

    cout << "Max of these: " << res;
}

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int parth[size] = {0};

    for (int i = 0; i < size; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> parth[i];
    }

    giveMax(parth, size);

    return 0;
}
