#include <bits/stdc++.h>
#include <vector>
using namespace std;

string test(vector<string> &vec)
{
    vec.pop_back();
    return vec[vec.size()-1];
}

int main()
{
    vector<string> Strs({"donkey", "goat", "cat", "pig", "dog", "Cow", "Sheep", "horse", "water buffalo", "red fox"});
    cout<<Strs[Strs[1]];
    return 0;
}