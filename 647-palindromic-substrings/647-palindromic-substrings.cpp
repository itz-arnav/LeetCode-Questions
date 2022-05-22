class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        for(int g = 0; g<n; g++){
            for(int i = 0, j = g; j<n; i++,j++){
                if(g == 0){
                    dp[i][j] = true;
                }
                else if(g == 1){
                    dp[i][j] = (s[i] == s[j] ? true : false);
                }
                else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1]; 
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(dp[i][j])
                    count++;
            }
        }
        return count;
        
    }
};