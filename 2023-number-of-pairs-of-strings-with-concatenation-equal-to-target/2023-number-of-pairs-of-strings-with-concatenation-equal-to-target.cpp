class Solution {
public:
    int numOfPairs(vector<string>& nums, string t) {
    int pref[101] = {}, suf[101] = {}, res = 0;
    for (auto &n : nums)
        if (n.size() < t.size()) {
            bool isPref = t.compare(0, n.size(), n) == 0;
            bool isSuf = t.compare(t.size() - n.size(), n.size(), n) == 0;
            res += (isPref ? suf[n.size()] : 0) + (isSuf ? pref[t.size() - n.size()] : 0);
            pref[n.size()] += isPref;
            suf[t.size() - n.size()] += isSuf;
        }
    return res;
}
};