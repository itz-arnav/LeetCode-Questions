class Solution {
public:
    int dp[605][105][105];
    int solve(int i, int sz, int z, int o, int m, int n, vector<vector<int>> &arr){
        if(i >= sz){
            return 0;
        }
        if(dp[i][z][o] != -1)
            return dp[i][z][o];
        
        int notpick = solve(i+1, sz, z, o, m,n, arr);
        int pick = 0;
        int newzero = arr[i][0] + z;
        int newone = arr[i][1] + o;
        if(newzero <= m and newone <= n){
            pick = 1 + solve(i+1, sz, newzero, newone, m,n, arr);
        }
        return dp[i][z][o] = max(pick, notpick);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<int>> arr(size, vector<int> (2,0));
        for(int i = 0; i<size; ++i){
            for(int j = 0; j<strs[i].size(); ++j){
                if(strs[i][j] == '0'){
                    arr[i][0]++;
                }
                else{
                    arr[i][1]++;
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, size, 0, 0, m,n, arr);        
    }
};