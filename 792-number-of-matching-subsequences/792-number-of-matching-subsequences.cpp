class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int> cmap[26];
        for (int i = 0; i < S.length(); i++) {
            cmap[S[i]-'a'].push_back(i);
        }
        int res = 0;
        for (auto& word : words) {
            int i = 0, n = word.length(), j = -1;
            while (i < n) {
                int c = word[i]-'a';
                if (cmap[c].empty()) break;
                auto it = upper_bound(begin(cmap[c]), end(cmap[c]), j);
                if (it == cmap[c].end()) break;
                j = *it;
                i++;
            }
            res += (i == n);
        }
        return res;
    }
};