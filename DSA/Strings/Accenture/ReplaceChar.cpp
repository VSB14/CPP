#include <iostream>
#include<string>
using namespace std;
int main(){
    string str = "hello world";
    char ch1 = 'h';
    char ch2 = 'w';


    for (int i = 0; i < str.length()-1; i++)
    {
        if(str[i] == ch1) str[i] = ch2;
        else if(str[i] == ch2) str[i] = ch1;
        
    }
    cout<<"Result: "<<str<<endl;
    return 0;
}