class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(6, vector<int> (n+4, 0));
        for(int i = 0; i<5; i++)
            dp[i][1] = 1;
        for(int i = 2; i<=n; i++){
            for(int j = 0; j<5; j++){
                for(int k = 0; k<=j; k++){
                    dp[j][i] += dp[k][i-1];
                }
            }
        }
        return dp[0][n] + dp[1][n] + dp[2][n] + dp[3][n] + dp[4][n];
    }
};