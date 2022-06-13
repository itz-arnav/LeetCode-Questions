class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int n = arr.size();
        
        for(int i = 1; i<n; i++){
            int m = arr[i-1].size();
            for(int j = 1; j<m; j++){
                arr[i][j] += min(arr[i-1][j], arr[i-1][j-1]);
            }
            arr[i][m] += arr[i-1][m-1];
            arr[i][0] += arr[i-1][0];
        }
        
        
        
        
        
        int minn = arr[n-1][0];
        
        for(int i = 1; i<arr[n-1].size(); i++){
            minn = min(minn, arr[n-1][i]);
        }
        return minn;
    }
};