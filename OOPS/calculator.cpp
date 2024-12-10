#include<iostream>
using namespace std;

class calculator{
    private:
    int sum(int a, int b){
        int ans = a + b;
        return ans;
    }
    int subtract(int a, int b){
        int ans = a - b;
        return ans;
    }
    int multiple(int a, int b){
        int ans = a * b;
        return ans;
    }
    int divide(int a, int b){
        int ans = a / b;
        return ans;
    }
};

int main(){
    return 0;
}