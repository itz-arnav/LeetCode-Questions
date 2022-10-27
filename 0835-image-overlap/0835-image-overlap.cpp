class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> va, vb;
        int rows = A.size(), cols = A[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (A[i][j]) va.push_back({i, j});
                if (B[i][j]) vb.push_back({i, j});
            }
        }
        unordered_map<string, int> mp;
        for (auto &pa : va) {
            for (auto &pb : vb) {
                string s = to_string(pa[0] - pb[0]) + " " + to_string(pa[1] - pb[1]);
                mp[s]++;
            }
        }
        int res = 0;
        for (auto &it : mp) res = max(res, it.second);
        return res;
    }
};