class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> res;
    for (int k = 0, i = 0; k < s.size(); ++k) {
        int h = startPos[1], v = startPos[0];
        for (i = k; i < s.size() && min(h, v) >= 0 && max(h, v) < n; ++i) {
            h += s[i] == 'L' ? -1 : s[i] == 'R' ? 1 : 0;
            v += s[i] == 'U' ? -1 : s[i] == 'D' ? 1 : 0;
        }
        res.push_back(i - k - 1 + (min(h, v) >= 0 && max(h, v) < n));
    }
    return res;
    }
};