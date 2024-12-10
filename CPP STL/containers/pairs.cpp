#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, string> p;
    p = make_pair(2, "lodu");
    // pair<int, string> &p2 = p;

    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};

    pair<int, int> p_arr[3];
    p_arr[0] = {arr1[0], arr2[0]};
    p_arr[1] = {arr1[1], arr2[1]};
    p_arr[2] = {arr1[2], arr2[2]};

    // cout << "Print The first value fo the pair " << p.first << endl;
    // cout << "Print The second value fo the pair " << p.second << endl;
    // cout << "Print The first value fo the pair " << p2.first << endl;
    // cout << "Print The second value fo the pair " << p2.second << endl;

    swap(p_arr[0],p_arr[2]);

    int size = sizeof(p_arr) / sizeof(p_arr[0]);
    for (int i = 0; i < size ; i++)
    {
        cout << " Int Value is " << p_arr[i].first << " String Value is " << p_arr[i].second << endl;
    }

    return 0;
}