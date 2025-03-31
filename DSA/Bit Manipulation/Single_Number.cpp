#include<bits/stdc++.h>
using namespace std;
//this program test doing xor on a array with duplicate values but in an un sorted array.
int xor_res(vector<int> x){
    int res =x[0];
  for (int i = 0; i < x.size()-1; i++)
  {
    res ^= x[i+1];
  }
  
    return res;
    
}

int main(){
    vector<int> arr = {5,131,4,5,4,6,7,7,6,};
    int res = xor_res(arr);
    cout<<"Result: "<<res;
    return 0;
}