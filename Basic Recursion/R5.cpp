//Print Sum of first N Natural Numbers using backtracking.
#include <bits/stdc++.h>
using namespace std;
int sum =0;
void print(int i,int N){
    if(i<1){
        cout<<sum;
        return;
    }
    sum = sum + i;
    print(i-1, N);


}

int main(){
    int N;
    cout<<"Enter the number: ";
    cin>>N;
    print(N,N);
}