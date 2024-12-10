#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        for (int i = 0; i < nums2.size(); i++)
        {
            for (int j = i+1; j < nums2.size(); j++)
            {
                if(nums2[i]< nums2[j]){
                    mpp[nums2[i]] = nums2[j];
                    break;
                }
                
            }
            
        }
        vector<int> res;
        for(auto it: nums1){
            if(mpp.find(it) != mpp.end()){
                res.push_back(mpp[it]);
            }else res.push_back(-1);
        }
        return res;
        
    }

int main(){
    vector<int> nums1 = {2,4};
    vector<int> nums2 = {1,2,3,4};
    vector<int> res = nextGreaterElement(nums1, nums2);
    for(auto it: res){
        cout<<it<<" ";
    }
    return 0;
}
