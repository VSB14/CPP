#include <bits/stdc++.h>
using namespace std;

void printVec(vector<string> &p)
{
    int size = p.size();
    cout << "Size: " << p.size() << endl; // p.size() = O(n)
    for (int i = 0; i < size; i++)
    {
        cout << p[i] << " ";
    }
}
int main()
{
    // vector<int> p(10);
    // vector<int> s = p; //takes O(n) Time, as new vector is created by copying each value of p into it.
    // vector<int> &s = p;
    // p.push_back(15);
    // s.push_back(14);
    // printVec(p);
    // printVec(s);

    // Vector of Strings
    vector<string> p;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string l;
        cin >> l;
        p.push_back(l);
    }
    printVec(p);
    return 0;
}
