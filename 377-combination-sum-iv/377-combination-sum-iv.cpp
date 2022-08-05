class Solution {
public:
    int combinationSum4(vector<int>& arr, int target) {
        int n = arr.size();
        vector<double>dp(target+5,0);
        sort(arr.begin(), arr.end());
        dp[0] = 1;
        for(int j = 1; j<=target; ++j){ 
            for(int i = 1; i<=n; ++i){
                if(j - arr[i-1] < 0)
                    break;
                dp[j] += dp[j- arr[i-1]];
            }  
        }
         return dp[target];
    }
};