class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& arr){
        if(i < 0 or j < 0 or i>= n or j>=m or arr[i][j] == '.'){
            return;
        }
        arr[i][j] = '.';
        dfs(i+1,j,n,m,arr);
        dfs(i-1,j,n,m,arr);
        dfs(i,j+1,n,m,arr);
        dfs(i,j-1,n,m,arr);
    }
    int countBattleships(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int count = 0;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(arr[i][j] == 'X'){
                    count++;
                    dfs(i,j,n,m,arr);
                }
            }
        }
        return count;
    }
};