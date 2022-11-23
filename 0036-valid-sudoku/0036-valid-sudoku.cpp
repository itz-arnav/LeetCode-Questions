class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        unordered_map<int, unordered_set<char>> row, col, grid;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == '.')
                continue;
                int val = (i/3)*3 + j/3;
                int t = mat[i][j];
                if(grid[val].count(t))
                return false;
                if(row[i].count(t))
                return false;
                if(col[j].count(t))
                return false;
                grid[val].insert(t);
                row[i].insert(t);
                col[j].insert(t);
            }
        }
        return true;
    }
};