class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0; i<nums.size(); ++i){
            ans += mp[nums[i] - k];
            ans += mp[nums[i] + k];
            mp[nums[i]]++;
        }
        return ans;
    }
};