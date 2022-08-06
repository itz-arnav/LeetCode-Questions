class Solution {
public:
    
int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp){
    if(j < 0){
        return i+1;
    }
    if(i < 0){
        return j+1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int ans = 1e7;
    if(a[i] == b[j])
        return dp[i][j] = solve(i-1, j-1, a,b,dp);
    //insert
    ans = min(ans, 1+solve(i, j-1,a,b,dp));
    //delete
    ans = min(ans, 1+solve(i-1, j, a,b,dp));
    //replace
    ans = min(ans, 1+solve(i-1,j-1, a,b,dp));
    return dp[i][j] = ans;
    
}

int editDistance(string &a, string &b)
{
    int n = a.size();
    int m = b.size();

    
//     vector<vector<int>> dp(n+15, vector<int>(m+15, 1e7));
    vector<int> prev(m+15, 0), curr(m+15,0);   
    for(int j = 0; j<=m; ++j){
        prev[j] = j;
    }
    for(int i = 1; i<=n; ++i){
        curr[0] = i;
        for(int j = 1; j<=m; ++j){
            if(a[i-1] == b[j-1]){
                curr[j] = prev[j-1];
            }
            else{
                //delete
                curr[j] = 1 + prev[j];
                //replace
                curr[j] = min(curr[j], 1 + prev[j-1]);
                //insert
                curr[j] = min(curr[j], 1 + curr[j-1]);
            }
        }
        prev = curr;
    }
    return prev[m];
    
}
    int minDistance(string word1, string word2) {
        return editDistance(word1, word2);
    }
};