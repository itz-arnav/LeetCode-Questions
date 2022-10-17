class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int b) {
        int n = nums.size();
        vector<int> ans(n);
        int x = 0;
        for(int i = 0; i<n; ++i){
            x ^= nums[i];
        }
        for(int i = n-1; i>=0; --i){
            int k = 0;
            for(int j = 0; j<b; ++j){
                int curr = 1<<j;
                if((curr & x) == 0){
                    k |= curr;
                }
            }
            ans[n-1-i] = k;
            x ^= nums[i];
        }
        return ans;
    }
};