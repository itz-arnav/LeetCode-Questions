class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& A, vector<int>& P, vector<int>& start, int k) {
        int M = A.size(), N = A[0].size(), step = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<pair<int, int>> q{{{start[0], start[1]}}};
        vector<vector<int>> ans;
        vector<vector<bool>> seen(M, vector<bool>(N));
        seen[start[0]][start[1]] = true;
        while (q.size() && ans.size() < k) {
            int cnt = q.size();
            vector<vector<int>> tmp;
            while (cnt--) {
                auto [x, y] = q.front();
                q.pop();
                if (A[x][y] >= P[0] && A[x][y] <= P[1]) tmp.push_back({A[x][y], x, y});
                for (auto &[dx, dy] : dirs) {
                    int a = x + dx, b = y + dy;
                    if (a < 0 || b < 0 || a >= M || b >= N || A[a][b] == 0 || seen[a][b]) continue;
                    seen[a][b] = true;
                    q.emplace(a, b);
                }
            }
            sort(begin(tmp), end(tmp));
            ++step;
            for (auto c : tmp) {
                ans.push_back({c[1], c[2]});
                if (ans.size() == k) break;
            }
        }
        return ans;
    }
};