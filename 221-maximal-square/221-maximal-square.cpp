class Solution {
public:
    int maximalSquare(vector<vector<char>>& arr) {
        int best = 0;
        int n=  arr.size(), m = arr[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i = 0;i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(arr[i][j] == '1'){
                    dp[i+1][j+1] = 1;
                    dp[i+1][j+1] += min({dp[i][j], dp[i+1][j], dp[i][j+1]});
                    best = max(best, dp[i+1][j+1]);
                }
            }
        }
        
        
        return best*best;
    }
};