//Print Factorial of a Number : Iterative and Recursive 
#include <bits/stdc++.h>
using namespace std;
int fac =1;
void print(int i,int N){
    if(i<1){
        cout<<fac;
        return;
    }
    fac = fac*i;
    print(i-1, N);


}

int main(){
    int N;
    cout<<"Enter the number: ";
    cin>>N;
    print(N,N);
}