class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int res = 0;
    unordered_map<int, int> gcds;
    for (int i = 0; i < nums.size(); ++i) {
        unordered_map<int, int> gcds1;
        if (nums[i] % k == 0) {
            ++gcds[nums[i]];
            for (auto [prev_gcd, cnt] : gcds)
                gcds1[gcd(prev_gcd, nums[i])] += cnt;
        }
        res += gcds1[k];
        swap(gcds, gcds1);
    }
    return res;
    }
};