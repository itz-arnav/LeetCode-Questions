class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        vector<vector<int>> dp(2001, vector<int> (2001, 0));
        int best = 0;
        
        for(int i = 0; i<nums.size(); ++i){
            for(int j = i+1; j<nums.size(); ++j){
                int diff = nums[j] - nums[i] + 1000;
                dp[j][diff] = max(2, dp[i][diff] + 1);
                best = max(best, dp[j][diff]);
            }
        }
        return  best;
    }
};