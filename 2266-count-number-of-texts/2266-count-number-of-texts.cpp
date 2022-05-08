class Solution {
public:
     int mod = 1000000007;
     int dp[100005];
     int dp2[100005];
    int countTexts(string s) {
        
        dp[0] = 1;
        for(int i = 1; i<= s.size(); i++){
            for(int j = 3; j>0; j--){
                if(i - j >= 0)
                    dp[i] = (dp[i] + dp[i-j])%mod;
            }
        }
        
        dp2[0] = 1;
        for(int i = 1; i<= s.size(); i++){
            for(int j = 4; j>0; j--){
                if(i - j >= 0)
                    dp2[i] = (dp2[i] + dp2[i-j])%mod;
            }
        }
        
        long long count = 1;
        long curr = 1;
        char prev = 'a';
        for(int i = 0; i<s.size(); i++){
            curr = 1;
            prev = s[i];
            if(s[i+1] == prev){
            i++;
            while(i < s.size() and s[i] == prev){
                i++;
                curr++;
            }
            i--;
            }
            if(prev != '7' and prev != '9')
                count = (count*dp[curr])%mod;
            else
                count = (count*dp2[curr])%mod;
            
        }
        return count%mod;
    }
};