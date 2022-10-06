class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e8);
        dp[0] = 0;
        for(int i = 0; i<= amount; ++i){
            for(int j = 0; j<coins.size(); ++j){
                if(i < coins[j])
                    continue;
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        return dp[amount] >= 1e8? -1: dp[amount];
    }
};