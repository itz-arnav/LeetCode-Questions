
    int c[1001][1001] = {}, n = 1;
class Solution {
public:
int triangularSum(vector<int>& nums) {
    for (; n <= nums.size(); ++n) // compute once for all test cases.
        for (int r = 0; r < n; ++r) 
            c[n][r] = r == 0 ? 1 : (c[n - 1][r - 1] + c[n - 1][r]) % 10;
    return inner_product(begin(nums), end(nums), begin(c[nums.size()]), 0) % 10;
}
};
