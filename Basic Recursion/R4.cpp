//Print N to 1 numbers using recursion.
#include <bits/stdc++.h>
using namespace std;

void print(int i,int N){
    if(i<1){
        return;
    }
    cout<<i<<endl;
    print(i-1, N);


}

int main(){
    int N;
    cout<<"Enter the number: ";
    cin>>N;
    print(N,N);
}