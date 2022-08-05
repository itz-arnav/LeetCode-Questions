class Solution {
public:
    int mod = 1e9 + 7;

int solve(int i, int a, int j, int b, string &t, string &s, vector<vector<int>> &dp){
    if(j == b){
        return 1;
    }
    if(i == a){
        return 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int first = 0, second = 0;
    if(t[i] == s[j]){
        first = solve(i+1, a, j+1, b, t,s,dp);
    }
    second = solve(i+1, a, j, b, t,s,dp);
    return dp[i][j] =  (first + second)%mod;
}

int subsequenceCounting(string &t, string &s, int a, int b) {
    vector<vector<double>> dp(a+5, vector<double>(b+5,0));
    for(int j = 1; j<=b; ++j){
        dp[0][j] = 0;
    }
    for(int i = 0; i<=a; ++i){
        dp[i][0] = 1;
    }
    for(int i = 1; i<=a; ++i){
        for(int j = 1; j<=b; ++j){
            if(t[i-1] == s[j-1]){
                dp[i][j] += dp[i-1][j-1];
            }
            dp[i][j] +=dp[i-1][j];
        }
    }
    return dp[a][b];
} 
    int numDistinct(string s, string t) {
        return subsequenceCounting(s, t, s.size(), t.size());
    }
};