//Print 1 to N numbers using backtracking.
#include <bits/stdc++.h>
using namespace std;

void print(int i,int N){
    if(i<1){
        return;
    }
    print(i-1, N);
    cout<<i<<endl;


}

int main(){
    int N;
    cout<<"Enter the number: ";
    cin>>N;
    print(N,N);
}