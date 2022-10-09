class Solution {
public:
    int mod = 1000000007;
    int m,n;
    vector<vector<vector<int>>>  dp;
    long long solve(int r,int c,vector<vector<int>>& grid, int k,long long sum){
        if(r<0 || r>=m || c<0 || c>=n)return 0;
        if(r==m-1 && c==n-1){
            sum+=grid[r][c];
            if(sum%k==0)return 1;
            return 0;
        }
        if(dp[r][c][sum%k]!=-1)return dp[r][c][sum%k];
        long long  x=0,y=0;
        x=solve(r+1,c,grid,k,sum+grid[r][c])%mod;
        y=solve(r,c+1,grid,k,sum+grid[r][c])%mod;
        return dp[r][c][sum%k]=(x+y)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        dp.resize(m+1, vector<vector<int>>(n+1, vector<int>(k, -1)));
        return solve(0,0,grid,k,0)%mod;
    }
};