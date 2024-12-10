#include <iostream>
using namespace std;

int slidingWindow(int arr[], int n, int k){
    //for the first window
    int current_sum = arr[0];
    for (int i = 0; i < k; i++)
    {
        current_sum += arr[i];
    }
    int max_sum = current_sum;
    for (int i = k; i < n ; i++)
    {
        current_sum += arr[i]-arr[i-k];
        max_sum = current_sum;
    }
    return max_sum;
    
    
}


int main(){
    int arr[] = {1,8,30,-5,20,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k =3;
    int result= slidingWindow(arr, size, k);
    printf("Resultant for max sum of %d consecutive numbers is: %d\n", k, result);

}