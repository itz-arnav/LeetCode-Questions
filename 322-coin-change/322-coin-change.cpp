class Solution {
public:
    int dp[100001];
    int recursion(int amount,vector<int>&coins)
    {
        if(amount<0)    return INT_MAX;
        if(amount==0)   return 0;
        if(dp[amount]!=-1)
            return dp[amount];
        int ans=INT_MAX-1;
        for(int i=0;i<coins.size();i++)
        {
            ans=min(ans,recursion(amount-coins[i],coins));
        }
        dp[amount]=ans+1;
        return ans+1;
    }
    int coinChange(vector<int>& coins, int amount) {
        for(int i=0;i<100001;i++)   dp[i]=-1;
       int ans=recursion(amount,coins); 
        if(ans>=INT_MAX)
            return -1;
        return ans;
    }
};