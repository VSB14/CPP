#include<iostream>
using namespace std;

int count_set_bits(int x){
    int cnt=0;
    while (x!=0)
    {
        if(x&1 ==1 )  cnt++;
        x = x>>1;//right shift by one

    }
    return cnt;
    
}

int main(){
    int num;
    cout<<"Provide Number: ";
    cin>> num;
    int res = count_set_bits(num);
    cout<<"Number of set bits: "<<res;
    return 0;
}