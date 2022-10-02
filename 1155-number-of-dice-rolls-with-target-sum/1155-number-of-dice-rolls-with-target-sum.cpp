class Solution {
public:
    int mod = 1000000007;
    long solve(int n, int k, int target, vector<vector<int>> &dp){
        if(target == 0 and n == 0)
            return 1;
        
        if(n == 0 and target > 0)
            return 0;
        
        if(target == 0 and n > 0)
            return 0;
        
        
        if(dp[n][target] != -1)
            return dp[n][target];
        
        long ans = 0;
        for(int i = 1; i<=min(k, target); ++i){
            ans = (ans + solve(n-1, k, target-i, dp))%mod;
        }
        
        return dp[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(100, vector<int>(1008, -1));
        int ans = solve(n, k, target, dp);
        return ans;
    }
};