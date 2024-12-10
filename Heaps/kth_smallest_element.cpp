#include <bits/stdc++.h>
using namespace std;

int main(){
    int k;
    int arr[] = {7,10,4,3,10,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter kth element to find : ";
    cin>>k;
    priority_queue<int> maxh;
    for (int i = 0; i < size; i++)
    {
        maxh.push(arr[i]);
        if(maxh.size()>k){
            maxh.pop();
            
        }
    }
    cout << "The " << k << "th smallest element is: " << maxh.top() << endl;

    return 0;
}