//Given an array of size N. Find the highest and lowest frequency element.
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {};
    int n;
    cout<<"Input size of the Array: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Input Array Element "<<i+1<<" Value: ";
        cin>>arr[i];
    }
    
    //unordered_map
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    
    int minelement = 0, maxelement =0;
    int minfreq = n, maxfreq =0;
    
    for (auto it: mp)
    {
        int count = it.second;
        int element = it.first;

        if(count > maxfreq){
            maxfreq = count;
            maxelement = element;

        }
        if(count < minfreq){
            minfreq = count;
            minelement = element;
        }

        

    }
    cout << "The highest frequency element is: " << maxelement << "\n";
        cout << "The lowest frequency element is: " << minelement << "\n";
    

    return 0;

}