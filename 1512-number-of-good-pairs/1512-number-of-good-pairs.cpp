class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int ct = 0;
        for(auto & x : nums){
            if(mp[x]){
                ct += mp[x];
            }
            mp[x]++;
        }
        return ct;
    }
};