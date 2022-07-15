class Solution {
public:
    int ans = 0;
    int solve(int i, int j, vector<vector<int>>& grid){
        if( i < 0 or i >= grid.size() or j < 0 or j >= grid[0].size() or grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        int up = solve(i-1, j, grid);
        int down = solve(i+1, j, grid);
        int left = solve(i, j-1, grid);
        int right = solve(i, j+1, grid);
        ans = max(ans,  1 + up + down + left + right);
        return 1 + up + down + left + right;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                solve(i, j, grid);
            }
        }
        return ans;
    }
};