class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp( m+1 , vector<long long>(n+1,0));
        dp[m][n] = 1;
        for(int i = m; i>=1; i--){
            for(int j = n; j>=1; j--){
                if(i == m && j == n)
                    continue;
                if(obstacleGrid[i-1][j-1] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(j!=n)
                    dp[i][j] += dp[i][j+1];
                if(i!=m)
                    dp[i][j] += dp[i+1][j];    
            }
        }
        if(obstacleGrid[m-1][n-1] != 1)
        return dp[1][1];
        else
            return 0;
    }
};