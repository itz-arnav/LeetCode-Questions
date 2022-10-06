class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1, 0);
        int best = 1;
        for(int i = 0; i<n; ++i){
            dp[i] = 1;
            for(int j = 0; j<i; ++j){
                if(arr[i] > arr[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                    best = max(best, dp[i]);
                }
            }
        }
        return best;
    }
};