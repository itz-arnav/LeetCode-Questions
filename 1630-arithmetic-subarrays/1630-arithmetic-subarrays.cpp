class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> res;
    for (auto i = 0, j = 0; i < l.size(); ++i) {
        auto [p_min, p_max] = minmax_element(begin(nums) + l[i], begin(nums) + r[i] + 1);
        int len = r[i] - l[i] + 1, d = (*p_max - *p_min) / (len - 1);
        if (*p_max == *p_min)
             res.push_back(true);
        else if ((*p_max - *p_min) % (len - 1))
             res.push_back(false);
        else {
            vector<bool> n(len);
            for (j = l[i]; j <= r[i]; ++j) {
                if ((nums[j] - *p_min) % d || n[(nums[j] - *p_min) / d])
                    break;
                n[(nums[j] - *p_min) / d] = true;
            }
            res.push_back(j > r[i]);
        }
    }
    return res;
}
};