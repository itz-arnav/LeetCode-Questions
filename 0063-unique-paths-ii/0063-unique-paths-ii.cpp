class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
         int m=  obstacleGrid.size(); // row
        int n = obstacleGrid[0].size();     // column
         vector<vector<int>> dp(m , vector<int> (n,-1));   // declareing dp array
        
        return memoization(m-1,n-1,dp,obstacleGrid);
        
        
        
    }
    
    int memoization(int i , int j , vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid){
        
        if(i==0 && j==0 && obstacleGrid[i][j]!=1) return 1;   // is wale case k liye [[1]]
        
        if(i<0||j<0) return 0; // out of matrix 
        
        if(i>=0 && j >=0&& obstacleGrid[i][j]==1) return 0;  
        if(dp[i][j]!=-1)  return dp[i][j];
        
        int up = memoization(i-1,j, dp,obstacleGrid);   // if go down in reverse manner
        int left = memoization(i,j-1,dp,obstacleGrid);  // if go right in reverse manner
         
        return dp[i][j] = (up+left);
     
    }
};