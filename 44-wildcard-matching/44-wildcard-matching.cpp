class Solution {
public:
    bool solve(int i, int j, string &a, string &b, vector<vector<int>> &dp){

    if(j == 0 and i == 0)
        return true;
    if(j == 0){
        int p = i;
        while(i > 0){
            if(a[i-1] == '*'){
                i--;
            }
            else{
                return dp[p][j] = false;
            }
        }
        return dp[p][j] = true;
    }
    if(i == 0 and j > 0)
        return false;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(a[i-1] == b[j-1] or a[i-1] == '?'){
        return dp[i][j] = solve(i-1, j-1, a,b,dp);
    }
    if(a[i-1] == '*'){
        return dp[i][j] = solve(i-1, j-1, a,b,dp) or solve(i,j-1, a,b,dp) or solve(i-1,j,a,b,dp);
    }
    else
        return dp[i][j] = false;
}
    bool isMatch(string b, string a) {
        vector<vector<int>> dp(a.size()+10, vector<int>(b.size()+10, -1));
   return solve(a.size(), b.size(), a, b,dp);
    }
};