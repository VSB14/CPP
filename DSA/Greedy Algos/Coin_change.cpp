class Solution {

  public:
  static bool comp(int a, int b){
      return a>b;
  }
    int minCoins(vector<int> &coins, int sum) {
        // sort in decending order
        if(sum == 0) return 0;
        int res = 0;
        int diff =0;
        sort(coins.begin(),coins.end(), comp);
        //find difference with the first element and if the difference can be cut down more via adding the multiple of the current element then do so
        for(int i = 0;i<coins.size();i++){
            if(sum%coins[i] == 0) return res+ sum/coins[i];
            while(abs(sum-coins[i])< sum && coins[i]<= sum){
                res++;
                sum = sum - coins[i];
                if(sum == 0) return res;
            }
              
        }
        return -1;
    }
};