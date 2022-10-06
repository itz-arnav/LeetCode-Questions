class Solution {
public:
    unordered_map<int,bool> dp;
    bool solve(int sum, int val, int state){
        if(dp.find(state) != dp.end())
            return dp[state];
        
        for(int i = 1; i<=val; ++i){
            if((1<<i) & state)
                continue;
            if(sum <= i or !solve(sum-i, val, state | (1<<i))){
                return dp[state] = true;
            }
        }
        return dp[state] = false;
    }
    bool canIWin(int val, int desiredTotal) {
        if(val*(val+1)/2 < desiredTotal)
            return false;
        return solve(desiredTotal, val, 0);
    }
};