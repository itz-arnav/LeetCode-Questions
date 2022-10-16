class Solution {
public:
    int minDifficulty(vector<int>& arr, int d) {
        
        int n = arr.size();
        if(d > n)
            return -1;
        
        vector<vector<long long>> dp(d+10, vector<long long> (n+10, 1e7));
        dp[0][0] = 0;
        for(int i = 1; i<=d; ++i){
            dp[i][i] = arr[i-1] + dp[i-1][i-1];
        }
        for(int i = 1; i<=d; ++i){
            for(int j = 1; j<=n; j++){
                dp[i][j] =dp[i][j-1];
                if(j > 1 and arr[j-1] > arr[j-2]){
                    dp[i][j] += arr[j-1] - arr[j-2];
                }
                int minn = arr[j-1];
                for(int k = j-1; k>=0; k--){
                    
                    dp[i][j] = min(dp[i][j], minn + dp[i-1][k]);
                    if(k > 0)
                    minn = max(arr[k-1], minn);
                }
            }
        }
        // for(int i = 0; i<=d; ++i){
        //     for(int j = 0; j<=n; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[d][n];
    }
};