#include <iostream>
#include<string>
using namespace std;
int main(){
    string str[2] = {"listen", "silent"};
    vector<char> freqArr(0,26);
    vector<char>::iterator it = freqArr.begin();
    string s1= str[0];
    string s2= str[1];
    // cout<<str[0].length();
    if(str[0].length() == str[1].length()){
        return -1;
    }else{
        //frequency array of size 26 characters
        //save by doing str[i]-'a'

        for (int i = 0; i < str[0].length()-1; i++)
        {
            int n = s1[i]-'a';
            freqArr[n] += 1;
        }
        for (int i = 0; i < str[0].length()-1; i++)
        {
            int n = s2[i]-'a';
            freqArr[n] += 1;
        }

        

    }
    return 0;
}