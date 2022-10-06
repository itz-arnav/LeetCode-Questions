class Solution {
public:
    bool solve(int curr, int n, string &s, vector<string>& arr, vector<int> &dp){
        if(curr == n)
            return true;
        if(curr > n){
            return false;
        }
        if(dp[curr] != -1)
            return dp[curr];
        
        for(int i = 0; i<arr.size(); ++i){
            if(arr[i].size() + curr > n)
                continue;
            bool flag = true;
            for(int j = 0; j<arr[i].size(); ++j){
                if(arr[i][j] != s[curr + j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                bool ans = solve(curr + arr[i].size(), n, s, arr, dp);
                if(ans)
                    return dp[curr] = true;
            }
        }
        return dp[curr] = false;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+5, -1);
        return solve(0, s.size(), s, wordDict, dp);
    }
};