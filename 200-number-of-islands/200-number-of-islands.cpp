class Solution {
public:
        void solve(int i, int j, int n, int m, vector<vector<char>>& arr){
        if(i < 0 or i >= n or j < 0 or j >= m or arr[i][j]=='0')
            return;
        
        arr[i][j] = '0';
        solve(i+1, j, n, m, arr);
        solve(i-1, j ,n ,m ,arr);
        solve(i, j+1, n ,m, arr);
        solve(i, j-1, n, m, arr);
    }
    int numIslands(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        int ct = 0;
        for(int i = 0; i<n; i++){
            for(int j= 0; j<m; j++){
                if(arr[i][j] == '1'){
                    ct++;
                    solve(i, j, n, m, arr);
                }
            }
        }
        return ct;
    }
    
};