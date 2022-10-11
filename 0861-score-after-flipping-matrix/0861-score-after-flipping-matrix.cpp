class Solution {
public:
    int matrixScore(vector<vector<int>>& arr) {
        int n=  arr.size();
        int m = arr[0].size();
        for(int i = 0; i<n; ++i){
            if(arr[i][0] == 1)
                continue;
                for(int j = 0; j<m; ++j){
                    arr[i][j] = 1-arr[i][j];
                }
        }
        
        for(int j = 1; j<m; ++j){
            int ct = 0;
            for(int i = 0; i<n; ++i){
                ct += arr[i][j];
            }
            if(2*ct < n){
                for(int i = 0; i<n; ++i){
                    arr[i][j] = 1-arr[i][j];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n; ++i){
            int val = 1;
            for(int j = m-1; j>=0; --j){
                ans += arr[i][j]*val;
                val<<=1;
            }
        }
        return ans;
    }
};