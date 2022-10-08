class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        for(int i = 0, j = n, k = 0; i<n; ++i, ++j){
            ans[k++] = nums[i];
            ans[k++] = nums[j];
        }
        return ans;
    }
};