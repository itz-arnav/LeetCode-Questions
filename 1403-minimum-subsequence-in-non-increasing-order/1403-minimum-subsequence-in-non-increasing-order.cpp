class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(auto x : nums)
            ans+=x;
        
        int cs = 0;
        for(int i = nums.size()-1; i>=0; --i){
            cs += nums[i];
            ans -= nums[i];
            v.push_back(nums[i]);
            if(cs > ans){
                return v;
            }
        }
        return v;
    }
};