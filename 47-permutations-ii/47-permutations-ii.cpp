class Solution {
public:
    void solve(vector<int> curr, int i, int j, vector<vector<int> > &arr) {
        if (i == j-1) {
            arr.push_back(curr);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && curr[i] == curr[k]) continue;
            swap(curr[i], curr[k]);
            solve(curr, i+1, j, arr);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >arr;
        solve(num, 0, num.size(), arr);
        return arr;
    }
};