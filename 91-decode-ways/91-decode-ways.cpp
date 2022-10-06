class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+5, 0);
        dp[0] = 1;
        for(int i = 0; i<n; ++i){
            if(s[i] == '0'){
                if(i > 0 and (s[i-1] == '1' or s[i-1] == '2')){
                    dp[i+1] = dp[i-1];
                }
                else{
                    dp[i+1] = 0;
                }
            }
            else{
                dp[i+1] += dp[i];
                if(i > 0 and (s[i-1] == '1')){
                    dp[i+1] += dp[i-1];
                }
                else if(i > 0 and s[i-1] == '2' and s[i] <= '6'){
                    dp[i+1] += dp[i-1];
                }
            }
        }
        return dp[n];
    }
};