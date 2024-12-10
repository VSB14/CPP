//Print Reverse a given Array using recursion.
#include <bits/stdc++.h>
using namespace std;
int fac =1;
void print(int arr[],int size){
    if(i<1){
        cout<<fac;
        return;
    }
    fac = fac*i;
    print(i-1, N);


}

int main(){
    int arr[] = {5,4,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    print(arr,size);
    }