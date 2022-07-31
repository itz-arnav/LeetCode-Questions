class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<int> row(n, 0), col(m, 0);
        for(auto &x : indices){
            row[x[0]]++;
            col[x[1]]++;
        }
        int no_of_odd_col = 0;
        for(int i = 0; i<m; ++i){
            no_of_odd_col += (col[i]&1);
        }
        int ans = 0;
        for(int i = 0; i<n; ++i){
            if(row[i]&1)
                ans += (m - no_of_odd_col);
            else
                ans += no_of_odd_col;
        }
        return ans;
    }
};