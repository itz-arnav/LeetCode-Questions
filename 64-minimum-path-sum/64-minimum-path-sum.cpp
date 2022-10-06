class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 1e9));
        
        for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=m; ++j){
                if(i == 1 and j == 1)
                    dp[i][j] = arr[i-1][j-1];
                else
                dp[i][j] = arr[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};