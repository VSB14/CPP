// Count the number of occurences of given numbers in the given array.
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {};
    int n;
    cout<<"size of the array";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>> arr[i];
    }
    
    //pre-compute
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]+=1; //hash[arr[i]= hash[arr[i]] +1 ]

    }
    
    int q; //number of entries
    cin>>q;
    while (q--)
    {
        int number; //value of the number to fetch its occurences
        cin>> number;
        //fetch
        cout<< hash[number]<<endl;
    }
    return 0;
    

}