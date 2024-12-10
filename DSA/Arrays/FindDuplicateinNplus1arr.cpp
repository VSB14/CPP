#include <iostream>
#include <vector>
using namespace std;


    int findDuplicate(int (&nums)[5], int size)
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
 int main(){
    int arr[5] = {1,3, 4, 2, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int res  = findDuplicate(arr,size );
    cout<<"Res: "<<res<<endl;
    for (int i = 0; i < size; i++)
    {
       cout<< arr[i]<<endl;
    }
    
    return  0; 
 }
