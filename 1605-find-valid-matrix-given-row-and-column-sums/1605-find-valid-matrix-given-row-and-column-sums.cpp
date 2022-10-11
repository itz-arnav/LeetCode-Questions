class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        int m = row.size(), n = col.size(), i = 0, j = 0, a;
        vector<vector<int>> A(m, vector<int>(n, 0));
        while (i < m && j < n) {
            a = A[i][j] = min(row[i], col[j]);
            if ((row[i] -= a) == 0) ++i;
            if ((col[j] -= a) == 0) ++j;
        }
        return A;
    }
};