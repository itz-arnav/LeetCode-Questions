class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dp(n+1, 10006);
        dp[k] = 0;
        for(int i=0;i<n-1;i++) {
           for(int i=0;i<times.size();i++) {
            if(dp[times[i][0]] + times[i][2] < dp[times[i][1]] )
                dp[times[i][1]] = dp[times[i][0]] + times[i][2];
            } 
        }
        int mx = 0;
        for(int i=1;i<=n;i++) {
            mx = max(mx, dp[i]);
        }
        return mx == 10006 ? -1 : mx;
    }
};