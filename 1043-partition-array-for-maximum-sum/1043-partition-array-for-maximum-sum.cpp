class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        for(int i = 1; i<=n; ++i){
            int best = 0;
            for(int j = 1; j<=k; ++j){
                if(i - j < 0)
                    break;
                best = max(best, arr[i-j]);
                dp[i] = max(dp[i], best*j + dp[i-j]);
            }
            
        }
        
        return dp[n];
    }
};