class Solution {
public:
    int f(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp,int m,int n){
      //  if(i<0 || j<0 || i>=m || j>=n) return -1;
        if(mat[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int  p1=INT_MAX-2,p2=INT_MAX-2;
        if(i+1<m) p1=1+f(i+1,j,mat,dp,m,n);
        if(j+1<n) p2=1+f(i,j+1,mat,dp,m,n);
       // int p3=min(dp[i-1][j],dp[i][j-1]);
        if(min(p1,p2)==INT_MAX) return dp[i][j]=INT_MAX-1;
        return dp[i][j]=min(p1,p2);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dp[i][j]=0;
                  //  cout<<dp[i][j]<<" ";
                    continue;
                }
                if(dp[i][j]==-1)
                dp[i][j]=f(i,j,mat,dp,m,n);
                if(i-1>=0) dp[i][j]=min(1+dp[i-1][j],dp[i][j]);
                if(j-1>=0) dp[i][j]=min(1+dp[i][j-1],dp[i][j]);
                // dp[i][j]=min(dp[i][j],v);
            }
        }
        return dp;
    }
};