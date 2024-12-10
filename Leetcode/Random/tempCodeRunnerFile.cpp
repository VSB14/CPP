#include <bits/stdc++.h>
using namespace std;

 //using arr apporach
 //Steps
 //step1: two input arrays arr1(release times) and arr2 (keyspressed)
 //step2: Int arr3(duration), arr3[i] = arr1[i] - arr[i-1]
 //step3: find largest and second largest in arr3. sort arr3(cannot be done coz order of elements would get disturbed)
 //step4: if(largest != second largest) then return arr2[arr3[largest]] else check lexicographically which is shortest. i.e print min(arr2[arr3])

 //GPT approach
 //string vector initialization, pass by reference of releasetimes, stringkeysPressed

//Define a struct or use a pair to store key and duration
struct KeyDuration {
    char key;
    int duration;
};

 KeyDuration slowestKey(vector<int>& releaseTimes, string keysPressed){
    const int n = releaseTimes.size();
    vector<int> keyDuration(26,0);
    char maxkey = keysPressed[0];
    int maxDuration = releaseTimes[0];
    
    for (int i = 1; i < n; i++)
    {
        char key = keysPressed[i]  ;
        int duration = releaseTimes[i]- releaseTimes[i-1];
        keyDuration[key- 'a'] = max(keyDuration[key-'a'], duration);

        if( keyDuration[key-'a']> maxDuration || keyDuration[key-'a'] == maxDuration && key>maxkey){
            maxkey = key;
            maxDuration = keyDuration[key-'a'] ;
        }
    }
    return {maxkey, maxDuration};
 }

 int main(){
    vector<int> releaseTimes= {9,29,49,50};
    string keysPressed = "cbcd";
    KeyDuration result = slowestKey(releaseTimes, keysPressed);
    cout<< "Slowest Key: " <<result.key<< ", Duration: "<< result.duration<< "units."<<endl;
    return 0;
 }