class Solution {
public:
    // int f(int i,vector<int> &v,vector<vector<int>> &dp,int prev,int n){
    //     if(i>=n) return 0;
    //     if(dp[i][prev]!=-1) return dp[i][prev];
    //     int npick=f(i+1,v,dp,prev,n);
    //     int pick=0;
    //     if(prev==0) 
    //         pick=1 + f(i+1,v,dp,i+1,n);
    //     else if(v[i]>v[prev-1])
    //         pick=1 + f(i+1,v,dp,i+1,n);
    //     return dp[i][prev]=max(pick,npick);
    // }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> t(n+10, vector<int>(n+10,0));
        for(int i =0; i< n+1; i++)
        {
            for(int j =0; j<n+1; j++)
            {
                if(i == 0)
                {
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i =1; i< n+1; i++)
        {
            for(int j =1; j<n+1; j++)
            {
                if(j == n || arr[i-1] < arr[j])
                {
                    t[i][j] = max(t[i-1][j], t[i-1][i-1]+1);
                }
                else
                    t[i][j] = t[i-1][j];
                
            }
        }
        
        return t[n][n];
    }
    
};