class Solution {
public:
    int countBalls(int l, int h) {
        unordered_map<int,int> mp;
        int best = 0;
        vector<int> dp(h + 5, 0);
        for(int i = 1; i<=h; ++i){
            dp[i] = i%10 + dp[i/10];
        }
        for(int i = l; i<=h; ++i){
            mp[dp[i]]++;
            best = max(best, mp[dp[i]]);
        }
        return best;
        
    }
};