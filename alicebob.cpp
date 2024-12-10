#include <bits/stdc++.h>
using namespace std;

int main()
{
    int runs;
    cin >> runs;
    vector<int> A(runs), B(runs); // Initialize vectors with size runs

    // Input loop to read pairs of integers into vectors A and B
    for (int i = 0; i < runs; i++)
    {
        cin >> A[i] >> B[i];
    }

    for (int i = 0; i < runs; i++)
    {
        int restcount = 0;
        int req = 0;
        if (A[i] > B[i])
        {
            restcount = A[i] - B[i];
            if (restcount >= 10)
            {
                cout << 0 << endl;
            }
            else
            {

                req = 10 - restcount;
                if (req % 3 == 0)
                {
                    cout << req / 3 << endl;
                    continue;
                }

                if (req % 2 == 0)
                {
                    cout << req / 2 << endl;
                    continue;
                }
                else
                {
                    cout << 1 << endl;
                }
            }
        }
        else if (A[i] < B[i])
        {
            req = 10 + B[i] - A[i];
            if (req % 3 == 0)
            {
                cout << req / 3 << endl;
                continue;
            }

            if (req % 2 == 0)
            {
                cout << req / 2 << endl;
                continue;
            }
            else
            {
                cout << 1 << endl;
            }
        }
    }

    return 0;
}
